//Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include <RTClib.h>

//serial peripheral interface and library for SD card reader
#include <SPI.h> //serial peripheral interface for SD card reader
#include <SD.h> //library for SD card reader

//communication protocols for temperature sensors
#include <Adafruit_MAX31865.h>

//Software libary for the pressure sensor
#include <MS5803_14.h>

//EC Circuit uses software serial
#include <SoftwareSerial.h>

//Set conditions for RTC
RTC_DS3231 rtc; //define real-time clock

//set conditions for SD card reader
const int chipSelect = 4; //sets chip select pin for SD card reader
char datalogFileName[12];

/* This integer specifies how high accuracy you want your pressure sensor to be (oversampling resolution).
   Ok values: 256, 512, 1024, 2048, or 4096 (Higher = more accuracy but slower sampling frequency**)
 * ** There is no reason not to use the highest accuracy. This is because the datalogging rate is set by the
   sampling/response frequency of the ec sensor [default = 1 sec] (this is to avoid the case where both sensors send data at the same time). */

#define PRESSURE_SENSOR_RESOLUTION 4096
MS_5803 sensor = MS_5803(PRESSURE_SENSOR_RESOLUTION); // Define pressure sensor.

//Set conditions for PT100/PT1000 temperature probe
Adafruit_MAX31865 thermo = Adafruit_MAX31865(6, 9, 10, 11); //SPI: CS, DI, DO, CLK
#define RREF      4300.0 // The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RNOMINAL  1000.0 // The 'nominal' 0-degrees-C resistance of the sensor, 100.0 for PT100, 1000.0 for PT1000

//Declare global variables for PT100/1000 temperature
float tempPT;

SoftwareSerial ecSerial(12, 13); // Define the SoftwareSerial port for conductivity.

double pressure_abs; //define absolute pressure variable

//Declare global variables for eletrical conductivity
float EC_float = 0;
char EC_data[48]; // A 48 byte character array to hold incoming data from the conductivity circuit.
char *EC; // Character pointer for string parsing.
byte received_from_sensor = 0; // How many characters have been received.
byte string_received = 0; // Whether it received a string from the EC circuit.

#define EC_SAMPLING_FREQUENCY 1 // Set the requested sampling frequency of the conductivity probe in seconds (NO Decimals) (this by extension sets the overall frequency of logging).
#define EC_LED 1 // Set the LED on the EZO EC Chip. 1 to turn on, 0 to turn off to preserve power

void setup () {

// comment the following three lines out for final deployment
//#ifndef ESP8266
// while (!Serial && millis() < 20000); //for Leonardo/Micro/Zero - Wait for a computer to connect via serial or until a 20 second timeout has elapsed (This works because millis() starts counting the mlliseconds since the board turns on)
//#endif

  Serial.begin(9600);

  //Initialize SD card reader
  Serial.print("Initializing SD card...");

  while (!SD.begin(chipSelect)) {

    Serial.println("Card failed, or not present");
    delay(1000);

  }

  // This funny function allows the sd-library to set the correct file created & modified dates for all sd card files.
  // (See the SDCardDateTimeCallback function defined at the end of this file)
  SdFile::dateTimeCallback(SDCardDateTimeCallback);

  Serial.println("card initialized.");

  delay(1000);

  if (! rtc.begin()) {

    Serial.println("Couldn't find RTC");
    while (1);

  }

  get_numbered_filename(datalogFileName, "CAST", "CSV");

  Serial.print("Writing to datalog: ");
  Serial.println(datalogFileName);

  File dataFile = SD.open(datalogFileName, FILE_WRITE);

  if (dataFile) {
    Serial.println("====================================================");
    Serial.println("Date, Time,Pressure, Temperature, Conductivity");
    dataFile.println("Date, Time, Pressure, Temp, Conductivity");
    dataFile.close();

  } else {
    Serial.println("Err: Can't open datalog!");
  }

  //Initialize real-time clock
  if (rtc.lostPower()) {

    //reset RTC with time when code was compiled if RTC loses power
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  }

  delay(250);   // Wait a quarter second to continue.

  //Initialize sensors
  Serial.println("-- Pressure Sensor Info: --");
  sensor.initializeMS_5803(); // Initialize pressure sensor
  Serial.println("---------------------------");
  
  //Initialize Temperature Sensor
  thermo.begin(MAX31865_3WIRE);  // set to 2WIRE or 4WIRE as necessary

  ecSerial.begin(9600); // Set baud rate for conductivity circuit.

  do {

    ecSerial.write('i');  // Tell electrical conductivity board to reply with the board information by sending the 'i' character ...
    ecSerial.write('\r'); // ... Finish the command with the charage return character.

    received_from_sensor = ecSerial.readBytesUntil('\r', EC_data, 30); // Wait for the ec circut to send the data before moving on...
    EC_data[received_from_sensor] = 0; // Null terminate the data by setting the value after the final character to 0.

  } while (EC_data[1] != 'I'); // Keep looping until the ecSerial has sent the board info string (also indicating it has booted up, I think...)

  Serial.print("EC Board Info (Format: ?I,[board type],[Firmware Version]) -> "); Serial.println(EC_data);

  delay(10);
  ecSerial.write('C');  // Tell electrical conductivity board to continously ("C") transmit mesurements ...
  ecSerial.write(',');  //
  ecSerial.print(EC_SAMPLING_FREQUENCY);    // ... every x seconds (here x is the EC_SAMPLING_FREQUENCY variable)
  ecSerial.write('\r'); // Finish the command with the carrage return character.
    
  ecSerial.write('L');  // Tell electrical conductivity board to turn off LED to preserve power ...
  ecSerial.write(',');  //
  ecSerial.print(EC_LED);  // 1 to turn light on, 0 to turn light off
  ecSerial.write('\r'); // ... Finish the command with the charage return character.

  received_from_sensor = ecSerial.readBytesUntil('\r', EC_data, 10); // keep reading the reply until the return character is recived (or it gets to be 10 characters long, which shouldn't happen)
  EC_data[received_from_sensor] = 0; // Null terminate the data by setting the value after the final character to 0.
  Serial.print("EC Frequency Set Sucessfully? -> "); Serial.println(EC_data);
  Serial.print("EC LED on or off? -> ");
  if (EC_LED > 0) {Serial.println("on");}
    else {Serial.println("off");}

  Serial.println("--- Starting Datalogging ---");
}

void loop () {

  //Read electrical conductivity sensor
  if (ecSerial.available() > 0) {

    received_from_sensor = ecSerial.readBytesUntil(13, EC_data, 48);
    EC_data[received_from_sensor] = 0; // Null terminate the data by setting the value after the final character to 0.

    if ((EC_data[0] >= 48) && (EC_data[0] <= 57)) { // Parse data, if EC_data begins with a digit, not a letter (testing ASCII values).

      parse_data();

    }

    // Read the temperature sensor.
    uint16_t rtd = thermo.readRTD();
    float ratio = rtd;
    ratio /= 32768;
    tempPT = thermo.temperature(RNOMINAL, RREF);
    
    sensor.readSensor(); //read pressure sensor
    pressure_abs = sensor.pressure();

    DateTime now = rtc.now(); //check RTC
    char dateTimeString[40];
    get_date_time_string(dateTimeString, now);

    //output readings to serial
    Serial.print(dateTimeString);
    Serial.print(",");
    Serial.print(pressure_abs);
    Serial.print(",");
    Serial.print(tempPT);
    Serial.print(",");
    Serial.println(EC);

    //output readings to data file.
    File dataFile = SD.open(datalogFileName, FILE_WRITE);
    if (dataFile) {

      dataFile.print(dateTimeString);
      dataFile.print(",");
      dataFile.print(pressure_abs);
      dataFile.print(",");
      dataFile.print(tempPT);
      dataFile.print(",");
      dataFile.println(EC);
      dataFile.close();

      }

  }

  // Tip: For a slower overall logging frequency, set the EC_SAMPLING_FREQUENCY variable rather than adding a delay (this will avoid the possibility of garbled ec sensor readings)

}

void get_numbered_filename(char* outStr, const char* filePrefix, const char* fileExtension) {

  // Make base filename
  sprintf(outStr, "%s000.%s", filePrefix, fileExtension);
  int namelength = strlen(outStr);
  if (namelength > 12) Serial.println("Error: filename too long. Shorten your filename to < 5 characters (12 chars total w number & file extension) !");

  // Keep incrementing the number part of filename until we reach an unused filename
  int i = 1;
  while (SD.exists(outStr)) {  // keep looping if filename already exists on card. [If the filename doesn't exist, the loop exits, so we found our first unused filename!]

    int hundreds = i / 100;
    outStr[namelength - 7] = '0' + hundreds;
    outStr[namelength - 6] = '0' + (i / 10) - (hundreds * 10);
    outStr[namelength - 5] = '0' + i % 10;
    i++;

  }

}

void get_date_time_string(char* outStr, DateTime date) {
  // outputs the date as a date time string,
  sprintf(outStr, "%02d/%02d/%02d,%02d:%02d:%02d", date.month(), date.day(), date.year(), date.hour(), date.minute(), date.second());
  // Note: If you would like the date & time to be seperate columns chabge the space in the formatting string to a comma - this works because the file type is CSV (Comma Seperated Values)
}

void SDCardDateTimeCallback(uint16_t* date, uint16_t* time) // This funny function allows the sd-library to set the correct file created & modified dates for all sd card files (As would show up in the file explorer on your computer)
{
  DateTime now = rtc.now();
  *date = FAT_DATE(now.year(), now.month(), now.day());
  *time = FAT_TIME(now.hour(), now.minute(), now.second());
}

void parse_data() { // Parses data from the EC Circuit.

  EC = strtok(EC_data, ",");

}

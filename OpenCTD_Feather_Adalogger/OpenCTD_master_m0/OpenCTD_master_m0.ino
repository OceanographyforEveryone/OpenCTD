
//Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

//serial peripheral interface and library for SD card reader
#include <SPI.h> //serial peripheral interface for SD card reader
#include <SD.h> //library for SD card reader

//communication protocols for temperature sensors
#include <OneWire.h>
#include <DallasTemperature.h>

//Software libary for the pressure sensor
#include <MS5803_14.h>

//EC Circuit uses software serial
#include <SoftwareSerial.h>

RTC_DS3231 rtc; //define real-time clock

const int chipSelect = 4; //sets chip select pin for SD card reader
char datalogFileName[12];

/* This integer specifies how high accuracy you want your pressure sensor to be (oversampling resolution).

   Ok values: 256, 512, 1024, 2048, or 4096 (Higher = more accuracy but slower sampling frequency**)
 * ** There is no reason not to use the highest accuracy. This is because the datalogging rate is set by the
   sampling/response frequency of the ec sensor [default = 1 sec] (this is to avoid the case where both sensors send data at the same time). */

#define PRESSURE_SENSOR_RESOLUTION 4096
MS_5803 sensor = MS_5803(PRESSURE_SENSOR_RESOLUTION); // Define pressure sensor.

OneWire oneWire(6); // Define the OneWire port for temperature.
DallasTemperature sensors(&oneWire); //Define DallasTemperature input based on OneWire.

SoftwareSerial ecSerial(12, 13); // Define the SoftwareSerial port for conductivity.

double pressure_abs; //define absolute pressure variable

/* This integer specifies how high resolution you want your temperature sensors to be.

   Ok values: 9,10,11,12 (Higher = more accuracy but slower sampling frequency**)
 * ** There is no reason not to use the highest accuracy. This is because the datalogging rate is set by the
   sampling/response frequency of the ec sensor [default = 1 second] (this is to avoid the case where both sensors send data at the same time). */

#define TEMP_SENSOR_RESOLUTION 12

//Declare global temperature variables.
float tempA;
float tempB;
float tempC;
int tempADelayStartTime; // Define a variable to mark when we requested a temperature mesurement from A so we can wait the required delay before reading the value.
int tempBDelayStartTime; // Define a variable to mark when we requested a temperature mesurement from B so we can wait the required delay before reading the value.
int tempCDelayStartTime; // Define a variable to mark when we requested a temperature mesurement from C so we can wait the required delay before reading the value.
int requiredMesurementDelay = sensors.millisToWaitForConversion(TEMP_SENSOR_RESOLUTION);

//Declare global variables for eletrical conductivity
float EC_float = 0;
char EC_data[48]; // A 48 byte character array to hold incoming data from the conductivity circuit.
char *EC; // Character pointer for string parsing.
byte received_from_sensor = 0; // How many characters have been received.
byte string_received = 0; // Whether it received a string from the EC circuit.

#define EC_SAMPLING_FREQUENCY 1 // Set the requested sampling frequency of the conductivity probe in seconds (NO Decimals) (this by extension sets the overall frequency of logging).


void setup () {

  // comment the following three lines out for final deployment
#ifndef ESP8266
  while (!Serial && millis() < 20000); //for Leonardo/Micro/Zero - Wait for a computer to connect via serial or until a 20 second timeout has elapsed (This works because millis() starts counting the mlliseconds since the board turns on)
#endif

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

  get_numbered_filename(datalogFileName, "LOG", "CSV");

  Serial.print("Writing to datalog: ");
  Serial.println(datalogFileName);

  File dataFile = SD.open(datalogFileName, FILE_WRITE);

  if (dataFile) {
    Serial.println("====================================================");
    Serial.println("Date Time,Pressure,Temp A,Temp B,Temp C,Conductivity");
    dataFile.println("Date Time,Pressure,Temp A,Temp B,Temp C,Conductivity");
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
  
  sensors.begin();  // Intialize the temperature sensors.
  sensors.setResolution(TEMP_SENSOR_RESOLUTION);  // Set the resolution (accuracy) of the temperature sensors.
  sensors.requestTemperatures(); // on the first pass request all temperatures in a blocking way to start the variables with true data.
  tempA = get_temp_c_by_index(0);
  tempB = get_temp_c_by_index(1);
  tempC = get_temp_c_by_index(2);

  sensors.setWaitForConversion(false);  // Now tell the Dallas Temperature library to not block this script while it's waiting for the temperature mesurement to happen

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

  received_from_sensor = ecSerial.readBytesUntil('\r', EC_data, 10); // keep reading the reply until the return character is recived (or it gets to be 10 characters long, which shouldn't happen)
  EC_data[received_from_sensor] = 0; // Null terminate the data by setting the value after the final character to 0.
  Serial.print("EC Frequency Set Sucessfully? -> "); Serial.println(EC_data);
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

    // Read the temperature sensors.
    if (millis() - tempADelayStartTime > requiredMesurementDelay) { // wait for conversion to happen before attempting to read temp probe A's value;
      tempA = get_temp_c_by_index(0);
      sensors.requestTemperaturesByIndex(0);  // request temp sensor A start mesuring so it can be read on the following loop (if enough time elapses).
      tempADelayStartTime = millis();  // mark when we made the request to make sure we wait long enough before reading it.
    }

    if (millis() - tempBDelayStartTime > requiredMesurementDelay) { // wait for conversion to happen before attempting to read temp probe B's value;
      tempB = get_temp_c_by_index(1);
      sensors.requestTemperaturesByIndex(1);  // request temp sensor B start mesuring so it can be read on the following loop (if enough time elapses).
      tempBDelayStartTime = millis();  // mark when we made the request to make sure we wait long enough before reading it.
    }


    if (millis() - tempCDelayStartTime > requiredMesurementDelay) { // wait for conversion to happen before attempting to read temp probe C's value;
      tempC = get_temp_c_by_index(2);
      sensors.requestTemperaturesByIndex(2);  // request temp sensor C start mesuring so it can be read on the following loop (if enough time elapses).
      tempCDelayStartTime = millis(); // mark when we made the request to make sure we wait long enough before reading it.
    }

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
    Serial.print(tempA);
    Serial.print(",");
    Serial.print(tempB);
    Serial.print(",");
    Serial.print(tempC);
    Serial.print(",");
    Serial.println(EC);

    //output readings to data file.
    File dataFile = SD.open(datalogFileName, FILE_WRITE);
    if (dataFile) {

      dataFile.print(dateTimeString);
      dataFile.print(",");
      dataFile.print(pressure_abs);
      dataFile.print(",");
      dataFile.print(tempA);
      dataFile.print(",");
      dataFile.print(tempB);
      dataFile.print(",");
      dataFile.print(tempC);
      dataFile.print(",");
      dataFile.println(EC);
      dataFile.close();

      }

  }

  // Tip: For a slower overall logging frequency, set the EC_SAMPLING_FREQUENCY variable rather than adding a delay (this will avoid the possibility of garbled ec sensor readings)

}

void get_numbered_filename(char* outStr, char* filePrefix, char* fileExtension) {

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
  sprintf(outStr, "%02d/%02d/%02d %02d:%02d:%02d", date.month(), date.day(), date.year(), date.hour(), date.minute(), date.second());
  // Note: If you would like the date & time to be seperate columns chabge the space in the formatting string to a comma - this works because the file type is CSV (Comma Seperated Values)
}

void SDCardDateTimeCallback(uint16_t* date, uint16_t* time) // This funny function allows the sd-library to set the correct file created & modified dates for all sd card files (As would show up in the file explorer on your computer)
{
  DateTime now = rtc.now();
  *date = FAT_DATE(now.year(), now.month(), now.day());
  *time = FAT_TIME(now.hour(), now.minute(), now.second());
}

float get_temp_c_by_index(int sensor_index) {
  
  float value = sensors.getTempCByIndex(sensor_index);
  if (value == DEVICE_DISCONNECTED_C) {
    return NAN; // Return Not a Number (NAN) to indicate temperature probe has error or is disconnected.
  } else {
    return value; // otherwise return the measured value.
  }

}

void parse_data() { // Parses data from the EC Circuit.

  EC = strtok(EC_data, ",");

}


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

MS_5803 sensor = MS_5803(512); // Define pressure sensor.

OneWire oneWire(6); // Define the OneWire port for temperature.
DallasTemperature sensors(&oneWire); //Define DallasTemperature input based on OneWire.

SoftwareSerial ecSerial(12, 13); // Define the SoftwareSerial port for conductivity.

double pressure_abs; //define absolute pressure variable

//Declare global temperature variables.
float tempA;
float tempB;
float tempC;

//Declare global variables for eletrical conductivity
float EC_float = 0;  
char EC_data[48]; // A 48 byte character array to hold incoming data from the conductivity circuit. 
char *EC; // Character pointer for string parsing.
byte received_from_sensor = 0; // How many characters have been received.
byte string_received = 0; // Whether it received a string from the EC circuit.

void setup () {

// comment the following three lines out for final deployment
  #ifndef ESP8266
    while (!Serial);   //for Leonardo/Micro/Zero
 #endif

  Serial.begin(9600);

//Initialize SD card reader
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    
    Serial.println("Card failed, or not present");
    return;
    
  }
  
  Serial.println("card initialized.");

  delay(1000); 

  if (! rtc.begin()) {
    
    Serial.println("Couldn't find RTC");
    while (1);
    
  }

  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  
  if (dataFile) {
    
    dataFile.println("");
    dataFile.println("=== New Cast ===");
    dataFile.println("");
    dataFile.close();
    
  }

//Initialize real-time clock
  if (rtc.lostPower()) {

    //reset RTC with time when code was compiled if RTC loses power
    Serial.println("RTC lost power, lets set the time!"); 
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
  }
  
  delay(250);       // Wait a quarter second to continue.

//Initialize sensors  
  sensor.initializeMS_5803(); // Initialize pressure sensor   
  
  sensors.begin();  // Intialize the temperature sensors.

  ecSerial.begin(9600); // Set baud rate for conductivity circuit.  

}

void loop () {
  
  DateTime now = rtc.now(); //check RTC

  sensor.readSensor(); //read pressure sensor
  pressure_abs = sensor.pressure();

//read temperature sensor
  sensors.requestTemperatures();
  tempA = sensors.getTempCByIndex(0);
  tempB = sensors.getTempCByIndex(1);
  tempC = sensors.getTempCByIndex(2);

//Read electrical conductivity sensor
  if (ecSerial.available() > 0) {

    received_from_sensor = ecSerial.readBytesUntil(13, EC_data, 48);
    EC_data[received_from_sensor] = 0; // Null terminate the data by setting the value after the final character to 0.
  
  }

  if ((EC_data[0] >= 48) && (EC_data[0] <=57)) { // Parse data, if EC_data begins with a digit, not a letter (testing ASCII values).

    parse_data();
    
  }  
  
//output readings to serial monitor. A whole mess of if/else statements to keep numbers formatted correctly
  Serial.print(now.year(), DEC);
  Serial.print('/');

  if (now.month()<10) {
    
    Serial.print(0);
    Serial.print(now.month(), DEC);
    
  }

  else {
    
  Serial.print(now.month(), DEC);
  
  }
  
  Serial.print('/');
  
  if (now.day()<10) {
    
    Serial.print(0);
    Serial.print(now.day(), DEC);
    
  }

  else {
    
  Serial.print(now.day(), DEC);
  
  }
  
  Serial.print("  ");
  
  if (now.hour()<10) {
    
    Serial.print(0);
    Serial.print(now.hour(), DEC);
    
  }

  else {
    
  Serial.print(now.hour(), DEC);
  
  } 
  
  Serial.print(':');
  
  if (now.minute()<10) {
    
    Serial.print(0);
    Serial.print(now.minute(), DEC);
    
  }

  else {
    
  Serial.print(now.minute(), DEC);
  
  }  

  Serial.print(':');
  
  if (now.second()<10) {
    
    Serial.print(0);
    Serial.print(now.second(), DEC);
    
  }

  else {
    
  Serial.print(now.second(), DEC);
  
  }
  
  Serial.print("  ");
  Serial.print(pressure_abs);
  Serial.print("  ");  
  Serial.print(tempA);
  Serial.print("  ");
  Serial.print(tempB);
  Serial.print("  ");
  Serial.print(tempC); 
  Serial.print("  "); 
  Serial.println(EC);

  //output readings to data file. A whole mess of if/else statements to keep numbers formatted correctly
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  
  if (dataFile) {
      
    dataFile.print(now.year(), DEC);
    dataFile.print('/');
 
    if (now.month()<10) {
    
    dataFile.print(0);
    dataFile.print(now.month(), DEC);
    
    }

    else {
    
     dataFile.print(now.month(), DEC);
  
    }
  
    dataFile.print('/');
  
    if (now.day()<10) {
    
      dataFile.print(0);
      dataFile.print(now.day(), DEC);
    
    }

    else {
    
      dataFile.print(now.day(), DEC);
  
    }
  
    dataFile.print("  ");
  
    if (now.hour()<10) {
    
      dataFile.print(0);
      dataFile.print(now.hour(), DEC);
    
    }

    else {
    
      dataFile.print(now.hour(), DEC);
  
    } 
  
    dataFile.print(':');
  
    if (now.minute()<10) {
    
      dataFile.print(0);
      dataFile.print(now.minute(), DEC);
    
    }

    else {
    
      dataFile.print(now.minute(), DEC);
  
    }  

    dataFile.print(':');
  
    if (now.second()<10) {
    
      dataFile.print(0);
      dataFile.print(now.second(), DEC);
    
    }

    else {
    
     dataFile.print(now.second(), DEC);
  
    }
  
    dataFile.print("  ");
    dataFile.print(pressure_abs);
    dataFile.print("  ");  
    dataFile.print(tempA);
    dataFile.print("  ");
    dataFile.print(tempB);
    dataFile.print("  ");
    dataFile.print(tempC);
    dataFile.print("  "); 
    dataFile.println(EC);
    dataFile.close();    

  }
  
  delay(50);

}

void parse_data() { // Parses data from the EC Circuit.

  EC = strtok(EC_data, ",");                  

}

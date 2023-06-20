//For use calibrating the Atlas EZO conductivity sensor and circuit. 

#include <SoftwareSerial.h>

//communication protocols for temperature sensors

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(6); // Define the OneWire port for temperature.
DallasTemperature sensors(&oneWire); //Define DallasTemperature input based on OneWire.

SoftwareSerial ecSerial(12, 13); // Define the SoftwareSerial port for conductivity.

#define TEMP_SENSOR_RESOLUTION 12

//Declare global temperature variables.
float tempA;
float tempB;
float tempC;
float avgTemp;
float roundTemp;
float fTemp;

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

#define EC_SAMPLING_FREQUENCY 0 // Set the requested sampling frequency of the conductivity probe in seconds (NO Decimals) (this by extension sets the overall frequency of logging).

void setup() {

#ifndef ESP8266
 while (!Serial && millis() < 20000); //for Leonardo/Micro/Zero - Wait for a computer to connect via serial or until a 20 second timeout has elapsed
#endif


  Serial.begin(9600);    // serial / USB port

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

  Serial.println("");
  Serial.print("EC Board Info (Format: ?I,[board type],[Firmware Version]) -> "); Serial.println(EC_data);

  delay(10);
  ecSerial.write('C');  // Tell electrical conductivity board to continously ("C") transmit mesurements ...
  ecSerial.write(',');  //
  ecSerial.print(EC_SAMPLING_FREQUENCY);    // ... every x seconds (here x is the EC_SAMPLING_FREQUENCY variable)
  ecSerial.write('\r'); // Finish the command with the carrage return character.

  received_from_sensor = ecSerial.readBytesUntil('\r', EC_data, 10); // keep reading the reply until the return character is recived (or it gets to be 10 characters long, which shouldn't happen)
  EC_data[received_from_sensor] = 0; // Null terminate the data by setting the value after the final character to 0.
  Serial.println("");
  Serial.println("Please review the OpenCTD Calibration Guide or the Atlas Scientific EZO_EC");
  Serial.println("embedded conductivity circuit datasheet for more details on calibration.");
  Serial.println("");
  Serial.println("----Useful Commands----"); 
  Serial.println("");
  Serial.println("c,0              --> disable continuous readings");
  Serial.println("c,1              --> enable continuous readings once per second");
  Serial.println("k,?              --> query probe K value");
  Serial.println("k,1              --> set probe K value to 1");
  Serial.println("cal,clear        --> clear calibration");
  Serial.println("cal,dry          --> set the dry probe calibration to 0");
  Serial.println("cal,low,12880    --> set the low standard calibration to 12880");
  Serial.println("cal,high,80000   --> set the high standard calibration to 80000");
  Serial.println("cal,?            --> query calibration status of probe");
  Serial.println("t,x              --> set temperature compensation to x degrees celsius");
  Serial.println("t,?              --> query temperature compensation value in degrees celsius");
  Serial.println("");
  Serial.println("----Useful Commands----"); 
  Serial.println("");

}

byte rx_byte = 0;        // stores received byte

void loop() {



  // check if byte available from USB port
  if (Serial.available()) {
    rx_byte = Serial.read();
    // send a byte to the software serial port
    ecSerial.write(rx_byte);
  }

  // check if byte available on the software serial port
  if (ecSerial.available()) {

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

    avgTemp = ((tempA+tempB+tempC)/3);
    roundTemp = round(avgTemp*10);
    fTemp = (roundTemp/10);

    // print conductivity from parsed string
    Serial.print(EC_data);
    Serial.print(", Temp = ");
    Serial.println(fTemp);
    
  }
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

//For use calibrating the Atlas EZO conductivity sensor and circuit. 

#include <SoftwareSerial.h>

SoftwareSerial ecSerial(12, 13); // Define the SoftwareSerial port for conductivity.

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

    // print conductivity from parsed string
    Serial.println(EC_data);
    
  }
}

void parse_data() { // Parses data from the EC Circuit.

  EC = strtok(EC_data, ",");

}

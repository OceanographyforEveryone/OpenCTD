/* MS5803_14_test.ino
  This version *only works* with the MS5803-14BA sensor, not the other
  pressure models (like the MS5803-30BA, MS5803-01BA etc). You can find
  libraries for those other models at http://github.com/millerlp
  
  A basic sketch to test communication with a Measurement Specialties MS5803
  pressure sensor. The MS5803 should be hooked up in I2C communication mode
  (PS pin 6 tied to Vdd) and I2C address 0x76 (CSB pin 3 tied to Vdd).
  Use 10k ohm resistors between the SDA pin and Vdd (+3.3V), and 
  SCL and Vdd (+3.3V) to keep the I2C lines from floating. 
  The MS5803 cannot tolerate 5V supply voltage or data links, so use 3.3V 
  to power it. On a 5V Arduino, you may use the 3.3V output to power the
  the MS5803, and put a 10k ohm resistor between SDA line and the +3.3V supply,
  as well as a 10k ohm resistor between  SCLK line and +3.3V supply to limit 
  the data lines to 3.3V max.

  Luke Miller April 1 2014
*/

// The Wire library carries out I2C communication
#include <Wire.h>
// Place the MS5803_14 library folder in your Arduino 'libraries' directory
#include <MS5803_14.h> 

// Declare 'sensor' as the object that will refer to your MS5803 in the sketch
// Enter the oversampling value as an argument. Valid choices are
// 256, 512, 1024, 2048, 4096. Library default = 512.
MS_5803 sensor = MS_5803(512);

void setup() {
  // Start the serial ports.
  Serial.begin(9600); // other values include 9600, 14400, 57600 etc.
  delay(2000);
  // Initialize the MS5803 sensor. This will report the
  // conversion coefficients to the Serial terminal if present.
  // If you don't want all the coefficients printed out, 
  // set sensor.initializeMS_5803(false).
  if (sensor.initializeMS_5803()) {
    Serial.println( "MS5803 CRC check OK." );
  } 
  else {
    Serial.println( "MS5803 CRC check FAILED!" );
  }
  delay(3000);
}

void loop() {
  // Use readSensor() function to get pressure and temperature reading. 
  sensor.readSensor();
   // Uncomment the print commands below to show the raw D1 and D2 values
//  Serial.print("D1 = ");
//  Serial.println(sensor.D1val());
//  Serial.print("D2 = ");
//  Serial.println(sensor.D2val());

  // Show pressure
  Serial.print("Pressure = ");
  Serial.print(sensor.pressure());
  Serial.println(" mbar");
  
  // Show temperature
  Serial.print("Temperature = ");
  Serial.print(sensor.temperature());
  Serial.println("C");

  delay(1000); // For readability
}



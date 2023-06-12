//For use calibrating the Atlas EZO conductivity sensor and circuit. 

#include <SoftwareSerial.h>

SoftwareSerial gtSerial(12, 13); // Arduino RX, Arduino TX

void setup() {
  Serial.begin(9600);    // serial / USB port
  gtSerial.begin(9600);  // software serial port
}

byte rx_byte = 0;        // stores received byte

void loop() {
  // check if byte available from USB port
  if (Serial.available()) {
    rx_byte = Serial.read();
    // send a byte to the software serial port
    gtSerial.write(rx_byte);
  }

  // check if byte available on the software serial port
  if (gtSerial.available()) {
    // get the byte from the software serial port
    rx_byte = gtSerial.read();
    Serial.write(rx_byte);
  }
}

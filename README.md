OpenCTD
=======

Source code for the OpenCTD

Reads an MS5803-14BA pressure sensor, 3-gang dallas temperature probe, and an Atlas conductivity circuit with homebrewed probe. 

Kludged together by Andrew Thaler from code by Walt Holm, arduino.cc samples, Atlas scientific, Vhati, Russell Neches, and myself. Runs on Arduino.

Currently a mess.

Required Arduino Libraries:

I2C library for the MS5803_14BA 14bar pressure sensor
https://github.com/millerlp/MS5803_14

Dallas Temperature Control for the DS18B20 thermometer
https://milesburton.com/Dallas_Temperature_Control_Library

OneWire **
http://www.pjrc.com/teensy/td_libs_OneWire.html
http://playground.arduino.cc/Learning/OneWire

SD *
https://www.arduino.cc/en/Reference/SD

SoftwareSerial *
http://www.pjrc.com/teensy/td_libs_SoftwareSerial.html
https://www.arduino.cc/en/Reference/SoftwareSerial

SPI **
https://www.pjrc.com/teensy/td_libs_SPI.html
https://www.arduino.cc/en/Reference/SPI

Wire *
http://www.pjrc.com/teensy/td_libs_Wire.html
https://www.arduino.cc/en/Reference/Wire

* Included with Arduino.
** Included with Arduino. A newer version may be available.

Pinouts:

A4 - Pressure Sensor SDA
A5 - Pressure Sensor SCLK
D7 - Temperature Data
D2 - Conductivity RX
D3 - Conductivity TX

This folder contains support code for the OpenCTD. 

In [Arduino Libraries](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Support/Arduino%20Libraries), you will find compressed .zip files for all of the libraries required to run the OpenCTD software that do not come bundled with Arduino. These include:

- [Arduino-Temperature-Control-Library.zip](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Software/Support/Arduino%20Libraries/Arduino-Temperature-Control-Library.zip) which allows you to communicate with the temperature sensor array.
- [MS5803_14.zip](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Software/Support/Arduino%20Libraries/MS5803_14.zip) which supports the 14-bar pressure sensors.
- [OneWire.zip](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Software/Support/Arduino%20Libraries/OneWire.zip) which allows you to control the Dallas 1-wire protocol family of devices.
- [RTClib.zip](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Software/Support/Arduino%20Libraries/RTClib.zip) which drives the real-time clock.
- [SoftwareSerial.zip](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Software/Support/Arduino%20Libraries/SoftwareSerial.zip) which enables the serial monitor on the Adafruit Adalogger.

In addition, you will find [Serial_for_EC_Calibration_m0](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Support/Serial_for_EC_Calibration_m0) which allows you to calibrate the OpenCTD's conductivity circuit through the Arduino IDE terminal and [RTC_Reset](Software/Support/RTC_Reset) which resets the real-time clock to the last system time when the software was compiled. 

Please reference the [OpenCTD Construction and Operation Manual](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/OpenCTD_Feather_Adalogger/OpenCTD_ConstructionOperation.pdf) for a full description of how to import and use this software.

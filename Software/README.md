# OpenCTD Software

This directory contains software for using the OpenCTD. There are three types of
software here: firmware, which runs on the OpenCTD itself, support software which includes the require Arduino libraries as well as software for calibrating the conductivity sensor, and analysis
software, which is used to process data files copied from the OpenCTD to
another device (such as a personal computer) for analysis.

### Firmware

The OpenCTD is controlled by an [Adalogger Feather
M0](https://www.adafruit.com/product/2796) microcontroller development board.
Instructions on how to upload OpenCTD firmware to the microcontroller board can
be found in the [Documentation](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Documentation/Manual). General instructions and
learning resources about the Adalogger Feather M0 board itself can be found in
the [Adafruit Learning
Guide](https://learn.adafruit.com/adafruit-feather-m0-adalogger/).

[OpenCTD_master_m0](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Firmware/OpenCTD_m0) : This is the core software
for the OpenCTD. The file `OpenCTD_master_m0.ino` contains the basic firmware
used in normal deployment of the OpenCTD instrument.

[OpenCTD_master_m0_30bar](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Firmware/OpenCTD_m0_30Bar) : An alternative
to the basic firmware for use with a 30bar pressure sensor instead of the
standard 14bar sensor.

### Support
[Calibration](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Support/Serial_for_EC_Calibration_m0): The calibration software which allows users to calibrate the Atlas Scientific EZO conductivity sensor.

[RTC Reset](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Support/RTC_Reset): A small program to help you reset the real-time clock if it falls out of sync. 

[Arduino Libraries](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Support/Arduino%20Libraries): Five Arduino Libraries required to run the OpenCTD, in downloadable ZIP files. 

### Analysis

OpenCTD writes data
to its microSD card in a generic CSV format that is compatible with many
different tools. In the [Analysis](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Analysis) directory, you will find a few
examples of how to import and process data from the OpenCTD using different
software packages. Please use the software that best suits your own needs!

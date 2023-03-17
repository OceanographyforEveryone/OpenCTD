# OpenCTD Software

This directory contains software for using the OpenCTD. There are two types of
software here : firmware, which runs on the OpenCTD itself, and analysis
software, which is used to process data files copied from the OpenCTD to
another device (such as a personal computer) for analysis.

### Firmware

The OpenCTD is controlled by an [Adalogger Feather
M0](https://www.adafruit.com/product/2796) microcontroller development board.
Instructions on how to upload OpenCTD firmware to the microcontroller board can
be found in the [Documentation](../Documentation). General instructions and
learning resources about the Adalogger Feather M0 board itself can be found in
the [Adafruit Learning
Guide](https://learn.adafruit.com/adafruit-feather-m0-adalogger/).

[`OpenCTD_master_m0`](Firmware/OpenCTD_master_m0) : This is the core software
for the OpenCTD. The file `OpenCTD_master_m0.ino` contains the basic firmware
used in normal deployment of the OpenCTD instrument.

[`OpenCTD_master_m0_30bar`](Firmware/OpenCTD_master_m0_30Bar/) : An alternative
to the basic firmware for use with a 30bar pressure sensor instead of the
standard 14bar sensor.

[`Calibration`](Firmware/Calibration) : The calibration firmware, including the
revised Serial Protocol described in the manual and the conductivity
calibration firmware.

### Analysis

Once you have collected data, you will need to analyze it. OpenCTD writes data
to its microSD card in a generic CSV format that is compatible with many
different tools. In the [Analaysis](Analysis/) directory, you will find a few
examples of how to import and process data from the OpenCTD using different
software packages. Please use the software that best suits your own needs!

# OpenCTD Software

This directory contains software for using the OpenCTD. There are two types of
software here : firmware, which runs on the OpenCTD itself, and analysis
software, which is used to process data files copied from the OpenCTD to
another device (such as a personal computer) for analysis.

### Firmware

The OpenCTD is controlled by an 
[Adalogger Feather M0](https://www.adafruit.com/product/2796) microcontroller 
development board. Instructions on how to upload OpenCTD firmware to the microcontroller board
can be found in the [Documentation](../Documentation). General instructions and
learning resources about the Adalogger Feather M0 board itself can be found in
the [Adafruit Learning Guide](https://learn.adafruit.com/adafruit-feather-m0-adalogger/).

Core software: [`OpenCTD_master_m0.ino`](Firmware/OpenCTD_master_m0)

Calibration firmware, including the revised Serial Protocol described in the
manual and the conductivity calibration firmware:
[`Calibration`](Firmware/Calibration)

If you are using a 30bar pressure sensor instead of the 14bar sensor, use the
alternative [`OpenCTD_master_m0_30bar.ino`](Firmware/OpenCTD_master_m0_30Bar/)
firmware.

### Analysis

Once you have collected data, you will need to analyze it. OpenCTD writes data
to its microSD card in a generic CSV format that is compatible with many
different tools. In the [Analaysis](Analysis/) directory, you will find a few
examples of how to import and process data from the OpenCTD using different
software packages. Please use the software that best suits your own needs!

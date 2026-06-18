# OpenCTD Hardware 

This directory contains hardware files for building the OpenCTD Rev8. The [3D printable shapefiles](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Hardware/3DPrints) include the PowerSquid protective chassis, the sensor baseplate, and the router jigs and other accessories. The [printed circuit boards](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Hardware/PCB) include the KiCad and Gerber files for the OpenCTD Rev8 Control Board and the Oceanography for Everyone Custom Pressure Sensor breakout board. 

If you've been lucky enough to recieve Andrew's business card, [Benchtester](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Hardware/Benchtester) includes instructions for building a working test board for OpenCTD components, though, please note, the Benchtester was designed for the OpenCTD Rev7. 

### Electronics

The OpenCTD is controlled by an [Adalogger Feather M0](https://www.adafruit.com/product/2796) microcontroller development board.

Instructions on how to upload OpenCTD firmware to the microcontroller board can
be found in [Documentation](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Documentation/Manual). General instructions and
learning resources about the Adalogger Feather M0 board itself can be found in the [Adafruit Learning
Guide](https://learn.adafruit.com/adafruit-feather-m0-adalogger/).

The OpenCTD electronics can be assembled using a breadboard, or using a custom PCB. The custom PCB is designed using [KiCad](https://www.kicad.org/), and can be ordered in small batches from many PCB fabrication services around the world using the files located in the [PCB](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Hardware/PCB) directory.

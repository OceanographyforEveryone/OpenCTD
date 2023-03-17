# OpenCTD Hardware 

This directory contains files for building the OpenCTD. There are two types of
systems here : the electronics, which include the sensors, wiring, power, data
acquisition and microcontroller, and the enclosure, which include 3D printable
parts needed to construct the waterproof housing that makes the OpenCTD an
oceanographic instrument.

### Electronics

The OpenCTD is controlled by an [Adalogger Feather
M0](https://www.adafruit.com/product/2796) microcontroller development board.
Instructions on how to upload OpenCTD firmware to the microcontroller board can
be found in the [Documentation](../Documentation). General instructions and
learning resources about the Adalogger Feather M0 board itself can be found in
the [Adafruit Learning
Guide](https://learn.adafruit.com/adafruit-feather-m0-adalogger/).

The OpenCTD electronics can be assembled using a breadboard, or using a custom
PCB. The custom PCB is designed using [KiCad](https://www.kicad.org/), and can
be ordered in small batches from many PCB fabrication services around the world
using the files located in the [PCB](Electronics/PCB) directory.

### Enclosure

Most of the OpenCTD enclosure is constructed from PCV plumbing tubing and
components. However, there are some specialized parts that should be 3D printed
for mounting the electronics and sensor array. These files are located in the
[Enclosure](Enclosure/Models) directory.

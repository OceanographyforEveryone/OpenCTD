OpenCTD
=======

### 1.0 Overview

**Conductivity, temperature, and depth (CTD).**  These three measurements allow scientists to unlock ocean patterns hidden beneath the sea's surface. The ocean is not uniform, it its filled with swirling eddies, temperature boundaries, layers of high and low salinity, changing densities, and other physical characteristics invisible to an observer floating upon its surface. To reveal these patterns in, oceanographers employ a CTD--an oceanographic instument that, at its core, measures temeprature, salinity, and depth down a water column. The CTD is the workhorse of oceanographic research. 

CTDs are expensive, and that expense can act as a barrier-to-entry for researchers with limited budgets, scientists from developing nations, citizen oceanographers, and students of all levels interested in learning more about their local coasts and waterways. 

The OpenCTD is a low-cost, open-source CTD suitable for both educators and scientists. The platform is built using reasonably accessible parts and is powered by an Arduino-based microcontroller. Source codes and building instructions are freely available. The device sufficeintly accurate for scientific research, can be constructed for approximately $300, and is effective to 200 meters depth.

Why 200 meters? For many coastal regions, 200 meters of water depth covers the majority of the ocean that is accessible by small boat and generally the maximum depth of the continental shelf. The OpenCTD is targeted to people working in this niche, where entire research projects can be conducted for less than the cost of a commercial CTD. The OpenCTD is scalable, and someone with the inclination and expertise can adapt an OpenCTD to operate in deeper waters.

*__If you build an OpenCTD please let the [team at Oceanography For Everyone](http://oceanographyforeveryone.com/#meetAnchor) know. We love to keep up with the community of people using these devices. During your build session, or while using an OpenCTD or other [Oceanography for Everyone](http://oceanographyforeveryone.com/) tool, tweet [#HackTheOcean](https://twitter.com/hashtag/HackTheOcean?src=hash) so the community can follow your efforts!__*

####1.1 Skills Needed

Building an OpenCTD does require some basic soldering and coding knowledge, but it is also a great opportunity to learn those skills. With an hour or two of practice, you can develop the basic soldering skills needed to build an OpenCTD. [This descriptive, illustrative comic from Mighty Ohm] (http://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf) presents soldering fundamentals in an accesible and approachable format.

Andrew has used this [MightyOhn Geiger Counter Kit](http://mightyohm.com/blog/products/geiger-counter/) and this [Mega Menorah 9000 Soldering Kit](http://shop.evilmadscientist.com/productsmenu/756) to teach basic soldering skills to students from ages 10 to 65. 

Arduino is a relatively intuitive coding environment, but it can still seem daunting to first-time users. Practically, we have already created the code you will need to run the OpencTD, but it is extremely beneficial, particularly for end users, to understand what the software is doing. The book [Environmental Monitoring with Arduino: Building Simple Devices to Collect Data About the World Around Us](http://amzn.to/28JBqOI) is short, easy to understand, and will also provide you with some ideas for expanding your inventory of open-source environmental sensors. 

### 2.0 Project Status

The OpenCTD is now stable on the Qduino Mini platform, with comprehensive build instructions provided and a growing user community.  

#### 2.1 Field Trials

**_Lake Superior, R/V Blue Heron_:**Initial field trials were completed in October of 2015 and analysis of the data from the first several casts confirms the accuracy of OpenCTD as well as depth tolerance to 140 meters. All data and field notes from the first Field Trial can be found in the [Blue Heron 15-11](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/Blue_Heron_2015-11) repository.

### 3.0 Bill of Materials

Almost all of the necessary parts can be found through Amazon or Sparkfun. Visit our [Parts Depot](http://oceanographyforeveryone.com/depot.html) for a list of Amazon-sourceable parts.

Additional components, like a pre-fabricated [pressure sensor module] (https://www.sparkfun.com/products/12909), [LiPo batteries] (https://www.sparkfun.com/products/8483), [SMD boards] (https://www.sparkfun.com/products/13655), and the [qDuino Mini] (https://www.sparkfun.com/products/13614) can be found at Sparkfun. The MS5803-14BA pressure sensor previously needed to be special ordered from a parts supplier, but [SparkFun] (https://www.sparkfun.com/products/12909) has a (much more expensive) commercial 14-bar unit using the same sensor.

Servoflo sells the raw, calibrated pressure sensor in both [14Bar] (http://www.servoflo.com/download-archive/data-sheets/220-calibrated-digital-sensor-modules/614-ms5803-14ba) and [30Bar] (http://www.servoflo.com/download-archive/data-sheets/220-calibrated-digital-sensor-modules/613-ms5803-30ba) modules. These are surface mounted sensors and require significant soldering skills to mount properly. Detailed descriptions of the differeces and benefits between the two pressure sensors is discussed in section 5.2

PVC pipe can be found at most home supply stores. 

#### 3.1 Tools
- wire cutter
- wire stripper
- soldering iron
- solder tip cleaner
- helping hands soldering station
- epoxy gun
- needle-nosed pliers
- multimeter
- utility knife
- hot glue gun
- heat gun
- saw
- drill
- 1" bit (for holes in PVC)
- laptop
- micro-USB cable
- coffe maker (because coffee)

#### 3.2 Consumables
- sand paper
- Hysol E90-FL epoxy
- venturi mixing nozzles for epoxy
- solid core wire (6 colors)
- solder
- desoldering braid
- heat-shrink tubing
- electical tape
- hot glue
- mineral oil
- calibration standard for conductivity
- coffee

#### 3.3 Required Arduino Libraries
+ Included with Arduino IDE:
  - [**SPI.**] (https://www.arduino.cc/en/Reference/SPI) Serial Peripheral Interface for communicating with a standard SD card reader.
  - [**SoftwareSerial.**] (https://www.arduino.cc/en/Reference/SoftwareSerial) For communicating with serial devices like the conductivity circuit.
  - [**Wire.**] (https://www.arduino.cc/en/Reference/Wire) For communicating with I2C devices like the pressure sensor. 
+ Need to download and install ([How to install Arduino libraries](https://www.arduino.cc/en/Guide/Libraries)):
  + [**SD.**] (https://www.arduino.cc/en/Reference/SD) For reading and writing to a standard SD card reader.
  + [**SparkFun_MS5803_I2C.**](https://github.com/sparkfun/SparkFun_MS5803-14BA_Breakout_Arduino_Library/tree/V_1.1.0) For the MS5803 14 Bar pressure sensor (*__Note__: if you decide to use a different pressure sensor, you will need to update this library*)
  + [**Dallas Temperature Control.**](https://milesburton.com/Dallas_Temperature_Control_Library) Allows you to communicate with the DS18B20 thermistor. 
  + [**OneWire.**] (http://www.pjrc.com/teensy/td_libs_OneWire.html) For controlling the Dallas 1-wire family of devices. 

#### 3.4 Other Useful Software

+ [**Qduino.h and Qduino fuelGauge**](https://github.com/sparkfun/Arduino_Boards/tree/master/sparkfun/avr/libraries/Qduino) allows you to measure the charge on you battery. 
+ [**simple_serial_for_EC_calibration**](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/simple_serial_for_EC_calibration) is a basic serial monitor program to help you calibrate the conductivity probe. 

### 4.0 Arduino Qduino Pinouts

- **SD Card Reader:** CS (D4), SCK (D15), MOSI (D16), MISO (D17)
- **Pressure Sensor:** SDA (D2), SCL (D3)
- **Temperature Sensors:** Data (D6)
- **Conductivity Circuit:** TX (D8), RX (D9)

### 5.0 Build Instructions

We are continously updating and improving OpenCTD prototypes. These instuctions are subject to change. Please read through the entire guide before you make any irreversible changes to the hardware. Most manufacturers will consider the warranty void once you being soldering. 

**Important note about power consumption:** All sourced modules are rated to work at 3.3V, however, when two or more are running simultaneously, the 3.3V output on most Arduinos yield inconsistent results and the SD card reader may not function at all. We recommend powering the entire system with a minimum of 3.7V. On standard Arduino's, the 5V output should be used. On the Qduino, VCC with a 3.7V battery is sufficient. 

**_We strongly encourage you to test all the components one by one on a breadboard before soldering modules together. If you're planning to build multiple CTDs, we recommend that you use a dedicated Qduino, with header pins, for breadboard testing._**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![A complete OpenCTD system mounted to a breadboard for testing before soldering and potting](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/BB.jpg?raw=true "A complete OpenCTD system mounted to a breadboard for testing before soldering and potting")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*A complete OpenCTD system mounted to a breadboard for testing before soldering and potting.*

Before you begin, flash the [OpenCTD software](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/OpenCTD_qDuino) to your Qduino Mini so that you can test each component during the build. 

#### 5.1 SD Card Reader

The [Sainsmart microSD card reader](http://amzn.to/265xAZQ) that we recommend is a 'plug and play' module. Connect each pin following the pinout guide above. For fitting into a tight housing, you may want to bend each header pin 90 degrees (using needle-nosed pliers) or remove the headers completely. Hookup wires should be at least 8 cm long, though you may eventually shorten them to suit your preference. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![SD card reader with bent headers](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/SD1.jpg?raw=true "SD card reader with bent headers")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*SD card reader with bent headers.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![SD card reader with soldered connections](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/SD2.jpg?raw=true "SD card reader with soldered connections")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*SD card reader with soldered connections.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![SD card reader with heat shrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/SD3.jpg?raw=true "SD card reader with heat shrink")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*SD card reader with heat shrink*

To prepare the microSD card, wipe the card and create a single, empty text file called **datalog.txt**.

#### 5.2 Pressure Sensor

There are several options and configurations for the pressure sensor, all of which rely on the MS5803-14BA sensor module. The simplest solution is a prefabricated model that requires no additional modificaion, just solder headers or connectors to Gound, Vin, SCL, and SDA and connect to the Qduino (we strongly recommend this option for people who do not have extensive experience with soldering). 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Three possible pressure modules.](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS1.jpg?raw=true "Three possible pressure modules")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Three possible pressure modules.*

Other solutions require a small 100nF (104) capacitor and 10kOhm pull-up resistor. The resistor bridges pin 3 and 6 on the pressure module. The capacitor bridges pins 2 and 5. SCLK is pin 1, Ground is pin 2, VCC in pin 5, and SDI/SDA is pin 7. Pins 5 and 6 need to be bridged with a jumper wire. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Layout for pressure module](https://edwardmallon.files.wordpress.com/2014/03/pressure-sensor-wiring.jpg?w=640 "Layout for pressure module")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Layout for pressure module. From [The Cave Pearl Project](https://edwardmallon.wordpress.com/2014/03/27/adding-a-ms5803-02-high-resolution-pressure-sensor/).*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Back view of one DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS2.jpg?raw=true "Back view of one DIY pressure module")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Back view of one DIY pressure module.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Front view of a small DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS3.jpg?raw=true "Front view of a small DIY pressure module")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Front view of a small DIY pressure module.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Back view of the same DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS4.jpg?raw=true "Back view of the same DIY pressure module")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Back view of the same DIY pressure module.*

Hookup wires for the pressure sensor should be about 5 cm longer than the length of pipe used for the house (we recommend a total length of 30 cm). You may end up shortening these depending on your preference.  

#### 5.3 Temperature Sensors

The temperature probes use an off-the-shelf DS18B20 digital thermistor in a stainless steel housing. We use a battery of 3 probes averaged together for more consistent readings. The OneWire protocol allows mutliple probes to be queried on the same pin, so all three probes feed into a single data pin. To prepare the probes, cut the wire length to 30 cm. Solder three data strands, three power strands, and three ground strands together and attach a single solid core wire to each. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Three temperature probes prepped for soldering](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T1.jpg?raw=true "Three termperature probes prepped for soldering")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Three temperature probes prepped for soldering.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes connected](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T2.jpg?raw=true "Temperature probes connected")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes connected.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes treated with heat shrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T3.jpg?raw=true "Temperature probes treated with heat shrink")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes treated with heat shrink.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes treated with additional heat shrink to keep everything tindy](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T4.jpg?raw=true "Temperature probes treated with additional heat shrink to keep everything")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes treated with additional heat shrink to keep everything tidy.*

Finally, you will need to bridge the Vcc and Data pin (Vcc and D6 on the Qduino) with a 4.7 kOhm pull-up resisitor. This should be done when you solder everything directly to the Arduino. 

####5.4 Conductivity Sensor

There are a variety of options for conductivity probes, but we recommend using the [Atlas EC EZO circuit](http://www.atlas-scientific.com/product_pages/circuits/ezo_ec.html) to drive these probes. Different conductivity probes will have different configurations. In many cases, there will be more wires than are used. Use a multimeter to trace which wires are actually connected to each electrode. Once you have the electrodes traced, cut the wire to approximately 25cm and set the probe aside for potting. 

The Atlas conductivity circuit needs very little preparation. To help it fit into a tight housing, bend the headers 90 degrees and solder hook-up wires to all contacts except the two probe contacts. The conductivity probe will eventually be attached to these. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Conductivity circuit with bent headers and hook-up wires](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/EC1.jpg?raw=true "Conductivity circuit with bent headers and hook-up wires")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Conductivity circuit with bent headers and hook-up wires.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Conductivity circuit with heat-shrink to protect contacts](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/EC2.jpg?raw=true "Conductivity circuit with heat-shrink to protect contacts")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Conductivity circuit with heat-shrink to protect contacts.*

#### 5.5 Prepare the housing.

Cut a 3" PVC pipe to 25 cm in length.  Don't worry if the tube is label "not for pressure" as the device will be filled with mineral oil or other non-compressable liquids for deep casts. At one end of the pipe drill 4 equidistant holes to allow water flow around the sensors. The center of each hole should be 2.5 cm from the bottom edge.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![2 inch and 3inch OpenCTDs highlighting position of flow-through holes and probes](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/ctds.jpg?raw=true "2 inch and 3 inch OpenCTDs highlighting position of flow-through holes and probes")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*2" and 3" OpenCTDs highlighting position of flow-through holes and probes*

2" pipes should be prepared in the same manner, but will have three equidistant flow-through holes on the bottom. 

####  5.6 Connecting the electronics.

**Note:** Please test all electronics on a breadboard before permanently soldering to the Qduino. 

**Note:** Depending on how tight your OpenCTD housing is, you may want to pot the probes first, and then connect them. 

Create a power bus by soldering the four Vcc wires from each component to a single solid core wire so that they can all be connected to a single Vcc pin. Do the same with ground wires. Cover the connecctions with heat-shrink tubing. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Power bus, without heatshrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/powerbus.jpg?raw=true "Powerbus, without heatshrink")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Power bus, without heatshrink.*

Slot a 4.7 kOhm pullup resistor between Vcc and D46. Feed the Vcc and Ground power buses into their corresponding pinouts. Feed to temperature probe data connection into pin D6. With the pullup resistor, D6 and Vcc may be a tight fit. Solder all three pins. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Vcc, Ground, and D6 with pullup resistor](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/RS.jpg?raw=true "Vcc, Ground, and D6 with pullup resistor")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Vcc, Ground, and D6 with pullup resistor*

Solder the SD card reader and pressure sensor to the Qduino Mini following the [pinout guide](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/README.md#40-arduino-qduino-pinouts). Solder the conductivity probe to the PRB headers on the Atlas circuit, then connect the Atlas circruit to the Qduino Mini following the [pinout guide](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/README.md#40-arduino-qduino-pinouts). 

Depending on the size of the housing and how much wire you used in your build, fitting all of the electronics into the housing may require some creative placement. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![2-inch and 3-inch OpenCTDs, highlighing electronics placement in the housing](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/inside.jpg?raw=true "2-inch and 3-inch OpenCTDs, highlighing electronics placement in the housing")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*2-inch and 3-inch OpenCTDs, highlighing electronics placement in the housing*

#### 5.8 Potting

*__This is the point of no return, after this step, there's no going back!__*

**Note:** Depending on how tight your OpenCTD housing is, you may want to pot the probes first, and then connect them. 

 3D print the [OpenCTD baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/3D_Printer_Files/OpenCTDv4.stl). The outside of the baseplate is the portion of the base plate that will be exposed to the water--this is the side w/o the indentation for the pressure sensor.
 
 Place a small amount of heatshrink tubing to prevent hot glue from coming in contact with the membrane. Affix the pressure sensor to the center indentation in the base plate. Lightly cover the edge of the indentation with hot glue, taking care not to let any come in contact with the membrane. Seat the sensor in the indentation and apply more hot glue (This will provide added protection for this circuit, for deeper operrations of for added security, you can alos use 2-ton marine epoxy to seat the pressure sensor). Trim away to exposed heat shrink and qpply a small amount of electrical tape over the membrane of the pressure sensor to protect it while you work.
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Pressure sensor seated in the baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting1.jpg?raw=true "Pressure sensor seated in baseplate")
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Pressure sensor seated in baseplate.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Pressure sensor with heat shrink extending out through baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting2.jpg?raw=true "Pressure sensor with heat shrink extending out through baseplate")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Pressure sensor with heat shrink extending out through baseplate.*
 
 Place the three temperature sensor into the 3 smaller holes. The waterproofing around these probes is not always uniform. Make sure that some stainless steel is exopsed on the inside surface of the baseplat and than at least 1 cm extends out into the water.
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes extending out through the baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting3.jpg?raw=true "Temperature probes extaneding out through the baseplate")
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes extending out through the baseplate.*
 
 Apply hot glue around the outside of the base plate around each temperature sensor to hold them in place and prevent epoxy from leaking out. Once the hot glue hardens, place the conductivity probe in the only hole big enough for it. Make sure the conductivity probe extends further from the baseplate than the temperature probes (to avoid any interference from these metal probes). Apply hot glue to the outside of the base plate around the conductivity sensor.
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![All probes extending out through the baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting4.jpg?raw=true "All probes extending out through the baseplate")
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*All probes extending out through the baseplate.*
 
 Align the baseplate such that it is lightly recessed into the tube (when standing upright [i.e. sensors facing down], none of the sensors should touch the ground) and that it sits just above the top of each flow-through hole. Hot glue the outside of the baseplate into place along the wall of the PVC tube to ensure the expoy doesn't leak out during potting.
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![Baseplate seated in the housing](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting5.jpg?raw=true "Baseplate seated in the housing")
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Baseplate seated in the housing.*

Once you are satisfied with everything's position, it's time for EFL-90 epoxy. Using the epoxy gun apply the epoxy on the inside of the tube around the sensors. We recommend using an entire cartridge and had almost 2 cm of epoxy on the bottom.  Check periodically to make sure that nothing is leaking out of the bottom. Let it cure overnight.

 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Epoxy potting on the inside of the housing](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting6.jpg?raw=true "Epoxy potting on the inside of the housing")
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Epoxy potting on the inside of the housing.*

### 6.0 Calibration and Data Conversion

Proper calibration of the OpenCTD requires access to already calibrated validation instruments. These can be commercial CTD, handheld systems, or bench-mounted laboratory systems. As the community grows, properly calibrated OpenCTDs can be used to benchmark newly-built instruments. 

#### 6.1 Depth

The pressure sensor outputs absolute pressure, which means that is is self-calibrating. At sea level, pressure should be approximiately 1016 millibars, though local weather and small changes in altitude will affect this baseline. In order to minimize the amount of processing that happens onboard the OpenCTD, pressure is measured in millibars (the default output for the current pressure sensor). To convert pressure to depth use the following equation:

D = (P(depth) - P(surface) * 100) / (g * 1000)

Where D is depth in meters; P(depth) is the pressure (in millibars) at depth); P(surface) is the pressure at the surface in millibars; and g is acceleration due to gravity (9.81 m/s2).

#### 6.2 Temperature

Calibrating the temperature sensors requires access to an already calibrated instrument. Allow both the OpenCTD and the validation instrument to equilibrate in water for 15 minutes. Take the average of the three OpenCTD temperature outputs and note the difference between that average and the validation instrument. Repeat for a fluid that is at least 15 degrees hotter or colder than the test fluid. There should be a linear relationship between the OpenCTD temperature sensors and the validation instrument, which will give you a calibration constant. Take the average of the three temperature readings and use the calibration constant to adjust temperature measurements when processing raw data. 

This should remain steady for many casts, but it is always good practice to check you temperature calibration whenever you have access to a validation instrument. We recommend recalibrating temperature at the beginning of each expedition and once a month for prolonged deployments. 

#### 6.3 Conductivity

Calibration of the coductivity meter requires a calibration standard--a bottle of water of precise, known salinity. Calibration is done through software and is explained in detail [here](http://www.atlas-scientific.com/_files/_datasheets/_circuit/EC_EZO_Datasheet.pdf). You can perform either a one or two solution calibration depending on how many standards you have access to. 

To increase the ease of calibration, we [have created a small program for accessing the serial monitor](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/simple_serial_for_EC_calibration). Flash this simple serial program to your Qduino Mini. 

Open the serial monitor through the Arduino IDE. You should see a stream of unprecessed data. 

- Enter **c,0** into the command line and hit enter. This will turn off continuous monitorring.
- Enter **k,?** this will tell you what the K-value of you probe is set to. It should ke set to K=1.0 for most use cases. 
  - To change the K-value, enter **k,x** where **x** is the new K-value of the probe. 
- With the probe dry (be sure there is abosolutely no water on the electrodes) enter **cal,dry**. This with dry calibrate the probe. 
- For 1-point calibration, suspend the probe in calibration solution. Enter **cal,one,y**, where **y** is the known value of the standard. 
- For two point calibration, suspend the probe in the less conductive solution and enter **cal,low,y**, where **y** is the known value of the standard. Then suspend in the more conductive solution and enter **cal,high,z**, where **z** is the known value of the solution. 
- Now enter **c,1** to turn continuous monitorring back on. 

Don't forget to reflash the [OpenCTD software](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/OpenCTD_qDuino) to the Qduino Mini after calibration is done. Conductivity should be recalibrated at least once per year. 

### 7.0 Your first cast. 

Power up the OpenCTD with your battery pack of choice (you'll want the full 12v). Confirm that it is writing data to the SD card. 

Now for the fun part. 

While everything is powered on, fill it with mineral oil. Mineral oil is non conductive and won't interfere with the electronics. Fill it top a few centimeters below the top. There will be some spillover if you're trying to avoid bubbles in the housing. Gentle lower the test cap down and screw it into place. You CTD is now sealed and logging. Wipe down any spilled oil. I find that these [microfiber cloths from Amazon](http://amzn.to/1RLdKZd) do a great job of sopping up small oil spills. It's a good idea to have them with you as you want to minimize any oil release into the water. 

Your OpenCTD is now ready to take the plunge!

### 8.0 Resources

[Oceanography for Everyone](http://oceanographyforeveryone.com/)

[Original Project Description](https://www.rockethub.com/projects/26388-oceanography-for-everyone-the-openctd)

### 9.0 Acknowledgments

This software has been kludged together by Andrew Thaler, based on code from Walt Holm, arduino.cc samples, Atlas scientific, Vhati, and Russell Neches. OpenCTD was designed by Andrew Thaler, Kersey Sturdivant, and Russell Neches. 

### 10.0 Code of Conduct

Please review our [Contributor Code of Conduct](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/CODE_OF_CONDUCT.md) prior to your first contribution. 

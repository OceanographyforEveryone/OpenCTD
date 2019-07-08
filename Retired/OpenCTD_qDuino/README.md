OpenCTD Introduction and Build Guide
=======

*__Updated 9/25/2017__*

### 1.0 Overview

**Conductivity, temperature, and depth (CTD).**  These three measurements allow scientists to unlock ocean patterns hidden beneath the sea's surface. The ocean is not uniform, it its filled with swirling eddies, temperature boundaries, layers of high and low salinity, changing densities, and other physical characteristics invisible to an observer floating upon its surface. To reveal these patterns oceanographers employ the CTD--an oceanographic instrument that, at its core, measures temperature, salinity, and depth for a water column. The CTD is the workhorse of oceanographic research. 

CTDs are expensive, and that expense can is a barrier-to-entry for formal and informal researchers with limited budgets, scientists from developing nations, citizen oceanographers, and students of all levels interested in learning more about their local coasts and waterways. 

The OpenCTD is a low-cost, open-source CTD suitable for both educators and researchers. The platform is built using reasonably accessible parts and is powered by an Arduino-based microcontroller. Source codes and building instructions are freely available. The device, sufficiently accurate for scientific research, can be constructed for approximately $300, and is effective to 100 meters depth.

Why 100 meters? For many coastal regions, 100 meters depth covers the majority of the ocean that is accessible by small boat and generally the average depth of the outer continental shelf. The OpenCTD is targeted to people working in this niche, where entire research projects can be conducted for less than the cost of a commercial CTD. The OpenCTD is scalable and someone with the inclination and expertise can adapt an OpenCTD to operate in deeper waters.

*__If you build an OpenCTD please let the [team at Oceanography For Everyone](http://oceanographyforeveryone.com/#meetAnchor) know. We love to keep up with the community of people building and using these devices. During your build session, or while using an OpenCTD or other [Oceanography for Everyone](http://oceanographyforeveryone.com/) tools, please consider tweeting using the [#HackTheOcean](https://twitter.com/hashtag/HackTheOcean?src=hash) hashtag so the community can follow your efforts!__*

#### 1.1 Skills Needed

Building an OpenCTD requires some basic soldering and coding knowledge but it is also a great opportunity to learn those skills. With an hour or two of practice, you can develop the soldering skills needed to build an OpenCTD. [This descriptive, illustrative comic from Mighty Ohm](http://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf) presents soldering fundamentals in an accesible and approachable format.

Andrew has used this [MightyOhn Geiger Counter Kit](http://mightyohm.com/blog/products/geiger-counter/) and this [Mega Menorah 9000 Soldering Kit](http://shop.evilmadscientist.com/productsmenu/756) to teach soldering and basic electronic principles to students from ages 10 to 65. 

Arduino is a relatively intuitive coding environment, but it can still seem daunting to first-time users. Practically, we have already created the code you will need to run the OpenCTD, but it is extremely beneficial, particularly for end users, to understand what the software is doing. The book [Environmental Monitoring with Arduino: Building Simple Devices to Collect Data About the World Around Us](http://amzn.to/2xB15Xi) is short, easy to understand, and will provide you with some ideas for expanding your inventory of open-source environmental sensors. 

### 2.0 Project Status

The OpenCTD is stable on the Qduino Mini platform with comprehensive build instructions provided and a growing user community. We have validated the OpenCTD against commercial CTDs and are confident in the quality of the data. Users around the world are building and testing their own units and helping with instrument validation.  

#### 2.1 Field Trials

As we test and refine the design of the OpenCTD, critical field trials with essential data for assessing the quality, accuracy, and durability of the device are archived in the [Field_Trials](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials) repository.

+ **_Lake Superior, R/V Blue Heron_:** Initial field trials were completed in October of 2015 and analysis of the data from the first several casts confirms the accuracy of OpenCTD at it was cast against a commercial CTD. Additionaly, OpenCTD was successfully deployed to a depth of 140 meters. All data and field notes from the first Field Trial can be found in the [Blue Heron 15-11](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/Blue_Heron_2015-11) repository.

+ **_Gloucester Point, VA, Hurricane Hermine_:** Hurricane Hermine is a tropical cyclone that passed over our field site in coastal Virginia on September 4, 2016. To test the longevity of the batteries and the durability of the OpenCTD during long term deployments, Andrew placed two units in our Test Ditch (a tidally influence drainage ditch connected to the Mobjack Bay estuary), where they remained for 74 hours. Notes and data files can be found in the [HermineDeployment_9-2016](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/HermineDeployment_9-2016) respository.

### 3.0 Bill of Materials

We try to source as many parts as possible from accesible distibutors. **_NOTE: As Amazon is in the process of phasing out its aStore program, the Parts Depot is no longer being maintained. Please consult the below list for the most recent part recommendations._** Many components can also be purchased directly through the supplier, found on AliExpress, or sourced through auction sites for significantly less. Quality across suppliers for most parts has been generally consistent, though we have noticed a defect rate of about 10% with the sealed temperature sensors. 

**Please be aware: Part availability varies from month to month, and some components may become permanently unavailble or listed under a new manufacturer and product name. We do our best to keep the bill of material up to date, If you find any discrepancies, please email us.**

**Recommended Components**

Part	| Suplier	| Price	| Link	
---|---|---|---
Qduino Mini |	Sparkfun/Amazon	| $29.95	| https://www.sparkfun.com/products/13614	/ http://amzn.to/2wS8YUp
SD Card Reader Module	|  Amazon	| $5.66	| http://amzn.to/2jXSNnv 	
3.7V 2000mAh LiPo	| Amazon	| $14.98	| http://amzn.to/2y3nDRQ						
Conductivity K 1.0 Kit |	Atlas Scientific  |	$195.71	| https://www.atlas-scientific.com/product_pages/kits/ec_k1_0_kit.html	
DS18B20 Temperature Sensor | Amazon | $9.88 |	http://amzn.to/2yoBUo6				
MS5803-14BA	|	Mouser	| $22.85	| http://www.mouser.com/ProductDetail/Measurement-Specialties/MS580314BA01-00
SOIC to DIP Adapter	|	Sparkfun	| $2.95	| https://www.sparkfun.com/products/13655
0.1uF Capacitor	| Amazon	| $4.79	| http://amzn.to/2humBn9
10k Ohm Resistor	|	Amazon	| $4.19	| http://amzn.to/2yoCjqC	
4.7kOhm Resistor | Amazon	| $6.16	| http://amzn.to/2fMfmHe					
Hook-up wire	|	Amazon	| $22.00	| http://amzn.to/2hu54eJ	
Heat shrink tubing |	Amazon	| $5.99	|http://amzn.to/2wRQtPO	
2" Gripper Plug | Amazon | $9.41 | http://amzn.to/2jWVjdz

**Alternate Components**

Part	| Suplier	| Price	| Link	
---|---|---|---
MicroSD Card Read Module	|  Amazon	| $9.49	| http://amzn.to/2y4nSvS
Pressure Sensor Breakout - MS5803-14BA | SparkFun | $59.95 | https://www.sparkfun.com/products/12909
3" Gripper Plug | Amazon | $4.99 | http://amzn.to/2wS9qlC

**Some parts, such as resistors and capacitors, are very cheap but hard to source individually. We have tried to find the smallest lots that aren't excessively overpriced, but you may have better luck finding cheaper options, especially "intro to electronics"-type kits, which include many standard resistors and capacitors in small lots.** 

Additional components, like a pre-fabricated [pressure sensor module](https://www.sparkfun.com/products/12909), [LiPo batteries](https://www.sparkfun.com/products/8483), [SMD boards](https://www.sparkfun.com/products/13655), and the [qDuino Mini](https://www.sparkfun.com/products/13614) can be found at Sparkfun. The MS5803-14BA pressure sensor previously needed to be special ordered from a parts supplier, but [SparkFun](https://www.sparkfun.com/products/12909) has a (much more expensive) commercial 14-bar unit using the same sensor. 

Servoflo sells the raw, calibrated pressure sensor in both [14Bar](http://www.servoflo.com/download-archive/data-sheets/220-calibrated-digital-sensor-modules/614-ms5803-14ba) and [30Bar](http://www.servoflo.com/download-archive/data-sheets/220-calibrated-digital-sensor-modules/613-ms5803-30ba) modules. These are surface mounted sensors and require significant soldering skills to mount properly. Detailed descriptions of the differeces and benefits between the two pressure sensors is discussed in section 5.2. Mouser now sells individual MS5803-14BA sensor modules for a reasonable cost.

PVC pipe can be found at most home supply stores. If you want to get fancy, a [clear acrylic tube](http://amzn.to/2njFhqw) can add some flare to your build. Though the first OpenCTDs were built using 3" PVC pipe, we now recommend using 2" pipe for a more durable, compact device.

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
- coffee maker (because coffee)

#### 3.2 Consumables
- sand paper
- Hysol E90-FL epoxy
- venturi mixing nozzles for epoxy
- solder
- desoldering braid
- electical tape
- hot glue
- mineral oil
- calibration standard for conductivity
- coffee

#### 3.3 3D printed parts
Several useful parts that will significantly improve the build process are 3D printable: [3D Printer Files](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/3D_Printer_Files). While 3D printing allows rapid fabricating of small custom parts for very low cost, we recognize that access to a 3D printer is not universal. The OpenCTD can be entirely constructed without 3D printed parts. The sensor plate can be fabricated from cardboard if necessary (its purpose is to hold the sensors in place while the expoxy cures, once the epoxy is set, the plate serves no further function). The wire jig helps keep everything organized but is not necessary. The Jaunty CTD Cap is funny, but not particularly useful. If you would like to build an OpenCTD but do not have access to a 3D printer, please contact either Andrew or Russell and we will print the parts for you. If you're on [Thingiverse](https://www.thingiverse.com/), please Like, Collect, or Make our designs to help boost our profile in the 3D-printing community. 

+ [OpenCTD sensor template](https://www.thingiverse.com/thing:1641934)
+ [OpenCTD hardware frame and wire guide](https://www.thingiverse.com/thing:2500591)
+ [Jaunty Red Cap for the OpenCTD](https://www.thingiverse.com/thing:2470929)

#### 3.4 Required Arduino Libraries
+ Included with Arduino IDE:
  - [**SPI.**](https://www.arduino.cc/en/Reference/SPI) Serial Peripheral Interface for communicating with a standard SD card reader.
  - [**SoftwareSerial.**](https://www.arduino.cc/en/Reference/SoftwareSerial) For communicating with serial devices like the conductivity circuit.
  - [**Wire.**](https://www.arduino.cc/en/Reference/Wire) For communicating with I2C devices like the pressure sensor. 
+ Need to download and install ([How to install Arduino libraries](https://www.arduino.cc/en/Guide/Libraries)):
  + [**SD.**](https://www.arduino.cc/en/Reference/SD) For reading and writing to a standard SD card reader.
  + [**SparkFun_MS5803_I2C.**](https://github.com/sparkfun/SparkFun_MS5803-14BA_Breakout_Arduino_Library/tree/V_1.1.0) For the MS5803 14 Bar pressure sensor (*__Note__: if you decide to use a different pressure sensor, you will need to update this library*)
  + [**Dallas Temperature Control.**](https://milesburton.com/Dallas_Temperature_Control_Library) Allows you to communicate with the DS18B20 thermistor. 
  + [**OneWire.**](http://www.pjrc.com/teensy/td_libs_OneWire.html) For controlling the Dallas 1-wire family of devices. 

#### 3.5 Other Useful Software

+ [**Qduino.h and Qduino fuelGauge**](https://github.com/sparkfun/Arduino_Boards/tree/master/sparkfun/avr/libraries/Qduino) allows you to measure the charge on you battery. 
+ [**simple_serial_for_EC_calibration**](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Support_Code/simple_serial_for_EC_calibration) is a basic serial monitor program to help you calibrate the conductivity probe. 
+ [**TempProbeTester**](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Support_Code/TempProbeTester) allows you to test up to 26 temperature probes simultaneously and is useful for quality control and temperature calibrations. 
+ [**MS5803_14_test**](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Support_Code/MS5803_14_test) For testing the pressure sensor prior to installation. 

### 4.0 Arduino Qduino Pinouts

- **SD Card Reader:** CS (D4), SCK (D15), MOSI (D16), MISO (D14*)
- **Pressure Sensor:** SDA (D2), SCL (D3)
- **Temperature Sensors:** Data (D6)
- **Conductivity Circuit:** TX (D8), RX (D9)

\*older Qduinos may have this labeled D17

**It is possible to use other Arduino-based single board computers, but please check the pinouts and schematics. Different Arduino boards may use various pins for internal functions which can interfere with signals to and from the sensors (for example, using this pinout on an Arduino Uno will result in failed conductivity readings).**

### 5.0 Build Instructions

*We are continously updating and improving OpenCTD prototypes. These instuctions are subject to change. Please read through the entire guide before you make any irreversible changes to the hardware. Most manufacturers will consider the warranty void once you begin soldering.*

**Important note about power consumption:** All sourced modules are rated to work at 3.3V, however, when two or more are running simultaneously, the 3.3V output on most Arduinos yield inconsistent results and the SD card reader may not function at all. We recommend powering the entire system with a minimum of 3.7V. On standard Arduino's, the 5V output should be used. On the Qduino Mini, VCC with a 3.7V battery is sufficient. **_You can save yourself a lot of headache if you make sure the LiPo battery is fully charged and leave it connected to the Qduino Mini throughout the build._**

**_We strongly encourage you to test all the components one by one on a breadboard before soldering modules together. If you're planning to build multiple CTDs, we recommend that you use a dedicated Qduino, with header pins, for breadboard testing._**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![A complete OpenCTD system mounted to a breadboard for testing before soldering and potting](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/BB.jpg?raw=true "A complete OpenCTD system mounted to a breadboard for testing before soldering and potting")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*A complete OpenCTD system mounted to a breadboard for testing before soldering and potting.*

Before you begin, set up you Qduino Mini following this [helpful quickstart guide from Qtechknow](https://www.hackster.io/team-qtechknow/qduino-mini-quickstart-guide-8b2d68) and flash the [OpenCTD software](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/OpenCTD_qDuino) to your Qduino Mini so that you can test each component during the build.

#### 5.1 SD Card Reader

The [SD card reader](http://amzn.to/2xEPbM9) we recommend is a 'plug and play' module. Connect each pin following the pinout guide above. For fitting into a tight housing, you may want to bend each header pin 90 degrees (using needle-nosed pliers) or remove the headers completely. Hookup wires should be at least 60 mm long, though you may eventually shorten them to suit your preference. For SD card readers with two sets of pins, bend the 6 pins you need 90 degrees and snip the others flush with the board. Make sure you're connecting to the 3.3V terminal, not the 5V terminal. 

To prepare the SD card, format the card and create a single, empty text file called **datalog.txt**.

#### 5.2 Pressure Sensor

There are several options and configurations for the pressure sensor, all of which rely on the MS5803-14BA sensor module. The simplest solution is a prefabricated model that requires no additional modificaion, just solder headers or connectors to Gound, Vin, SCL, and SDA and connect to the Qduino (we strongly recommend this option for people who do not have extensive experience with surface mounted soldering). 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Three possible pressure modules.](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS1.jpg?raw=true "Three possible pressure modules")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Three possible pressure modules.*

Other solutions require a small 100nF (104) capacitor and 10kOhm pull-up resistor. The resistor bridges pin 3 and 6 on the pressure module. The capacitor bridges pins 2 and 5. SCLK is pin 1, Ground is pin 2, VCC in pin 5, and SDI/SDA is pin 7. Pins 5 and 6 need to be bridged with a jumper wire. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Layout for pressure module](https://edwardmallon.files.wordpress.com/2014/03/pressure-sensor-wiring.jpg?w=640 "Layout for pressure module")


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Layout for pressure module. From [The Cave Pearl Project](https://edwardmallon.wordpress.com/2014/03/27/adding-a-ms5803-02-high-resolution-pressure-sensor/).*


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Back view of one DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS2.jpg?raw=true "Back view of one DIYpressure module")


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Back view of one DIY pressure module.*


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Front view of a small DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS3.jpg?raw=true "Front view of a small DIY pressure module")


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Front view of a small DIY pressure module.*


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Back view of the same DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS4.jpg?raw=true "Back view of the same DIY pressure module")


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Back view of the same DIY pressure module.*


Hookup wires for the pressure sensor should be about 5 cm longer than the length of pipe used for the housing. You may end up shortening these depending on your preference. The [MS5803_14_test](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Support_Code/MS5803_14_test) code can be used to test the pressure sensor after assembly.

#### 5.3 Temperature Sensors

The temperature probes use an off-the-shelf DS18B20 digital thermistor in a stainless steel housing. We use a battery of 3 probes averaged together for more consistent readings. The OneWire protocol allows mutliple probes to be queried on the same pin, so all three probes feed into a single data pin. With these low-cost thermistors, we've found the failure rate to be about 10% out of the box. It's worth testing each thermistor on a breadboard before proceeding to save yourself frustration down the line. To prepare the probes, cut the wire length to 30 cm. Solder three data strands, three power strands, and three ground strands together and attach a single solid core wire to each. 

We recommend sealing each solder joint with waterproof heat shrink tubing for increased reliability and to protect connections in the event of a flooded housing. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Three temperature probes prepped for soldering](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T1.jpg?raw=true "Three termperature probes prepped for soldering")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Three temperature probes prepped for soldering.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes connected](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T2.jpg?raw=true "Temperature probes connected")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes connected.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes treated with heat shrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T3.jpg?raw=true "Temperature probes treated with heat shrink")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes treated with heat shrink.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes treated with additional heat shrink to keep everything tindy](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T4.jpg?raw=true "Temperature probes treated with additional heat shrink.")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes treated with additional heat shrink.*

Finally, you will need to bridge the Vcc and Data pin (Vcc and D6 on the Qduino) with a 4.7 kOhm pull-up resisitor. This should be done when you solder everything directly to the Arduino. 

#### 5.4 Conductivity Sensor

There are a variety of options for conductivity probes, but we recommend using the [Atlas EC EZO circuit](http://www.atlas-scientific.com/product_pages/circuits/ezo_ec.html) to drive these probes. Different conductivity probes will have different configurations. In many cases, there will be more wires than are used. Use a multimeter to trace which wires are actually connected to each electrode. Once you have the electrodes traced, cut the wire to approximately 25cm and set the probe aside for potting. 

The Atlas conductivity circuit needs very little preparation. Solder hook-up wires to all contacts except the two probe contacts. The conductivity probe will eventually be attached to these. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Conductivity circuit with heat-shrink to protect contacts](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/EC2.jpg?raw=true "Conductivity circuit with heat-shrink to protect contacts")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Conductivity circuit with heat-shrink to protect contacts.*

#### 5.5 Prepare the housing.

Cut a 2" PVC pipe to 25 cm in length. At one end of the pipe drill 2 equidistant holes to allow water flow around the sensors. The center of each hole should be 2.5 cm from the bottom edge. The position of the holes does not need to be precise, and you can get creative with their placement, provided you leave enough room for the sensor plate to sit above the holes. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![2 inch and 3inch OpenCTDs highlighting position of flow-through holes and probes](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/ctds.jpg?raw=true "2 inch and 3 inch OpenCTDs highlighting position of flow-through holes and probes")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*2" and 3" OpenCTDs highlighting position of flow-through holes and probes* 

####  5.6 Connecting the electronics.

The 3D printed hardware frame and wire guide will make it easier to produce a nice, clean, easy to access brain for your open CTD. Each space is designed to hold one of the three PCB components, with the SD card reader located at the top, the qDuino mini in the middle, and the conductivity circuit on the bottom. The d-loop allows for wire routing using zipties to lock wire in place and take strain off of solder joints. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![OpenCTD hardware frame and wire guide.](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/wireguide.jpg?raw=true "OpenCTD hardware frame and wire guide.")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*OpenCTD hardware frame and wire guide.*

**Note:** Please test all electronics on a breadboard before permanently soldering to the Qduino. 

**Note:** Depending on how tight your OpenCTD housing is, you may want to pot the probes first, and then connect them. 

Create a power bus by soldering the four Vcc wires from each component to a single solid core wire so that they can all be connected to a single Vcc pin. Do the same with ground wires. Cover the connections with heat-shrink tubing. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Power bus, without heatshrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/powerbus.jpg?raw=true "Powerbus, without heatshrink")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Power bus, without heatshrink.*

Slot a 4.7 kOhm pullup resistor between Vcc and D6. Feed the Vcc and Ground power buses into their corresponding pinouts. Feed to temperature probe data connection into pin D6. With the pullup resistor, D6 and Vcc may be a tight fit. Solder all three pins. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Vcc, Ground, and D6 with pullup resistor](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/RS.jpg?raw=true "Vcc, Ground, and D6 with pullup resistor")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Vcc, Ground, and D6 with pullup resistor*

Solder the SD card reader and pressure sensor to the Qduino Mini following the [pinout guide](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/README.md#40-arduino-qduino-pinouts). Solder the conductivity probe to the PRB headers on the Atlas circuit, then connect the Atlas circruit to the Qduino Mini following the [pinout guide](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/README.md#40-arduino-qduino-pinouts). 

Depending on the size of the housing and how much wire you used in your build, fitting all of the electronics into the housing may require some creative placement. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![2-inch and 3-inch OpenCTDs, highlighing electronics placement in the housing](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/inside.jpg?raw=true "2-inch and 3-inch OpenCTDs, highlighing electronics placement in the housing")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*2-inch and 3-inch OpenCTDs, highlighing electronics placement in the housing*

#### 5.8 Potting

*__This is the point of no return, after this step, there's no going back!__*

**Note:** Depending on how tight your OpenCTD housing is, you may want to pot the probes first, and then connect them. 

3D print the [OpenCTD baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/3D_Printer_Files/OpenCTD_2in.stl). The outside of the baseplate is the portion of the base plate that will be exposed to the water--this is the side w/o the indentation for the pressure sensor.
 
Place a small amount of heatshrink tubing on the pressure sensor to prevent epoxy from coming in contact with the membrane. Affix the pressure sensor to the center indentation in the base plate. Lightly cover the edge of the indentation with 2-ton epoxy, taking care not to let any come in contact with the membrane. Seat the sensor in the indentation and apply more epoxy (This will provide added protection for this circuit). Let the epoxy cure for 20 minutes. Trim away the exposed heat shrink taking care not to damage the pressure sensor. **Optional: Apply a small amount of electrical tape over the membrane of the pressure sensor to protect it while you work.**
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Pressure sensor seated in the baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting1.jpg?raw=true "Pressure sensor seated in baseplate")
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Pressure sensor seated in baseplate.*

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Pressure sensor with heat shrink extending out through baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting2.jpg?raw=true "Pressure sensor with heat shrink extending out through baseplate")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Pressure sensor with heat shrink extending out through baseplate.*
 
Place the three temperature sensors into the 3 small holes. The waterproofing around these probes is not always uniform. Make sure that some stainless steel is exposed on the inside surface of the baseplate and than at least 1 cm extends out into the water.
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Temperature probes extending out through the baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting3.jpg?raw=true "Temperature probes extaneding out through the baseplate")
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Temperature probes extending out through the baseplate.*
 
Apply hot glue around the inside of the base plate around each temperature sensor to hold them in place and prevent epoxy from leaking out. Once the hot glue hardens, place the conductivity probe in the only hole big enough for it. Make sure the conductivity probe extends further from the baseplate than the temperature probes (to avoid any interference from these metal probes). Apply hot glue to the inside of the base plate around the conductivity sensor.
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![All probes extending out through the baseplate](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting4.jpg?raw=true "All probes extending out through the baseplate")
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*All probes extending out through the baseplate.*
 
Align the baseplate such that it is lightly recessed into the tube (when standing upright [i.e. sensors facing down], none of the sensors should touch the ground) and that it sits just above the top of each flow-through hole. Remove the baseplate and apply hot glue around the edges of the plate. Quickly and carefully slide the plate back into the PVC pie while slowly rotating it. This will create a tight seal to prevent epoxy from leaking out.
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![Baseplate seated in the housing](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting5.jpg?raw=true "Baseplate seated in the housing")
 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Baseplate seated in the housing.*

Once you are satisfied with everything's position, it's time for EFL-90 epoxy. Using the epoxy gun apply the epoxy on the inside of the tube around the sensors. We recommend using an entire cartridge.  Check periodically to make sure that nothing is leaking out of the bottom. Let it cure overnight.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Epoxy potting on the inside of the housing](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/potting6.jpg?raw=true "Epoxy potting on the inside of the housing")
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Epoxy potting on the inside of the housing.*

### 6.0 Calibration and Data Conversion

Proper calibration of the OpenCTD requires access to already calibrated validation instruments. These can be commercial CTD, handheld systems, or bench-mounted laboratory systems. As the community grows, properly calibrated OpenCTDs can be used to benchmark newly-built instruments. 

#### 6.1 Depth

The pressure sensor outputs absolute pressure, which means that it is self-calibrating. At sea level, pressure should be approximiately 1016 millibars, though local weather and small changes in altitude will affect this baseline. In order to minimize the amount of processing that happens onboard the OpenCTD, pressure is measured in millibars (the default output for the current pressure sensor). To convert pressure to depth use the following equation:

D = (P(depth) - P(surface) * 100) / (g * 1000)

Where D is depth in meters; P(depth) is the pressure (in millibars) at depth); P(surface) is the pressure at the surface in millibars; and g is acceleration due to gravity (9.81 m/s^2).

#### 6.2 Temperature

The Cave Pearl Project has provided an excellent guide to thorough temperature sensor calibration: [DS18B20 Calibration: Finally nailed it!](https://edwardmallon.wordpress.com/2016/03/05/ds18b20-calibration-we-finally-nailed-it/). This process may be overkill for most users, but anyone intending to produce replicatable, peer-review ready results should put in the extra time for a comprehensive calibration. 

Calibrating the temperature sensors requires access to an already calibrated instrument. Allow both the OpenCTD and the validation instrument to equilibrate in water for 15 minutes. Take the average of the three OpenCTD temperature outputs and note the difference between that average and the validation instrument. Repeat for a fluid that is at least 15 degrees hotter or colder than the test fluid. There should be a linear relationship between the OpenCTD temperature sensors and the validation instrument, which will give you a calibration constant. Take the average of the three temperature readings and use the calibration constant to adjust temperature measurements when processing raw data. 

This should remain steady for many casts, but it is always good practice to check you temperature calibration whenever you have access to a validation instrument. We recommend recalibrating temperature at the beginning of each expedition and once a month for prolonged deployments. 

#### 6.3 Conductivity

Calibration of the coductivity meter requires a calibration standard--a bottle of water of precise, known salinity. Calibration is done through software and is explained in detail [here](http://www.atlas-scientific.com/_files/_datasheets/_circuit/EC_EZO_Datasheet.pdf). You can perform either a one or two solution calibration depending on how many standards you have access to. 

To increase the ease of calibration, we [have created a small program for accessing the serial monitor](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/simple_serial_for_EC_calibration). Flash this simple serial program to your Qduino Mini. 

Open the serial monitor through the Arduino IDE. You should see a stream of unprecessed data. 

- Enter **c,0** into the command line and hit enter. This will turn off continuous monitorring.
- Enter **k,?** this will tell you what the K-value of you probe is set to. It should ke set to K=1.0 for most use cases. 
  - To change the K-value, enter **k,x** where **x** is the new K-value of the probe. 
- With the probe dry (be sure there is abosolutely no water on the electrodes) enter **cal,dry**. This will dry calibrate the probe. 
- For 1-point calibration, suspend the probe in calibration solution. Enter **cal,one,y**, where **y** is the known value of the standard. 
- For two point calibration, suspend the probe in the less conductive solution and enter **cal,low,y**, where **y** is the known value of the standard. Then suspend in the more conductive solution and enter **cal,high,z**, where **z** is the known value of the solution. 
- Now enter **c,1** to turn continuous monitorring back on. 

Don't forget to reflash the [OpenCTD software](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/OpenCTD_qDuino) to the Qduino Mini after calibration is done. Conductivity should be recalibrated at least once per year. 

Converting conductivity to PSU is a complex equation that is temperature dependent. This [UNESCO paper](http://unesdoc.unesco.org/images/0005/000598/059832eb.pdf) outlines the basic equations. We are working on an Excel template that will perform those conversions for you. The [OpenCTD_DataConversion_Template](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Data_Processing/OpenCTD_DataConversion_Template.xlsx) will take raw data from the OpenCTD and make these conversions for you. 

### 7.0 Your first cast. 

This is the fun part. 

For shallow deployments (<100 m), the test cap will keep water out. For deeper deployments (<100 m), pressure compensate the housing with mineral oil or similarly no-conductive fluid. 

**No Mineral Oil:** Ensure that the inside surface of the PVC pipe is clean and free of debris. Hairs can be particularly difficult to see. Seat the test cap onto the housing and tighten the wingnut. Wingnut should be as tigh as possible without tool assistance and the cap should not move or turn. 

**Mineral Oil:** Fill to a few centimeters below the top. There may be some spillover to avoid bubbles in the housing. Turn on the CTD. Gently lower the test cap down and screw it into place. It should be tight enought that it cannot be removed without unscrewing. Your CTD is now sealed and logging. Wipe down any spilled oil. These [microfiber cloths from Amazon](http://amzn.to/2xAVyjg) do a great job of sopping up small amounts of mineral oil. 

Your OpenCTD is now ready to take the plunge! Gently lower into the water and descend no more than 1 meter per second. The slower the better. For the first cast, descend to 5 meters, then recover and check that no leakage has occured. With mineral oil, it will be very clear if the device is leaking. Once it passes the first soak test, you're ready to go forth and collect ocean data. 

Welcome to the Oceanography for Everyone community!

### 8.0 Resources

[Oceanography for Everyone](http://oceanographyforeveryone.com/)

### 9.0 Partners and Projects

If you are building you're own OpenCTD or have recieved one of ours, please add yourself to the following list. 

Partner | Affiliation | Project | Location | Link | Other Contact Info
---|---|---|---|---|---
Ian Black | Oregon State University | CTDizzle |USA | http://blogs.oregonstate.edu/ianblack/ | [@Ian_CTDizzle](https://twitter.com/Ian_CTDizzle)
Jonny Teague | University of Bristol | | England | |[@jonny_teague](https://twitter.com/jonny_teague)  
Steve Haan | | PiCTD | | | [@HaanHouse](https://twitter.com/HaanHouse)

### 10.0 Acknowledgments

This software has been compiled by [Andrew Thaler](https://github.com/SouthernFriedScientist), based on code from Walt Holm, arduino.cc samples, Atlas Scientific, [Vhati](https://github.com/Vhati), and [Russell Neches](https://github.com/orgs/OceanographyforEveryone/people/ryneches). OpenCTD was initially designed by Andrew Thaler, [Kersey Sturdivant](https://github.com/goldsphininx), and Russell Neches. 

### 11.0 Code of Conduct

Please review our [Contributor Code of Conduct](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/CODE_OF_CONDUCT.md) prior to your first contribution. 

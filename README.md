OpenCTD
=======

### 1.0 Overview

**Conductivity, temperature, and depth (CTD).**  These three measurements allow scientists to unlock ocean patterns hidden beneath the sea's surface. The ocean is not uniform, it its filled with swirling eddies, temperature boundaries, layers of high and low salinity, changing densities, and other physical characteristics invisible to an observer floating upon its surface. To reveal these patterns in, oceanographers employ a CTD--an oceanographic instument that, at its core, measures temeprature, salinity, and depth down a water column. The CTD is the workhorse of oceanographic research. 

CTDs are expensive, and that expense can act as a barrier-to-entry for researchers with limited budgets, scientists from developing nations, citizen oceanographers, and students of all levels interested in learning more about their local coasts and waterways. 

The OpenCTD is a low-cost, open-source CTD suitable for both educators and scientists. The platform is built using reasonably accessible parts and is powered by an Arduino-based microcontroller. Source codes and building instructions are freely available. The device sufficeintly accurate for scientific research, can be constructed for approximately $300, and is effective to 200 meters depth.

Why 200 meters? For many coastal regions, 200 meters of water depth covers the majority of the ocean that is accessible by small boat and generally the maximum depth of the continental shelf. The OpenCTD is targeted to people working in this niche, where entire research projects can be conducted for less than the cost of a commercial CTD. The OpenCTD is scalable, and someone with the inclination and expertise can adapt an OpenCTD to operate in deeper waters.

*__If you build an OpenCTD please let the [team at Oceanography For Everyone](http://oceanographyforeveryone.com/#meetAnchor) know. We love to keep up with the community of people using these devices. During your build session, or while using an OpenCTD or other {Oceanography for Everyone}(http://oceanographyforeveryone.com/) tool, tweet [#HackTheOcean](https://twitter.com/hashtag/HackTheOcean?src=hash) so the community can follow your efforts!__*

#### 1.1 Necessary Skills

Building an OpenCTD does require some basic knowledge in soldering and coding. However, for those with backgrounds in neither, honing those skills are relatively easy and not at all time intensive. Developing basic soldering skills necessary to construct an OpenCTD should take only an hour. We have found this descriptive, illustrative comic at [Mighty Ohm] (http://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf) should provide you with the soldering skills you need in an easily digestible manner. 

The next important skill is understanding a bit of coding so you can build the Arduino libraries. You DO NOT need to be a master coder, but just have a perfunctory understanding of how the Arduino libraries work so you can upload/apply them properly. Learning Arduino coding should take you another hour, and is succulently explained at:

### 2.0 Project Status

After success during our initial field trials in Lake Superior (see *Field Trials* section), and progress with conductivity sensor development, we are finalizing the design of OpenCTD during the Hack the Ocean conference in June 2016. During this build effort we will produce 3 sondes (1 to send to our early crowd fund donor, and 2 for field use), developing a detailed instruction guide, and creating video instructions to go along with the guide.

From June 18 to 21, Andrew Thaler and Kersey Sturdivant conducted a marathon prototyping session to produce additional OpenCTDs and streamline the software and hardware. Updates from this event will be available soon. 

#### 2.1 Field Trials

Initial field trials were completed in October of 2015 and analysis of the data from the first several casts confirms the accuracy of OpenCTD. All data and field notes from the first Field Trial can be found in the [Blue Heron 15-11](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/Blue_Heron_2015-11) repo.

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
- helping hands soldering station (critical soldering component)
- expoy gun
- needle nose pliers
- volt meter
- utility knife
- hot glue gun
- heat gun
- 
- saw
- drill
- 1" bit (for holes in PVC)
- laptop
- micro-USB cable
- coffe maker (because... coffe, duh) 

#### 3.2 Consumables

- sand paper
- Hysol 90 epoxy
- ventury tubes for epoxy
- solid core wiring
- solder
- desoldering braid
- heat shrink tubing
- electical tape
- hot glue
- mineral oil
- conductivity calibration constant
- coffee

#### 3.3 Required Arduino Libraries

+ [SparkFun_MS5803_I2C for the pressure sensor.](https://github.com/sparkfun/SparkFun_MS5803-14BA_Breakout_Arduino_Library/tree/V_1.1.0)

+ [Dallas Temperature Control for the DS18B20 thermometer.](https://milesburton.com/Dallas_Temperature_Control_Library)

+ [OneWire.] (http://www.pjrc.com/teensy/td_libs_OneWire.html) [Reference.](http://playground.arduino.cc/Learning/OneWire)

+ [SD.] (https://www.arduino.cc/en/Reference/SD) 

+ [SoftwareSerial*.] (http://www.pjrc.com/teensy/td_libs_SoftwareSerial.html) [Reference.] (https://www.arduino.cc/en/Reference/SoftwareSerial)

+ [SPI.] (https://www.pjrc.com/teensy/td_libs_SPI.html) [Reference.](https://www.arduino.cc/en/Reference/SPI)

+ [Wire.] (http://www.pjrc.com/teensy/td_libs_Wire.html) [Reference](https://www.arduino.cc/en/Reference/Wire)

+ **There is now an EC library**

#### 3.4 Other Useful Libraries and programs

+ [Qduino.h and Qduino fuelGauge](https://github.com/sparkfun/Arduino_Boards/tree/master/sparkfun/avr/libraries/Qduino) allow you to measure the charge on you battery. 

### 4.0 Arduino Qduino Pinouts

- SD Card Reader: CS (D4), SCK (D15), MOSI (D16), MISO (D17)

- Pressure Sensor: SDA (D2), SCL (D3)

- Temperature Sensors: Data (D6)

- Conductivity Circuit: TX (D8), RX (D9)

### 5.0 Build Instructions

*We are continously updating and improving OpenCTD prototypes. These instuctions are subject to change.* 

**IMPORTANT note about power consumption:** All of the sourced modules are rated to work at 3.3V, however, when two or more are running simultaneously, the 3.3V output on most Arduino yields inconsistent readings and the SD card reader may not function at all. We recommend powering the entire system with a minimum of 3.7V. On standard Arduino's, the 5V output should be used. On the Qduino, VCC with a 3.7V battery is sufficient. 

**_We strongly encourage you to test all the components one by one on a breadboard before soldering modules together. If you're planning to build multiple CTDs, we recommend that you use a dedicated Qduino, with header pins, for breadboard testing._**

![A complete OpenCTD system moutned to a breadboard for testing before soldering and potting](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/BB.jpg?raw=true "A complete OpenCTD system moutned to a breadboard for testing before soldering and potting")

*A complete OpenCTD system moutned to a breadboard for testing before soldering and potting*

#### 5.1 SD Card Reader

The [Sainsmart microSD card reader](http://amzn.to/265xAZQ) that we recommend is a 'plug and play' module. Connect each pin following the pinout guide above. For fitting into a tight housing, you may want to bend each pin at a 90% angle (using needle nose pliers) or remove the headers completely. Hookup wires should be at least 8 cm long. 

![SD card reader with bent headers](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/SD1.jpg?raw=true "SD card reader with bent headers")

*SD card reader with bent headers.*

![SD card reader with soldered connections](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/SD2.jpg?raw=true "SD card reader with soldered connections")

*SD card reader with soldered connections.*

![SD card reader with heat shrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/SD3.jpg?raw=true "SD card reader with heat shrink")

*SD card reader with heat shrink*

To prepare the microSD card, wipe the card and create a single, empty text file called **datalog.txt**.

#### 5.2 Pressure Sensor

There are several options and configurations for the pressure sensor, all of which rely on the MS5803-14BA sensor module. The simplest solution is a prefabricated model that requires no additional modificaion, just solder headers or connectors to Gound, Vin, SCL, and SDA and connect to the Qduino (we strongly recommend this option for people who do not have extensive experience with soldering). 

![Three possible pressure modules.](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS1.jpg?raw=true "Three possible pressure modules")

*Three possible pressure modules.*

Other solutions require a small 100nF (104) capacitor and 10kOhm pull-up resistor. The resistor bridges pin 3 and 6 on the pressure module. The capacitor bridges pins 2 and 5. SCLK is pin 1, Ground is pin 2, VCC in pin 5, and SDI/SDA is pin 7. Pins 5 and 6 need to be bridged with a jumper wire. 

![Layout for pressure module](https://edwardmallon.files.wordpress.com/2014/03/pressure-sensor-wiring.jpg?w=640 "Layout for pressure module")

*Layout for pressure module. From [The Cave Pearl Project](https://edwardmallon.wordpress.com/2014/03/27/adding-a-ms5803-02-high-resolution-pressure-sensor/).*

![Back view of one DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS2.jpg?raw=true "Back view of one DIY pressure module")

*Back view of one DIY pressure module.*

![Front view of a small DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS3.jpg?raw=true "Front view of a small DIY pressure module")

*Front view of a small DIY pressure module.*

![Back view of the same DIY pressure module](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/PS4.jpg?raw=true "Back view of the same DIY pressure module")

*Back view of the same DIY pressure module.*

Hookup wires for the pressure sensor should be about 5 cm longer than the length of pipe used for the house (we recommend a total length of 30 cm). 

#### 5.3 Temperature Sensors

The temeprature probes use a DS18B20 digital thermistor in a stainless steel housing. We use a battery of 3 probes averaged together for more consistent readings. The OneWire protocol allows mutliple probes to be queried on the same pin, so all three probescan feed into a single data pin. To prepare the probes, cut the wire length to 30 cm. Solder the three data strands, three power strands, and three ground strands together and a ttach a single solid core wire to each. 

![Three termperature probes prepped for soldering](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T1.jpg?raw=true "Three termperature probes prepped for soldering")

*Three termperature probes prepped for soldering.*

![Temperature probes connected](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T2.jpg?raw=true "Temperature probes connected")

*Temperature probes connected.*

![Temperature probes treated with heat shrink](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T3.jpg?raw=true "Temperature probes treated with heat shrink")

*Temperature probes treated with heat shrink.*

![Temperature probes treated with additional heat shrink to keep everything tindy](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/T4.jpg?raw=true "Temperature probes treated with additional heat shrink to keep everything")

*Temperature probes treated with additional heat shrink to keep everything tidy.*

Finally, you will need to bridge the Vcc and Data pin (Vcc and D6 on the Qduino) with a 4.7 kOhm pull-up resisitor. This should be done when you solder everything directly to the Arduino. 

####5.4 Conductivity Sensor

Different conductivity probes all have different configurations. In many cases, there will be more wires than are used. Use a multimeter to trace which wires are actually connected to each electrode. Once you have the electrodes traced, cut the wire to approximately 25cm and set the electrode aside for potting. 

The Atlas conductivity circuit needs very little preparation. To help it fit into a tight housing, bend the headers 90% and solder hook-up wires to all contacts except the two probe contacts. The conductivity probe will eventually be attached to these. 

![Conductivity circuit with bent headers and hook-up wires](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/EC1.jpg?raw=true "Conductivity circuit with bent headers and hook-up wires")

*Conductivity circuit with bent headers and hook-up wires.*

![Conductivity circuit with heat-shrink to protect contacts](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Images/EC2.jpg?raw=true "Conductivity circuit with heat-shrink to protect contacts")

*Conductivity circuit with heat-shrink to protect contacts.*

#### 5.6 Prepare the housing.

Cut your 3" PVC pipe so that it is 25 cm in length.  Don't worry if the tube is label "not for pressure" as the device will be filled with mineral oil of other non-compressable liquids. At one end of the pipe drill 4 equidistant holes to allow water flow. The center of each hole should be 2.5 cm from the edge. This will be the bottom of the OpenCTD where the sensors go.

[PICTURE]

####  5.7 Prepare the electronics.

Mount the SD Card reader on your Arduino board. Connect the temperature probes in series; mount a 1 KOhm resistor between the positive and signal leads. [PICTURE] Mount the pressure sensor by following the instructions provided by [the Cave Pearl Project](https://edwardmallon.wordpress.com/2014/03/27/adding-a-ms5803-02-high-resolution-pressure-sensor/) (and send them a hearty thank you for providing such excellent, clear, directions). [PICTURE] Mount the conductivity probe and circuit in accordance with the guidelines at [Atlas Scientific](https://www.atlas-scientific.com/conductivity.html). Get creative with how you plan on packing everything into the tube. It will be a tight fit! I like to use plenty of connectors that allow you to quickly detach different components. [PICTURES]

#### 5.8 Potting

*Warning, after this step, there's no going back!*

 Grab your 3-D printed base plate and prepare to affix the sensors. 
 **IMPORTANT:** *Apply a small amount of electrical tape over the membrane of the pressure sensor.* 
 This membrane is sensitive and covering it with tape will prevent any glue or epoxy from fouling it. You want to first affix the pressure sensor to the base plate. Lightly cover the edge of the indentation with hot glue. Taking care not to let any come in contact with the membrane, seat the sensor in the indentation and apply more hot glue (This will provide added protection for this circuit). [Picture] Place the three temperature sensor into the 3 small holes. Make sure that they do not sit so far out that you can't see some stainless steel in the inside. [Picture] Try and keep the 3 temperature sensors roughly the same distance protruding from the base plate.  Apply epoxy around the outside of the base plate around each temperature sensor. The outside of the base plate is the portion of the base plate that will be exposed to the water - this is the side w/o the indentation for the pressure sensor.  Once the hot glue hardens then place the conductivity probe in the only hole big enough for it. Make sure the conductivity probe sits above the temperature probes (to avoid any ionization interference from these metal probes) and apply hot glue to the outside of the base plate around the conductivity sensor similar in approach to what was done for the temperature sensors. [Picture] 
 
 Align the baseplate such that it is lightly recessed into the tube (when standing upright [i.e. sensors facing down], none of the sensors should touch the ground). On the side where the sensors protrude, hot glue the baseplate into place along the wall of the PVC tube to ensure the expoy doesn't leak out during potting. [Picture]

Once you are satisfied with everything's position, it's time for Hysol-90. Using the epoxy gun apply the epoxy on the inside of the tube around the sensors. We used an entire cartridge and had almost 2 cm of epoxy on the bottom.  Check periodically to make sure that nothing is leaking out of the bottom, and remove the tape from around the pressure sensor membrane. Let it cure overnight. [Picture]

### 6.0 Your first cast. 

Power up the OpenCTD with your battery pack of choice (you'll want the full 12v). Confirm that it is writing data to the SD card. 

Now for the fun part. 

While everything is powered on, fill it with mineral oil. Mineral oil is non conductive and won't interfere with the electronics. Fill it top a few centimeters below the top. There will be some spillover if you're trying to avoid bubbles in the housing. Gentle lower the test cap down and screw it into place. You CTD is now sealed and logging. Wipe down any spilled oil. I find that these [microfiber cloths from Amazon](http://amzn.to/1RLdKZd) do a great job of sopping up small oil spills. It's a good idea to have them with you as you want to minimize any oil release into the water. 

Your OpenCTD is now ready to take the plunge!

### 7.0 Calibration and Data Conversions

Proper calibration of the OpenCTD requires access to already calibrated validation instruments. These can be commercial CTD, handheld systems, or bench-mounted laboratory systems. As the community grows, properly calibrated OpenCTDs can be used to benchmark newly-built instruments. 

#### 7.1 Depth

In order to minimize the amount of processing that happens onboard the OpenCTD, pressure is measured in millibars (the default output for the current pressure sensor). To convert pressure to depth use the following equation:

D = (P(depth) - P(surface) * 100) / (g * 1000)

Where D is depth in meters; P(depth) is the pressure (in millibars) at depth); P(surface) is the pressure at the surface in millibars; and g is acceleration due to gravity (9.81 m/s2).

No additional calibration shoud be need for the MS5803-14BA pressure sensor. 

#### 7.2 Temperature

Calibrating the temperature sensors requires access to an already calibrated instrument. Allow both the OpenCTD and the validation instrument to equilibrate in water for 15 minutes. Take the average of the three OpenCTD temperature outputs and note the difference between that average and the validation instrument. Repeat for two additional temperatures of at least 5 degrees difference. There should be a linear relationship between the OpenCTD temperature sensors and the validation instrument. Take the average of the difference between the three temperature readings and use as a calibration coefficient for your OpenCTD. 

This should remain steady for many casts, but it is always good practice to check you temperature calibration whenever you have access to a validation instrument. 

#### 7.3 Conductivity

Atlas Instructions

### 8.0 Resources

[Oceanography for Everyone](http://oceanographyforeveryone.com/)

[Original Project Description](https://www.rockethub.com/projects/26388-oceanography-for-everyone-the-openctd)

### 9.0 Acknowledgments

This software has been kludged together by Andrew Thaler, based on code from Walt Holm, arduino.cc samples, Atlas scientific, Vhati, and Russell Neches. OpenCTD was designed by Andrew Thaler, Kersey Sturdivant, and Russell Neches. 

### 10.0 Code of Conduct

Please review our [Contributor Code of Conduct](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/CODE_OF_CONDUCT.md) prior to your first contribution. 

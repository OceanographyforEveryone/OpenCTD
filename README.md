OpenCTD
=======

### Overview

Conductivity, temperature, and depth (CTD). With these three measurements, marine scientists can unlock ocean patterns hidden beneath the waves. The ocean is not uniform, it its filled with swirling eddies, temperature boundaries, layers of high and low salinity, changing densities, and many other physical characteristics. To reveal these patterns, oceanographers use a tool called the CTD. 

The OpenCTD is a low-cost, open-source CTD suitable for both educators and scientists. The platform is built using easy-to-source parts powered by an Arduino-based microcontroller. Our goal is to create a device that is accurate enough to be used for scientific research and can be constructed for less than $300. Source codes, circuit diagrams, and building plans are open souce. Our goal is for the final instrument to be effective to 200 meters depth. For many coastal regions, 200 meters covers the majority of the ocean that is accessible by small boat. The OpenCTD is deisnged for people working in this niche, where entire research projects can be conducted for less than the cost of a commercial CTD. However, the Open CTD is scalable, and anyone with the inclination can adapt these plans to operate in deeper water.

###Current Status

Initial field trials have been completed and we are analyzing the data from the first several casts to confirm accuracy. All data and field notes from the first Field Trial can be found in the [Blue Heron 15-11](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/Blue_Heron_2015-11) repository.

From June 18 to 21, Andrew Thaler and Kersey Sturdivant conducted a marathon prototyping session to produce additional OpenCTDs and streamline the software and hardware. Updates from this event will be available soon. 

### Bill of Materials

Almost all of the necessary parts can be found through Amazon or Sparkfun. Visit our [Parts Depot](http://oceanographyforeveryone.com/depot.html) for a list of Amazon-sourceable parts.

Additional components, like a pre-fabricated [pressure sensor module](https://www.sparkfun.com/products/12909), [LiPo batteries](https://www.sparkfun.com/products/8483), [SMD boards](https://www.sparkfun.com/products/13655), and the [qDuino Mini](https://www.sparkfun.com/products/13614) can be found at Sparkfun. The MS5803-14BA pressure sensor previously needed to be special ordered from a parts supplier, but  [SparkFun](https://www.sparkfun.com/products/12909) has a (much more expensive) commercial 14-bar unit using the same sensor.

Servoflo sells the raw, calibrated pressure sensor in both [14Bar](http://www.servoflo.com/download-archive/data-sheets/220-calibrated-digital-sensor-modules/614-ms5803-14ba) and [30Bar](http://www.servoflo.com/download-archive/data-sheets/220-calibrated-digital-sensor-modules/613-ms5803-30ba) modules. These are surface mounted sensors and require significant soldering skills to mount properly. 

PVC pipe can be found at most home supply stores. 

### Required Arduino Libraries

+ [SparkFun_MS5803_I2C for the pressure sensor.](https://github.com/sparkfun/SparkFun_MS5803-14BA_Breakout_Arduino_Library/tree/V_1.1.0)

+ [Dallas Temperature Control for the DS18B20 thermometer.](https://milesburton.com/Dallas_Temperature_Control_Library)

+ [OneWire.](http://www.pjrc.com/teensy/td_libs_OneWire.html) [Reference.](http://playground.arduino.cc/Learning/OneWire)

+ [SD.](https://www.arduino.cc/en/Reference/SD) 

+ [SoftwareSerial*.](http://www.pjrc.com/teensy/td_libs_SoftwareSerial.html) [Reference.](https://www.arduino.cc/en/Reference/SoftwareSerial)

+ [SPI.](https://www.pjrc.com/teensy/td_libs_SPI.html) [Reference.](https://www.arduino.cc/en/Reference/SPI)

+ [Wire.](http://www.pjrc.com/teensy/td_libs_Wire.html) [Reference](https://www.arduino.cc/en/Reference/Wire)

###Other Useful Libraries and programs

+ [Qduino.h and Qduino fuelGauge](https://github.com/sparkfun/Arduino_Boards/tree/master/sparkfun/avr/libraries/Qduino) allow you to measure the charge on you battery. 

### Arduino Qduino Pinouts

- SD Card Reader: CS (D4), SCK (D15), MOSI (D16), MISO (D17)

- Pressure Sensor: SDA (D2), SCL (D3)

- Temperature Sensors: Data (D6)

- Conductivity Circuit: TX (D8), RX (D9)

##Build Instructions

We are continously updating and improving OpenCTD prototypes. These instuctions are subject to change. 

**A note about power consumption:** All of the sourced modules are rated to work at 3.3V, however, when two or more are running simultaneously, the 3.3V output on most Arduino yields inconsistent readings and the SD card reader may not function at all. We recommend powering the entire system with a minimum of 3.7V. On standard Arduino's, the 5V output should be used. On the Qduino, VCC with a 3.7V battery is sufficient. 

**_We strongly encourage you to test all the components one by one on a breadboard before soldering modules together. If you're planning to build multiple CTDs, we reccomend that you use a dedicated Qduino, with header pins, for breadboard testing._**

####SD Card Reader

The [Sainsmart microSD card reader](http://amzn.to/265xAZQ) that we recommend is a plug and play module. Connect each pin following the pinout guide above. For fitting into a tight housing, you may want to bend each pin at a 90% angle or remove the headers completely. 

To prepare the microSD card, wipe the card and create a single, empty text file called **datalog.txt**.

####Pressure Sensor

####Temperature Sensors

####Conductivity Sensor



###Prepare the housing.

Print the OpenCTD baseplate which will serve as a form to position your sensors. Cut a 12 inch long piece of 3 inch PVC. Don't worry if the tube is label "not for pressure" as the device will be filled with mineral oil of other non-compressable liquids. Cut small holes or gaps in one end of the tube to allow water flow, this will be the bottom of the OpenCTD where the sensors go. 

###Prepare the electronics.

Mount the SD Card reader on your Arduino board. Connect the temperature probes in series; mount a 1 KOhm resistor between the positive and signal leads. Mount the pressure sensor by following the instructions provided by [the Cave Pearl Project](https://edwardmallon.wordpress.com/2014/03/27/adding-a-ms5803-02-high-resolution-pressure-sensor/) (and send them a hearty thank you for providing such excellent, clear, directions). Mount the conductivity probe and circuit in accordance with the guidelines at [Atlas Scientific](https://www.atlas-scientific.com/conductivity.html). Get creative with how you plan on packing everything into the tube. It will be a tight fit! I like to use plenty of connectors that allow you to quickly detach different components. 

###Potting

*Warning, after this step, there's no going back!*

Align the baseplate such that it is lightly recessed into the tube (when standing upright, non of the sensors should touch the ground). Hot glue it into place along the edges so the expoy won't leak out during potting. Lay the pressure sensor into the middle hole. Lightly cover the indentation with 2-ton epoxy, taking care not to let any come in contact with the membrane. Seat the sensor and apply more 2-ton epoxy above. This will provide added protection for this circuit. Place the three temperature sensor into the 3 small holes. Make sure that they do not sit so far out that you can't see some stainless steel in the inside. Place the conductivity probe in the only hole big enough for it. 

Once you are satisfied with everything's position, it's time for Hysol-90. Use an applicator to mix the expoxy as you pour it into the tube. I used an entire cartridge and had almost 2 cm of epoxy on the bottom. Let it cure overnight. Check periodically to make sure that nothing is leaking out of the bottom. 

###Your first cast. 

Power up the OpenCTD with your battery pack of choice (you'll want the full 12v). Confirm that it is writing data to the SD card. 

Now for the fun part. 

While everything is powered on, fill it with mineral oil. Mineral oil is non conductive and won't interfere with the electronics. Fill it top a few centimeters below the top. There will be some spillover if you're trying to avoid bubbles in the housing. Gentle lower the test cap down and screw it into place. You CTD is now sealed and logging. Wipe down any spilled oil. I find that these [microfiber cloths from Amazon](http://amzn.to/1RLdKZd) do a great job of sopping up small oil spills. It's a good idea to have them with you as you want to minimize any oil release into the water. 

Your OpenCTD is now ready to take the plunge!

##Calibration

Proper calibration of the OpenCTD requires access to already calibrated validation instruments. These can be commercial CTD, handheld systems, or bench-mounted laboratory systems. As the community grows, properly calibrated OpenCTDs can be used to benchmark newly-built instruments. 

###Depth

In order to minimize the amount of processing that happens onboard the OpenCTD, pressure is measured in millibars (the default output for the current pressure sensor). To convert pressure to depth use the following equation:

D = (P(depth) - P(surface) * 100) / (g * 1000)

Where D is depth in meters; P(depth) is the pressure (in millibars) at depth); P(surface) is the pressure at the surface in millibars; and g is acceleration due to gravity (9.81 m/s2).

No additional calibration shoud be need for the MS5803-14BA pressure sensor. 

###Temperature

Calibrating the temperature sensors requires access to an already calibrated instrument. Allow both the OpenCTD and the validation instrument to equilibrate in water for 15 minutes. Take the average of the three OpenCTD temperature outputs and note the difference between that average and the validation instrument. Repeat for two additional temperatures of at least 5 degrees difference. There should be a linear relationship between the OpenCTD temperature sensors and the validation instrument. Take the average of the difference between the three temperature readings and use as a calibration coefficient for your OpenCTD. 

This should remain steady for many casts, but it is always good practice to check you temperature calibration whenever you have access to a validation instrument. 

###Conductivity

Atlas Instructions

###Resources

[Oceanography for Everyone](http://oceanographyforeveryone.com/)

[Original Project Description](https://www.rockethub.com/projects/26388-oceanography-for-everyone-the-openctd)

###Acknowledgments

This software has been kludged together by Andrew Thaler, based on code from Walt Holm, arduino.cc samples, Atlas scientific, Vhati, and Russell Neches. OpenCTD was designed by Andrew Thaler, Kersey Sturdivant, and Russell Neches. 

###Code of Conduct

Please review our [Contributor Code of Conduct](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/CODE_OF_CONDUCT.md) prior to your first contribution. 

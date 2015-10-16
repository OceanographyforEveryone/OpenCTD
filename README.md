OpenCTD
=======

[Link](https://www.rockethub.com/projects/26388-oceanography-for-everyone-the-openctd): RocketHub Project Description

### Background

Conductivity, temperature, and depth (CTD). With these three measurements, marine scientists can unlock ocean patterns hidden beneath the waves. The ocean is not uniform, it its filled with swirling eddies, temperature boundaries, layers of high and low salinity, changing densities, and many other physical characteristics. To reveal these patterns, oceanographers use a tool called the CTD. A CTD is found on almost every major research vessel. Rare is the scientific expedition--whether it be coastal work in shallow estuaries or journeys to the deepest ocean trenches--that doesn’t begin with the humble CTD cast.

### Overview

The OpenCTD is a low-cost, open-source CTD suitable for both educators and scientists. The platform is built using readily available parts and is powered by an Arduino-based microcontroller. Our goal is to create a device that is accurate enough to be used for scientific research and can be constructed for less than $300. Source codes, circuit diagrams, and building plans will be freely available. Our goal is for the final instrument to be effective to 200 meters depth.   Why 200 meters? For many coastal regions, 200 meters of water depth covers the majority of the ocean that is accessible by small boat. The OpenCTD is targeted to people working in this niche, where entire research projects can be conducted for less than the cost of a commercial CTD. However, the Open CTD is scalable, and anyone with the inclination can adapt our plans to operate in deeper waters.

###Current Status

Initial field trials have been completed and we are analyzing the data from the first several casts to confirm accuracy. All data and field notes from the first Field Trial can be found in the [Blue Heron 15-11](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/Blue_Heron_2015-11) repo.

### Bill of Materials

Almost all of the necessary parts can be found through Amazon. Visit our [Parts Depot](http://oceanographyforeveryone.com/depot.html) for the full list.

A 3" PVC pipe can be found at most home supply stores. 

The MS5803-14BA pressure sensor previously needed to be special ordered from a parts supplier, but hackable versions are now appearing on places like [SparkFun](https://www.sparkfun.com/products/12909).

### Required Arduino Libraries

+ [I2C library for the MS5803_14BA pressure sensor.](https://github.com/millerlp/MS5803_14)

+ [Dallas Temperature Control for the DS18B20 thermometer.](https://milesburton.com/Dallas_Temperature_Control_Library)

+ [OneWire**.](http://www.pjrc.com/teensy/td_libs_OneWire.html) [Reference.](http://playground.arduino.cc/Learning/OneWire)

+ [SD*.](https://www.arduino.cc/en/Reference/SD) 

+ [SoftwareSerial*.](http://www.pjrc.com/teensy/td_libs_SoftwareSerial.html) [Reference.](https://www.arduino.cc/en/Reference/SoftwareSerial)

+ [SPI**.](https://www.pjrc.com/teensy/td_libs_SPI.html) [Reference.](https://www.arduino.cc/en/Reference/SPI)

+ [Wire*.](http://www.pjrc.com/teensy/td_libs_Wire.html) [Reference](https://www.arduino.cc/en/Reference/Wire)

\* Included with Arduino.

\** Included with Arduino. A newer version may be available.

### Arduino Pinouts

- A4 - Pressure Sensor SDA

- A5 - Pressure Sensor SCLK

- D7 - Temperature Data

- D2 - Conductivity RX

- D3 - Conductivity 

###Build Instructions

*detailed build instructions are pending.*

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

*Pending seawater field trials.*

###Resources

[Oceanography for Everyone](http://oceanographyforeveryone.com/)

[Original Project Description](https://www.rockethub.com/projects/26388-oceanography-for-everyone-the-openctd)

###Acknowledgments

This software has been kludged together by Andrew Thaler, based on code from Walt Holm, arduino.cc samples, Atlas scientific, Vhati, and Russell Neches. OpenCTD was designed by Andrew Thaler, Kersey Sturdivant, and Russell Neches. 

Determining Time Constant
=========================

### Background

Thermal Time Constant is a measure of how quickly the thermistor to responds to changes in ambient temperature.  It is expressed as the time it takes for a thermistor to cool to 63.2% of the total difference between a stable high temperature and a stable low temperature.  
### Methods

Two different cladding styles were tested: stainless steel cladding with curved, hemispherical ends (hemis) and stainless steel cladding with flat ends (flat). Three hemis were tested together as a single batch. Nine flats were tested in three batches of three. We used the same methods as the equilibration test below and timed how long it took for a batch of 3 averaged thermistors to reach the 63.2% interval. 

### Results

The two different claddings had remarkably different time constants. 

Time constant for hemis: **8.5s**

Time constant for flats: **5.7s**

[Notes](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Field_Trials/Temperature_Tests/Test_Notes2.jpg)

Temperature Sensor Equilibration Test
=====================================

### Background 

Though Time Constant is the most meaningful measurement, in the field we often need a rough value to make on the fly adjustments to our field protocols. One of the big trade-offs between the OpenCTD and a commercial unit is that, while the sensors we use aren't actually less accurate than those you would find in a commercial unit, they are slower. Particularly the temperature sensors. This means that they take longer to reach equilibrium with their environment and in order to get accurate readings, users must be patient and do their conventional CTD casts just a little bit slower. 

How much slower has been a topic of debate, but with an array of steel-clad DS18B20 Temperature Sensors, I decided it's time to get some answers.

### Methods

A crock pot was filled with water and set to maintain a constant warm temperature, while a second vessel was filled with water and allowed to site a room termperature. But vessels were large enough that residual thermal energy from the stainless steel thermistor cladding wouldn't impact vessel temperature. Temperatures were confirmed with a commercial Hanna Instruments thermocouple. [TempProdeTester.ino](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Support_Code/TempProbeTester) from the [OpenCTD support code library](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Support_Code) was used to read thermistors. Thermistors, in batches of 5, were allowed to equilibrate in the room temperature vessel, and then transfered to the warm vessel. Time to equilibrium was recorded. Themistors were allowed to equilibrate in the warm vessel, and then transfered back to the room temperature vessel. Time to equilibrium was recorded. Three replicates were performed. 

![Photo of thermistor set-up](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Field_Trials/Temperature_Tests/temp_test_set_up.jpg) *Photo of thermistor set-up.*

Equilibration rate (&deg;C/s) was determined by averaging the rate of equilibration for each thermistor bank.

### Results

Average equilibration rate when transitioning from low temperature to high temperature: **1.2&deg;C/s**

Average equilibration rate when transitioning from high temperature to low temperature: **2.3&deg;C/s**

[Notes](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Field_Trials/Temperature_Tests/Test_Notes.jpg).

### Lessons Learned

It takes almost twice as long to reach equilibrium when warming up than when cooling down, a result which matches our observations in the field. Though this should serve as a rough baseline, there is a curve to the equilibration rate that is not capture in this data (the rate slows down as the sensors approach equilibrium) which we will need to assess with additional tests. 

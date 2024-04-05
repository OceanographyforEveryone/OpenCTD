## OpenCTD Benchtest Board

Congratulations! If you've landed here, you've recieved one of the OpenCTD benchtest boards/calling cards. This card allows you to build a working CTD that you can use to practice your soldering skills, test OpenCTD components before permanently sealing them into epoxy, or build a benchtop instrument for measuring  salinity, temperature, and air pressure. This board works with the components listed in the manual [Construction and Operation of the OpenCTD](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Documentation/Manual/OpenCTD_ConstructionOperation.pdf). 

![Bare OpenCTD Benchtest Board](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Hardware/Benchtester/BoardBlank.png)

To build your benchtester, you will need:
1. [Standard female headers](https://amzn.to/3J5v8dg) (2 8-pin headers, 2 3-pin headers, 1 16-pin header, and 1 12-pin header, but you can order long strips of headers and cut them down with a flush cutter)
2. 2 [10 kOhm resistors](https://amzn.to/4cN27Rc)
3. 1 [4.7 kOhm resistor](https://amzn.to/4aIREVb)
4. 1 [2-position board mounted switch](https://www.adafruit.com/product/805)

The only tools and consumables you need are a [soldering iron](https://amzn.to/4aios7I), [solder](https://amzn.to/4cMaoVF), and [flush cutters](https://amzn.to/4cDmFf0). I love the Pinecil as a simple starter soldering iron, but you will need to get a [power supply](https://amzn.to/3J8Vewa) for the iron. 

This board is designed to work with the [Adafruit Adalogger M0 Feather](https://www.adafruit.com/product/2796), the [Atlas EZO EC conductivity circuit](https://amzn.to/49nwWcp), and the [DS3231 Real-Time Clock](https://www.adafruit.com/product/5188). If you have an OpenCTD kit, all three components are already included. 

Once assembled, this board will read data from the [Sparkfun 14-Bar Pressure Sensor Breakout Board](https://www.sparkfun.com/products/12909) (or any other system using a MS5803-14BA pressure chip), any [DS18B20 temperature sensor](https://amzn.to/49sBpL5), and any [two-electrode conductivity probe](https://amzn.to/3xrnmrT).

### Assembling the Benchtest Board

![OpenCTD Benchtest Board with headers, switch, and resistors](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Hardware/Benchtester/BoardHeaders.png)

Note: All components will be soldered onto on the front (the side with Andrew's contact information) of the card. If you've never soldered before, I recomend reading through Mitch Altman's [Soldering Is Easy](https://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf) guide. 

1. Trim your strips of female headers to the correct length for each set of through holes. I reccommend cutting through the center of the next pin in the line in order to ensure that you do not accidentally cut it too short. You will have 1 16-pin-long strip, 1 12-pin-long strip, 2 8-pin long strips, and 2 3-pin-long strips.

2. Solder each strip of pins into the corresponding row that they fit in. The 16- and 12-pin strips will go in the rows for the Adalogger M0. The 3-pin strips will go in teh rows for the Atlas EZO EC. One 8-pin strip will go in the row for the DS3231 Real-Time Clock (on some boards it may be mislabelled DS 3331). The final 8-pin strip will go on the row of 8 labeled holes on the lower right edge of the card.

3. Insert the 4.7 kOhm resistor through the holes labeled R1. It does not matter which leg of the resistor goes through which hole. Solder in place. 

4. Insert the two 10 kOhm resistors through the holes labeled R2 and R3. It does not matter which leg of the resistor goes through which hole. Solder in place.

5. Insert the switch into the holes labeled switch and solder into place.

![OpenCTD Benchtest Board poulated with components](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Hardware/Benchtester/BoardPopulated.png)

That's it! Your board is now ready tgo be populated with OpenCTD components. For instuctions on how to assemble the Adalogger, Real-time Clock, and EZO EC circuit, as well as the sensors, please refer to Chapter 6 and Chapter 7 of [Construction and Operation of the OpenCTD](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Documentation/Manual/OpenCTD_ConstructionOperation.pdf). To learn how to calibrate these sensor, you can reference the build guide or the [Calibration and Data Management](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Documentation/Manual/OpenCTD_CalibrationDataManagement.pdf) guide.

![OpenCTD Benchtest Board with sensors attached](https://github.com/OceanographyforEveryone/OpenCTD/blob/main/Hardware/Benchtester/BoardFinished.png)

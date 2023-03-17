Data Processing
==============

This folder contains software and templates for translating OpenCTD outputs into human readable formats. 

### Basic R Plotter

This R script will process your raw OpenCTD data to give you salinity and temperature profiles. It is set up to process files with data rows in the order of 'Date,Time,Conductivity,Temperature,Pressure'. It is recommended you create a folder in your C: drive labeled 'OpenCTD_Data'. This script will use that folder as a working directory. The top 1.5 meters of data is removed to make figures more readable.

### Excel Template

For users who would prefer to work in Microsoft Excel, [OpenCTD_DataConversion_Template.xlsx](https://github.com/OceanographyforEveryone/OpenCTD/blob/master/Data_Processing/OpenCTD_DataConversion_Template.xlsx) is an Excel template which will conver raw data fromt he OpenCTD into human-readable practical units for further presentation analysis. It must be downloaded. 

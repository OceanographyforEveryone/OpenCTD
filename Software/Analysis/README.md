# Data Analysis

This folder contains software and templates for translating OpenCTD outputs
into human readable formats. 

### Excel Template

For users who would prefer to work in Microsoft Excel,
[OpenCTD_DataConversion_Template.xlsx](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Analysis/Excel) is an Excel template which
will convert raw data from the OpenCTD into human-readable practical units for
further presentation analysis.

### Google Sheets Template

For users who prefer Google Sheets, the same template is available here: [OpenCTD_DataConversion_Template](https://docs.google.com/spreadsheets/d/1f7xNA3-hjREeEzjW1fgzbNm-msiKLi_wXyJGh-PwAek/edit?usp=sharing). Please note that the chart function in Google Sheets is not particularly felxible, so the water column profile is generated sideways. 

### Basic R Plotter

This [R script](Software/Analysis/R) will process your raw OpenCTD data to give you salinity and
temperature profiles. It will process files with data rows with the fields
`Date,Time,Conductivity,Temperature,Pressure`. It is recommended you create
a folder in your local drive labeled 'OpenCTD_Data'. This script will use that
folder as a working directory. The top 1.5 meters of data is removed to make
figures more readable.

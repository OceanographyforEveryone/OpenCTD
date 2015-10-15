Field Trials
============

Are you ready to take your own OpenCTD into the field for testing? Thank you, this repo is for you! Please note that *Field Trials* are note the same as expeditions. Field trials are about testing the OpenCTD against validated, commercial instruments to better help us understand their strengths and weaknesses. 

###Data is the source of all our power

We need to see how the OpenCTD performs in the wild, in a variety of conditions, from freshwater lakes and rivers to hypersaline seas. We need data, both raw and cleanly processed. We need the original OpenCTD data as well as the data from the instuments you are testing it against. We need station logs, field notes, and pictures of your device. All of this will help make the OpenCTD and Oceanography for Everyone better. 

###Style Guide

In order to streamline these Field Trials and make them accessible to everyone, we'd like to follow a relatively standardized form. Each field trial should be contained within its own folder--you can use the name of the vessel, the geographic location, the expedition number, or any other signifier that is consistent and clear. Each folder should then contain:

1. A README.md that descibes the Field Trial, including location, dates, vessel used (if any), and instruments that the OpenCTD was tested against. A field narrative describing the trials would also be appreciated. 

1. Notes_and_Station_Logs: These are your observation notes (handwritten and scanned is fine) from the field trials as well as the official station logs that should be produced with each cast. Stations logs include inportant information like environmental conditions, geographic coordinates, time of deployment start and end, other events that happened during deployment, and any other notes regarding the deployment. Formally, anytime a piece of gear goes over the side, it should be considered a new station, even if the deployment was aborted. 

2. Raw_Data: A folder for both the raw outputs of the OpenCTD and the validation instrument, separated by casts and clearly delinated such that other users can quickly tell which validation instruments cast corresponds to which OpenCTD cast. 

3. Processed_Data: Your cleaned data, ready to be analyzed. Preferably in accesible formats (though duplicates in proprietary formats like .xlsx are acceptable as long as it is not the only format available). Refer to the [Blue_Heron_2015-11](https://github.com/OceanographyforEveryone/OpenCTD/tree/master/Field_Trials/Blue_Heron_2015-11) Field Trial for an example. 

417. Images: Any relevent images from the Field Trial, including graphs of your data output and photographs of the deployment. 

###Future Goals

As this project evolves, we will be developing ways to easily database your OpenCTD casts and make them accessible to other citizen oceanographers and the general public. 

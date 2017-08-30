setwd('C:/OpenCTD_Data') #Set working directory to user-created folder in C drive named "OpenCTD_Data". You can still search for the file elsewhere through a search window per the script.
originalcolumns <- c("Date","Time","Conductivity","Temperature","Pressure") #Establish column names for incoming file read.
rawdata <- read.csv(file.choose(),header=FALSE,skip=3,col.names=originalcolumns,stringsAsFactors=FALSE)   #Read user transferred datalog.txt from the user-defined working directory.
#Removed the first three lines in case of gibberish from EC circuit.

#Coefficients for Pressure to Depth Conversion (See AN69 by SeaBird Scientific)
Coeff1=-1.82*10^-15; Coeff2=2.279*10^-10; Coeff3=2.2512*10^-5; Coeff4=9.72659; g=9.806

#Calculating Depth from Absolute Pressure (See AN69 by SeaBird Scientific)
AtmP = rawdata[1,5] #Assuming first recorded pressure value is the atmospheric pressure.
GaugeP = matrix((rawdata[,5]-AtmP)/100)  #In decibars.
Depth = matrix(((((Coeff1*GaugeP+Coeff2)*GaugeP-Coeff3)*GaugeP+Coeff4)*GaugeP)/g)

#PSS-78 Coefficients (See AN14 by SeaBird Scientific)
A1=2.070*10^-5; A2=-6.370*10^-10 ; A3=3.989*10^-15
B1=3.426*10^-2; B2=4.464*10^-1; B3=4.215*10^-1; B4=-3.107*10^-3
c0=6.766097*10^-1; c1=2.00564*10^-2; c2=1.104259*10^-4; c3=-6.9698*10^-7; c4=1.0031*10^-9
a0=0.0080; a1=-0.1692; a2=25.3851; a3=14.0941; a4=-7.0261; a5=2.7081
b0=0.0005; b1=-0.0056; b2=-0.0066; b3=-0.0375; b4=0.0636; b5=-0.0144
k=0.0162; CStandard=42.914

#PSS-78 Calculations for Salinity (See AN14 by SeaBird Scientific)
R=matrix((rawdata[,3]/1000)/CStandard)  
Rp=1+(((A1*GaugeP[,1])+(A2*(GaugeP[,1])^2)+(A3*(GaugeP[,1])^3))/(1+(B1*rawdata[,4])+(B2*rawdata[,4]^2)+(B3*R)+(B4*R*rawdata[,4])))
rT=c0+(c1*rawdata[,4])+(c2*rawdata[,4]^2)+(c3*rawdata[,4]^3)+(c4*rawdata[,4]^4)
RT=R/(rT*Rp)

#Calculating Salinity
Salinity=(a0+(a1*RT^0.5)+(a2*RT)+(a3*RT^1.5)+(a4*RT^2)+(a5*RT^2.5))+((rawdata[,4]-15)/(1+k*(rawdata[,4]-15)))*(b0+(b1*RT^0.5)+(b2*RT)+(b3*RT^1.5)+(b4*RT^2)+(b5*RT^2.5))

ConvertedData <- matrix(c(c(rawdata[,4]),c(Salinity),c(Depth)),ncol=3)
Filter1 <- ConvertedData[-which(ConvertedData[,3]<=1.0),] #Remove top meter of data.
MaxDepth <- which.max(Filter1[,3])  #Recorded max depth reached.

DowncastTemp <- matrix(Filter1[1:MaxDepth,1])   #Temp from surface to max depth.
DowncastSal <- matrix(Filter1[1:MaxDepth,2])    #Sal from surface to max depth.
DowncastDepth <- matrix(Filter1[1:MaxDepth,3])  #Depth from surface to max depth.

win.graph(800,600)  #Set window size for plots.
par(mfrow=c(2,1)) #Display both profiles in one window.
plot(DowncastTemp,-DowncastDepth,xlab='Temperature (C)',ylab='Depth (m)',col='#ff3300')  #Plot temp profile of downcast.
plot(DowncastSal,-DowncastDepth,xlab='Salinity (PSU)',ylab='Depth (m)',col='#0066ff')  #Plot sal profile of downcast.







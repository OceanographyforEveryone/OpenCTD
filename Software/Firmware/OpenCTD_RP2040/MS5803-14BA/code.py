##
# adapted from MS5803-14BA I2C Micropython Library by minyiky (https://github.com/minyiky/ms5803-micropython)
# and the SparkFun Pressure Sensor Breakout - MS5803-14BA library by Sparkfun (https://github.com/sparkfun/MS5803-14BA_Breakout)
##

import board
import busio
from MS5803 import MS5803

# Pins are configured for the Adalogger RP2040 and other Feather boards
i2c = busio.I2C(scl=board.SCL, sda=board.SDA)

# Initialize the sensor
ms = MS5803(i2c)

# print raw measurements to serial monitor
print(ms.get_measurements())

# return temperature in Celsius and pressure in mbar
temp, pressure = ms.get_measurements(temp_units='celsius', pressure_units='mbar')

# print temperature and pressure readings to serial monitor
print(f"Temperature: {temp:.2f} C, Pressure: {pressure:.2f} mbar")

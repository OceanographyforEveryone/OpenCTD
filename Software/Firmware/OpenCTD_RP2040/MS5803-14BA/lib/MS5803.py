##
# adapted from MS5803-14BA I2C Micropython Library by minyiky (https://github.com/minyiky/ms5803-micropython)
# and the SparkFun Pressure Sensor Breakout - MS5803-14BA library by Sparkfun (https://github.com/sparkfun/MS5803-14BA_Breakout)
##

import time
from collections import namedtuple
import board
import busio

OSR = namedtuple('OSR', ('address', 'sampling_time'))

TEMP_UNITS = ['fahrenheit', 'celsius']
PRESSURE_UNITS = ['pascals', 'mbar']

def convert_temperature(temp, units='celsius'):
    if units == 'fahrenheit':
        converted_temp = temp / 100
        converted_temp = (((converted_temp) * 9) / 5) + 32
    elif units == 'celsius':
        converted_temp = temp / 100
    return converted_temp

def convert_pressure(pressure, units='pascals'):
    if units == 'pascals':
        converted_pressure = pressure / 10
    elif units == 'mbar':
        converted_pressure = pressure / 10
    return converted_pressure

class MS5803():
    CMD_RESET    = 0x1E
    CMD_PROM     = 0xA0
    CMD_ADC_CONV = 0x40
    CMD_ADC_READ = 0x00

    PRESSURE    = 0x00
    TEMPERATURE = 0x10

    OSRs = {
        256: OSR(0x00, 1),
        512: OSR(0x02, 2),
        1024: OSR(0x04, 3),
        2048: OSR(0x06, 5),
        4096: OSR(0x08, 10)
    }

    def __init__(self, i2c, address=0x76, temp_osr=256, pressure_osr=256, temp_units=None, pressure_units=None):
        self.i2c = i2c
        self.address = address
        self._begin()
        self.temp_osr = temp_osr
        self.pressure_osr = pressure_osr
        self.temp_units = temp_units
        self.pressure_units = pressure_units

    def reset(self):
        self.i2c.try_lock()
        try:
            self.i2c.writeto(self.address, bytes([self.CMD_RESET]))
        finally:
            self.i2c.unlock()
        time.sleep(0.003)

    def _begin(self):
        self.C = []
        self.i2c.try_lock()
        try:
            for i in range(8):
                buf = bytearray(2)
                self.i2c.writeto_then_readfrom(self.address, bytes([self.CMD_PROM + (i * 2)]), buf)
                self.C.append((buf[0] << 8) | buf[1])
        finally:
            self.i2c.unlock()

    @property
    def temp_units(self):
        return self._temp_units

    @temp_units.setter
    def temp_units(self, value):
        if value:
            assert value in TEMP_UNITS, 'The temperature unit must be one of {}'.format(TEMP_UNITS)
            self._temp_units = value
        else:
            self._temp_units = None

    @property
    def pressure_units(self):
        return self._pressure_units

    @pressure_units.setter
    def pressure_units(self, value):
        if value:
            assert value in PRESSURE_UNITS, 'The pressure unit must be one of {}'.format(PRESSURE_UNITS)
            self._pressure_units = value
        else:
            self._pressure_units = None

    @property
    def temp_osr(self):
        return self._temp_osr

    @temp_osr.setter
    def temp_osr(self, value):
        assert value in self.OSRs.keys(), 'The sampling rate must be in the set {}'.format(self.OSRs.keys())
        self._temp_osr = self.OSRs[value]

    @property
    def pressure_osr(self):
        return self._pressure_osr

    @pressure_osr.setter
    def pressure_osr(self, value):
        assert value in self.OSRs.keys(), 'The sampling rate must be in the set {}'.format(self.OSRs.keys())
        self._pressure_osr = self.OSRs[value]

    def get_measurements(self, temp_osr=None, pressure_osr=None, temp_units=None, pressure_units=None):
        if not temp_osr:
            temp_osr = self.temp_osr
        else:
            self.temp_osr = temp_osr

        if not pressure_osr:
            pressure_osr = self.pressure_osr
        else:
            self.pressure_osr = pressure_osr

        if not temp_units:
            temp_units = self.temp_units
        else:
            self.temp_units = temp_units

        if not pressure_units:
            pressure_units = self.pressure_units
        else:
            self.pressure_units = pressure_units

        temp_raw = self._get_ADC_conversion(self.TEMPERATURE, temp_osr)
        pressure_raw = self._get_ADC_conversion(self.PRESSURE, pressure_osr)

        dT = temp_raw - (self.C[5] << 8)
        temp = ((dT * self.C[6]) >> 23) + 2000

        if temp < 2000:
            T2 = 3 * ((dT * dT) >> 33)
            OFF2 = 3 * ((temp - 2000) * (temp - 2000)) >> 1
            SENS2 = 5 * ((temp - 2000) * (temp - 2000)) >> 3

            if temp < -1500:
                OFF2 = OFF2 + 7 * ((temp + 1500) * (temp + 1500))
                SENS2 = SENS2 + (((temp + 1500) * (temp + 1500)) << 2)
        else:
            T2 = 7 * (dT * dT) >> 37
            OFF2 = ((temp - 2000) * (temp - 2000)) >> 4
            SENS2 = 0

        OFF = (self.C[2] << 16) + (((self.C[4] * dT)) >> 7)
        SENS = (self.C[1] << 15) + (((self.C[3] * dT)) >> 8)

        temp = temp - T2
        OFF = OFF - OFF2
        SENS = SENS - SENS2

        pressure = (((SENS * pressure_raw) >> 21) - OFF) >> 15

        if temp_units:
            temp = convert_temperature(temp, temp_units)
        if pressure_units:
            pressure = convert_pressure(pressure, pressure_units)

        return (temp, pressure)

    def _get_ADC_conversion(self, measurement, precision=None):
        self.i2c.try_lock()
        try:
            self.i2c.writeto(self.address, bytes([self.CMD_ADC_CONV + measurement + precision.address]))
            time.sleep(precision.sampling_time / 1000)
            buf = bytearray(3)
            self.i2c.writeto_then_readfrom(self.address, bytes([self.CMD_ADC_READ]), buf)
        finally:
            self.i2c.unlock()
        result = (buf[0] << 16) + (buf[1] << 8) + buf[2]

        return result

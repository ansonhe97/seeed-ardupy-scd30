# Seeed-ArduPy-scd30 [![Build Status](https://travis-ci.com/Seeed-Studio/seeed-ardupy-scd30.svg?branch=master)](https://travis-ci.com/Seeed-Studio/seeed-ardupy-scd30)

## Introduction

An ArduPy library forGrove - CO2 & Temperature & Humidity Sensor for Arduino (SCD30) - 3-in-1. The Grove - SCD30 is a 3-in-1 Arduino sensor that can measure CO2, temperature, and humidity. Based on Sensirion SCD30, it is a Non-Dispersive Infrared(NDIR) carbon dioxide sensor with high precision and wide measurement accuracy which can reach ±(30 ppm + 3%) between 400ppm to 10000ppm.



## How to binding with ArduPy

- Install [AIP](https://github.com/Seeed-Studio/ardupy-aip)
```shell
pip3 install aip
```
- Build firmware with Seeed ArduPy scd30
```shell
aip install https://github.com/Seeed-Studio/seeed-ardupy-scd30
aip build
```
- Flash new firmware to you ArduPy board
```shell
aip flash [Ardupy Bin PATH]
```
For more examples of using AIP, please refer to [AIP](https://github.com/Seeed-Studio/ardupy-aip).

## Usage

```python
from arduino import grove_scd30
import time

scd30 = grove_scd30()
while True:
    if(scd30.isAvailable()):
        data = scd30.getCarbonDioxideConcentration()
        print("\n-------SCD30 Data Set-------")
        print("Carbon Dioxide Concentration:", data[0])
        print("Temperature:", data[1])
        print("Humidity:", data[2])
    time.sleep(1)
```

## API Reference

- **isAvailable(void) : bool** - available

```py
if scd30.isAvailable():
    print("SCD30 is connected")
```

- **setAutoSelfCalibration(enable<bool>) : void** - Turn ON/OFF self calibration

```py
scd30.setAutoSelfCalibration(True)  # Enable auto self calibration
scd30.setAutoSelfCalibration(False) # Disable auto self calibration
```

- **setMeasurementInterval(interval<uint16_t>) : void** - Set the measurement interval

```py
scd30.setMeasurementInterval(2) # Sets measurement interval to 2s
```

- **startPeriodicMeasurment(void) : void** - Start periodic measurements

```py
scd30.startPeriodicMeasurment()
```

- **stopMeasurement(void) : void** - Stop measurements

```py
scd30.stopMeasurement()
```

- **setTemperatureOffset(offset<uint16_t>) : void** - Sets temperature offset

```py
scd30.setTemperatureOffset(0) # Set temperature offset
```

- **getCarbonDioxideConcentration(void)** : tuple - returns all 3 datas of CO2, temperature and humidity.

```py
data = scd30.getCarbonDioxideConcentration()
print(data[0]) # CO2
print(data[1]) # Temperature
print(data[2]) # Humidity
```


## License

This software is written by seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
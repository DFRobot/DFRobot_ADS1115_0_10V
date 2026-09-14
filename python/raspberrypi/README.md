# DFRobot_ADS1115_0_10V
- [中文版](./README_CN.md)

The product is a module that integrates the ADS1115 chip. The I2C and UART communication modes can be selected by the dial switch, and the I2C address of the module can also be switched by the dial switch. The external device can obtain two sets of voltage data with a resolution of 0.01mv through the gravity interface. This module can be used to accurately measure the DC voltage from 0 to 10v.


![effect picture](../../resources/images/DFR1184-1.png) 

## Product Link(https://www.dfrobot.com/)

## Table of Contents

* [Summary](#Summary)
* [Installation](#Installation)
* [Methods](#Methods)
* [Compatibility](#Compatibility)
* [History](#History)
* [Credits](#Credits)

## Summary

  * Get the voltage and choose to get the voltage of channel 1 or channel 2
  * Measurement voltage accuracy, 0.01mv


## Installation
To use this library, first download it to Raspberry Pi and then open the examples folder. To run an example, enter `python <example>.py` in the command line. For example, to run `get_value.py`, enter:<br>

```
python get_value.py
```



## Methods

```python
'''!
  @fn begin
  @brief Initializes the communication method
  @return True or False
'''
  def begin(self)

'''!
  @fn get_value
  @brief Getting voltage values
  @param channel Select channel 1 or channel 2
  @note Only 1 or 2 are valid; any other value returns 0
  @return Voltage in mV
'''
  def get_value(self, channel)

```

## Compatibility
|              |           |            |          |         |
| ------------ | --------- | ---------- | -------- | ------- |
| MCU          | Work Well | Work Wrong | Untested | Remarks |
| RaspberryPi2 |           |            | √        |         |
| RaspberryPi3 |           |            | √        |         |
| RaspberryPi4 | √         |            |          |         |

- Python version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | --------- | ---------- | -------- | ------- |
| Python2 | √         |            |          |         |
| Python3 | √         |            |          |         |


## History

- 2026/09/14 - Version 1.0.2 released.
- 2024/12/13 - Version 1.0.1 released.
- 2024/07/23 - Version 1.0.0 released.

## Credits

Written by lr(rong.li@dfrobot.com), 2024. (Welcome to our website)

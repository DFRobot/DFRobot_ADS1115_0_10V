'''
    @file get_value.py
    @brief Run this routine to get the voltage
    @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
    @license The MIT License (MIT)
    @author [lr](rong.li@dfrobot.com)
    @version V1.0.2
    @date 2026-09-14
    @url https://github.com/DFRobot/DFRobot_ADS1115_0_10V
'''
import time
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../')))

'''
Module DIP switches (set with power OFF):
1) I2C / UART mode switch — must match I2C_UART_FLAG below
   - I2C_UART_FLAG = "I2C"  -> set module switch to I2C
   - I2C_UART_FLAG = "UART" -> set module switch to UART
2) I2C address switch (A1/A0) — only used in I2C mode; ADDR must match silk screen
     A1 A0 | ADDR
      0  0 | 0x48
      0  1 | 0x49
      1  0 | 0x4A
      1  1 | 0x4B
'''
# I2C address: set SLAVE_ADDRESS to the value on the module silk screen (A1/A0)
SLAVE_ADDRESS = 0x48

# Set to "I2C" or "UART"; must match the module mode DIP switch
I2C_UART_FLAG = "I2C"
# I2C_UART_FLAG = "UART"
if I2C_UART_FLAG == "I2C":
    from DFRobot_ADS1115_0_10V import DFRobot_ADS1115_I2C
    ads1115 = DFRobot_ADS1115_I2C(1, SLAVE_ADDRESS)
else:
    from DFRobot_ADS1115_0_10V import DFRobot_ADS1115_UART
    ads1115 = DFRobot_ADS1115_UART("/dev/serial0")


def setup():
    while not ads1115.begin():
        if I2C_UART_FLAG == "I2C":
            print("Error: check wiring; set mode DIP to I2C; match SLAVE_ADDRESS with silk screen (A1/A0)!")
        else:
            print("Error: check wiring and set the module mode DIP switch to UART!")
        time.sleep(1)
    print("Successfully connected.")

def loop():
    channel = 1 #1 A1 2 A2
    print("channel%d adValue:%.2f  mv" %(channel ,ads1115.get_value(channel)))
    channel = 2 #1 A1 2 A2
    print("channel%d adValue:%.2f  mv" %(channel ,ads1115.get_value(channel)))
    time.sleep(1)


if __name__ == "__main__":
    try:
        setup()
        while True:
            loop()
    except KeyboardInterrupt:
        exit()

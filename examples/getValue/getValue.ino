/*!
 * @file getValue.ino
 * @brief Run this routine to get the voltage
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license      The MIT License (MIT)
 * @author [lr](rong.li@dfrobot.com)
 * @version V1.0.2
 * @date 2026-09-14
 * @url https://github.com/DFRobot/DFRobot_ADS1115_0_10V
 */
#include <DFRobot_ADS1115_0_10V.h>

/*
 * Module DIP switches (set with power OFF):
 * 1) I2C / UART mode switch — must match the code below
 *    - Uncomment I2C_COMMUNICATION  -> set module switch to I2C
 *    - Comment out I2C_COMMUNICATION -> set module switch to UART
 * 2) I2C address switch (A1/A0) — only used in I2C mode; ADDR must match silk screen
 */
// Use I2C; comment out the next line to use UART instead
#define I2C_COMMUNICATION

/*
 * I2C address: set MODULE_I2C_ADDRESS to the value on the module silk screen
 * (selected by A1/A0). Mismatch will cause begin() to fail.
 *   A1 A0 | ADDR
 *    0  0 | 0x48
 *    0  1 | 0x49
 *    1  0 | 0x4A
 *    1  1 | 0x4B
 */
#define MODULE_I2C_ADDRESS 0x48
#ifdef  I2C_COMMUNICATION
  DFRobot_ADS1115_I2C ads1115(&Wire, MODULE_I2C_ADDRESS);
  
 /* ---------------------------------------------------------------------------------------------------------------------
  *    board   |             MCU                | Leonardo/Mega2560/M0 |    UNO    | ESP8266 | ESP32 |  microbit  |   m0  |
  *     VCC    |            3.3V/5V             |        VCC           |    VCC    |   VCC   |  VCC  |     X      |  vcc  |
  *     GND    |              GND               |        GND           |    GND    |   GND   |  GND  |     X      |  gnd  |
  *     RX     |              TX                |     Serial1 TX1      |     5     |   5/D6  | 26/D3 |     X      |  tx1  |
  *     TX     |              RX                |     Serial1 RX1      |     4     |   4/D7  | 25/D2 |     X      |  rx1  |
  * ----------------------------------------------------------------------------------------------------------------------*/

#elif defined(ARDUINO_AVR_UNO) || defined(ESP8266)
  SoftwareSerial mySerial1(4, 5); 
  DFRobot_ADS1115_UART ads1115(&mySerial1);
#elif defined(ESP32)
  DFRobot_ADS1115_UART ads1115(&Serial1,/*rxD2*/25,/*txD3*/26);
#else
  DFRobot_ADS1115_UART ads1115(&Serial1);
#endif

void setup() {
    Serial.begin(9600);
    while (!ads1115.begin())
    {
#ifdef I2C_COMMUNICATION
      Serial.println("Error: check wiring; set mode DIP to I2C; match MODULE_I2C_ADDRESS with silk screen (A1/A0)!");
#else
      Serial.println("Error: check wiring and set the module mode DIP switch to UART!");
#endif
      delay(1000);
    }
}

void loop() {
  double data;
  unsigned char channel = 1;
  data= ads1115.getValue(channel);
  Serial.print(" channel:");
  Serial.print(channel);
  Serial.print(" adValue:");
  Serial.print(data);
  Serial.println("mv");

  delay(1000);
  channel = 2;
  data= ads1115.getValue(channel);
  Serial.print(" channel:");
  Serial.print(channel);
  Serial.print(" adValue:");
  Serial.print(data);
  Serial.println("mv");

  delay(1000);
}

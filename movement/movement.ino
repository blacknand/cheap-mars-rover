#include <avr/wdt.h>
#include <Arduino.h>
#include "DeviceDriverSet0.h"
#include "AppFuncSet0.cpp"

DeviceDriverSetMotor AppMotor;
App AppRover0;

void setup() {
  Serial.begin(9600);                                           // Initialise serial communication
  AppMotor.DeviceDriverSetMotorInit();
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    Serial.println("Recieved char ");
    Serial.println(c);
    if (c == 'w')
      AppFuncSetRoverMotionControl(FORWARD, 255);
    else if (c == 's')
      AppFuncSetRoverMotionControl(BACKWARD, 255);
    else if (c == 'd')
      AppFuncSetRoverMotionControl(RIGHT, 255);
    else if (c == 'a')
      AppFuncSetRoverMotionControl(LEFT, 255);
    else
      AppFuncSetRoverMotionControl(STOP, 0);
  }
}

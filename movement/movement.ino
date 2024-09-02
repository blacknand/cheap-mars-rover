// <movement.ino> listens for serial input and controls the rover


#include <avr/wdt.h>
#include <Arduino.h>
#include "DeviceDriverSet0.h"
#include "AppFuncSet0.h"


DeviceDriverSetMotor AppMotor;
App AppRover0;


void setup() {
  Serial.begin(9600);
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

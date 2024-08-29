#include <avr/wdt.h>
#include "DeviceDriverSet0.h"
#include "AppFuncSet0.cpp"            // not sure if arduino requires importing .cpp files, or if you need to link them?

DeviceDriverSetMotor AppMotor;
App AppRover0;

void setup() {
  AppMotor.DeviceDriverSetMotorInit();
  delay(2000);

  for (AppRover0.MotionControl = 0; AppRover0.MotionControl < 9;
       AppRover0.MotionControl = AppRover0.MotionControl + 1) {
          Serial.println("moving rover");
          AppFuncSetRoverMotionControl(AppRover0.MotionControl, 255);
          delay(1000);
  }
}

void loop() {

}

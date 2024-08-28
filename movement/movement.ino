#include <avr/wdt.h>
#include "DeviceDriverSet0.h"
#include "AppFuncSet0.cpp"            // not sure if arduino requires importing .cpp files, or if you need to link them?

DeviceDriverSetMotor AppMotor;
App AppRover0;

void setup() {
  AppMotor.DeviceDriverSetMotorInit();
  delay(2000);

  for (AppRover.MotionControl = 0; AppRover.MotionControl < 9;
       AppRover.MotionControl++) {
          AppFuncSetRoverMotionControl(AppRover.MotionControl, 255);
          delay(1000);
  }
}

void loop() {

}

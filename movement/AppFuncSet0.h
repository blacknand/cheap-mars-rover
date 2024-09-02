#include "DeviceDriverSet0.h"

extern DeviceDriverSetMotor AppMotor;

enum RoverControlMotion {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  LEFT_FORWARD,
  LEFT_BACKWARD,
  RIGHT_FORWARD,
  RIGHT_BACKWARD,
  STOP
};

struct App {
  RoverControlMotion MotionControl;
};

extern App AppRover0;

void AppFuncSetRoverMotionControl(RoverControlMotion direction, uint8_t speed);
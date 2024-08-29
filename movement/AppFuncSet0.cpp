#include "DEviceDriverSet0.h"

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

static void AppFuncSetRoverMotionControl(RoverControlMotion direction, uint8_t speed) {
  static uint8_t directionRecord = 0;
  uint8_t Kp, UpperLimit;

  switch (direction) {
    case FORWARD:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_JUST, speed, DIRECTION_JUST, speed, CONTROL_ENABLE);
      break;
    case BACKWARD:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_BACK, speed, DIRECTION_BACK, speed, CONTROL_ENABLE);
      break;
    case LEFT:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_JUST, speed, DIRECTION_BACK, speed, CONTROL_ENABLE);
      break;
    case RIGHT:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_BACK, speed, DIRECTION_JUST, speed, CONTROL_ENABLE);
      break;
    case LEFT_FORWARD:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_JUST, speed, DIRECTION_JUST, speed / 2, CONTROL_ENABLE);
      break;
    case RIGHT_FORWARD:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_JUST, speed / 2, DIRECTION_JUST, speed, CONTROL_ENABLE);
      break;
    case LEFT_BACKWARD:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_BACK, speed, DIRECTION_BACK, speed / 2, CONTROL_ENABLE);
      break;
    case RIGHT_BACKWARD:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_BACK, speed / 2, DIRECTION_BACK, speed, CONTROL_ENABLE);
      break;
    case STOP:
      AppMotor.DeviceDriverSetMotorControl(DIRECTION_VOID, 0, DIRECTION_VOID, 0, CONTROL_ENABLE);
      break;
    default:
      break;
  }
}

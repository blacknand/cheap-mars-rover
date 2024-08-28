extern DeviceDriverSetMotor AppMotor;
extern App AppRover0;

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
}

static void AppFuncSetRoverMotionControl(RoverControlMotion direction, uint8_t speed) {}

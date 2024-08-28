#include "DeviceDriverSet0.h"

// Initialise pins for motor control
void DeviceDriverSetMotor::DeviceDriverSetMotorInit() {
  pinMode(PIN_MOTOR_STBY, OUTPUT);
  pinMode(PIN_MOTOR_PWMA, OUTPUT);
  pinMode(PIN_MOTOR_PWMB, OUTPUT);
  pinMode(PIN_MOTOR_AIN1, OUTPUT);
  pinMode(PIN_MOTOR_BIN1, OUTPUT);
}


void DeviceDriverSetMotor::DeviceDriverSetMotorControl(bool directionA, uint8_t speedA,       // Motor A
                                                       bool directionB, uint8_t speedB,       // Motor B
                                                       bool controlLED) {                     // AB enable true

}
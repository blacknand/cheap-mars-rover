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
  if (controlLED == CONTROL_ENABLE) {
    digitalWrite(PIN_MOTOR_STBY, HIGH);

    switch (directionA) {
      case DIRECTION_JUST:
        digitalWrite(PIN_MOTOR_AIN1, HIGH);
        digitalWrite(PIN_MOTOR_PWMA, speedA);
        break;
      case DIRECTION_BACK:
        digitalWrite(PIN_MOTOR_AIN1, LOW);
        digitalWrite(PIN_MOTOR_PWMA, speedA);
        break;
      case DIRECTION_VOID:
        analogWrite(PIN_MOTOR_PWMA, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;
      default:
        analogWrite(PIN_MOTOR_PWMA, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;
    }

    switch (directionB) {
      case DIRECTION_JUST:
        digitalWrite(PIN_MOTOR_BIN1, HIGH);
        digitalWrite(PIN_MOTOR_PWMB, speedA);
        break;
      case DIRECTION_BACK:
        digitalWrite(PIN_MOTOR_BIN1, LOW);
        digitalWrite(PIN_MOTOR_PWMB, speedA);
        break;
      case DIRECTION_VOID:
        analogWrite(PIN_MOTOR_PWMB, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;
      default:
        analogWrite(PIN_MOTOR_PWMB, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;
    }
  } else {
    digitalWrite(PIN_MOTOR_STBY, LOW);
    return;
  }
}
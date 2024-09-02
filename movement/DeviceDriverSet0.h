#ifndef _DeviceDriverSet0H_
#define _DeviceDriverSet0H_

#include <Arduino.h>


// Motor
class DeviceDriverSetMotor {
  public:
    void DeviceDriverSetMotorInit();
    #if _Test_DeviceDriverSet
    void DeviceDriverSetMotorTest();
    #endif
    void DeviceDriverSetMotorControl(bool directionA, uint8_t speedA,
                                     bool directionB, uint8_t speedB,
                                     bool controlLED);
  private:
    // Flag variables
    #define PIN_MOTOR_PWMA    5
    #define PIN_MOTOR_PWMB    6
    #define PIN_MOTOR_BIN1    8
    #define PIN_MOTOR_AIN1    7
    #define PIN_MOTOR_STBY    3
  
  public:

    // Motor rotation direction flags
    #define SPEED_MAX         255
    #define DIRECTION_JUST    true        // Motor forward
    #define DIRECTION_BACK    false       // Motor backward
    #define DIRECTION_VOID    3
    
    // Other functional flags
    #define DURATION_ENABLE  true
    #define DURATION_DISABLE false
    #define CONTROL_ENABLE   true
    #define CONTROL_DISABLE  false
};

#endif
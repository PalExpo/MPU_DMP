#ifndef DMP_H
#define DMP_H
#include "Arduino.h"

#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#define OUTPUT_READABLE_YAWPITCHROLL
#define INTERRUPT_PIN 4
#define Xgyro 220
#define Ygyro 76
#define Zgyro -85
#define Zaccel 1788  // 1688 factory default for my test chip

class dmp {
  public:
    dmp();
    void wire_clockset();
    void Init();
    float getZ();
    float getypr(uint8_t choose);
  private:
    bool dmpReady = false;
    uint8_t mpuIntStatus;
    uint8_t devStatus;
    uint8_t packetSize;
    uint16_t fifoCount;
    uint8_t fifoBuffer[64];
    Quaternion q;
    VectorFloat gravity;
    float ypr[3];
    uint8_t choose_;
};

#endif

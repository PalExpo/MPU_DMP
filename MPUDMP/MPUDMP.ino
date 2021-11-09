#include "dmp.h"

#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
dmp mpudmp;

void setup() {
  mpudmp.wire_clockset();
  Serial.begin(115200);
  mpudmp.Init();
}

void loop() {
  Serial.println(mpudmp.getypr(0));
}

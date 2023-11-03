#ifndef MPU6050_UTILS_H
#define MPU6050_UTILS_H

//#include <Arduino.h>
#define MPU6050_ADDRESS 0x68
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define GYRO_SCALE 65.5  // for +/- 500 degrees/s range
#define ACCEL_SCALE 4096.0  // for +/- 8g range

float     rateRoll, ratePitch, rateYaw;
float     rateCalibrationRoll = 0, rateCalibrationPitch = 0, rateCalibrationYaw = 0;
float     angleRoll, anglePitch;

#endif
#include "mpu6050_utils.h"
#include <Wire.h>


float     rateCalibrationRoll = 0; 
float     rateCalibrationPitch = 0;
float     rateCalibrationYaw = 0;
float     angleRoll, anglePitch;
float     ratePitch, rateYaw, rateRoll;

static float     accX, accY, accZ;

static void  get_gyro_values(void)
{
  //request 6 bytes from 0x43 to 0x48 (Gyroscope)
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDRESS, 6);

  // read values
  int16_t gyroX = Wire.read() << 8 | Wire.read();
  int16_t gyroY = Wire.read() << 8 | Wire.read();
  int16_t gyroZ = Wire.read() << 8 | Wire.read();

  //convert raw vales to degrees/sec
  rateRoll = (float)gyroX / GYRO_SCALE;
  ratePitch = (float)gyroY / GYRO_SCALE;
  rateYaw = (float)gyroZ / GYRO_SCALE;
}

static void  get_accel_values(void)
{
  // request 6 bytes from 3B to 40 (Accelerometer)
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDRESS, 6);
  //read values
  int16_t accXLSB = Wire.read() << 8 | Wire.read();
  int16_t accYLSB = Wire.read() << 8 | Wire.read();
  int16_t accZLSB = Wire.read() << 8 | Wire.read();
  // convert from lsb/g to g
  accX = accXLSB / ACCEL_SCALE - 0.03;
  accY = accYLSB / ACCEL_SCALE + 0.02;
  accZ = accZLSB / ACCEL_SCALE + 0.11;
}

void  get_mpu_signals(void)
{
  get_gyro_values();
  get_accel_values();
  // get roll and pitch angle
  angleRoll = atan(accY / sqrt(accX*accX+accZ*accZ)) * 180 / PI;
  anglePitch = -atan(accX / sqrt(accY*accY+accZ*accZ)) * 180 / PI;
}

void  init_gyro_com(void)
{
  Wire.setClock(400000); //MPU6050 specific
  Wire.begin();
  // Wake up the MPU6050
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();

  // Set gyro sensitivity 65.5 LSB/deg/sec
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x08);
  Wire.endTransmission();

  // Set accelerometer sensitivity to +/- 8g
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x10);
  Wire.endTransmission();
}

void  calibrateGyro(void)
{
  for(int i = 0; i < 2000; i++){
    get_mpu_signals();
    rateCalibrationPitch += ratePitch;
    rateCalibrationRoll += rateRoll;
    rateCalibrationYaw += rateYaw;
  }
  rateCalibrationPitch /= 2000;
  rateCalibrationRoll /= 2000;
  rateCalibrationYaw /= 2000;
}
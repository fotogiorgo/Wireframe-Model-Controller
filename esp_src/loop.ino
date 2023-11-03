#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Kalman_filter.h"
#define MPU6050_ADDRESS 0x68
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define GYRO_SCALE 65.5  // for +/- 500 degrees/s range
#define ACCEL_SCALE 4096.0  // for +/- 8g range

#define SSID "ESP8266_AP"
#define PASSWORD "password"
unsigned int localPort = 8888; // Port to listen on
WiFiUDP udp;

float     rateRoll, ratePitch, rateYaw;
float     rateCalibrationRoll = 0, rateCalibrationPitch = 0, rateCalibrationYaw = 0;
float     accX, accY, accZ;
float     angleRoll, anglePitch;
uint32_t  timeStamp;
float     kalmanAngleRoll = 0,                   //starting guess of 0 degrees
              kalmanUncertaintyAngleRoll = 2*2; //starting uncertainty of 2 degrees
float     kalmanAnglePitch = 0,
              kalmanUncertaintyAnglePitch = 2*2;
//output of the filter {prediction, uncertainty}

float     package[2];


/* void  Kalman1D( float kalmanState, float kalmanUncertainty, 
                float kalmanInput, float kalmanMeasurement)
{
  kalmanState = kalmanState + 0.004*kalmanInput;
  kalmanUncertainty = kalmanUncertainty + 0.004 * 0.004 * 4 * 4;
  float kalmanGain = kalmanUncertainty * 1 / (1*kalmanUncertainty + 3 * 3);
  kalmanState = kalmanState + kalmanGain * (kalmanMeasurement - kalmanState);
  kalmanUncertainty = (1-kalmanGain) * kalmanUncertainty;
  kalman1DOutput[0] = kalmanState;
  kalman1DOutput[1] = kalmanUncertainty;
} */

void  get_gyro_values(void)
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

void  get_accel_values(void)
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

void  initAPandUDPserver(void)
{
  WiFi.softAP(SSID, PASSWORD);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Start UDP server
  udp.begin(localPort);
  Serial.printf("UDP server started on port %d\n", localPort);
}

void setup() {
  Serial.begin(74880);
  init_gyro_com();
  initAPandUDPserver();
  delay(200);
  calibrateGyro();
  //timeStamp = micros();
}


void loop() {
  int packetSize = udp.parsePacket();
  while(packetSize){
    timeStamp = micros();
    get_mpu_signals();
    rateRoll -= rateCalibrationRoll;
    ratePitch -= rateCalibrationPitch;
    rateYaw -= rateCalibrationYaw;

    Kalman1D(&kalmanAngleRoll, &kalmanUncertaintyAngleRoll, rateRoll, angleRoll);

    Kalman1D(&kalmanAnglePitch, &kalmanUncertaintyAnglePitch, ratePitch, anglePitch);

/*     Serial.print("Roll = ");
    Serial.print(kalmanAngleRoll);
    Serial.print(" Pitch = ");
    Serial.println(kalmanAnglePitch); */

    package[0] = kalmanAngleRoll;
    package[1] = kalmanAnglePitch;
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.write((const char*)package, 8);
    udp.endPacket();

    while(micros() - timeStamp < 4000);
  }
}

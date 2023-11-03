#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Kalman_filter.h"
#include "mpu6050_utils.h"

#define SSID "ESP8266_AP"
#define PASSWORD "password"
#define LOCAL_PORT 8888 // Port to listen on
WiFiUDP udp;

uint32_t  timeStamp;
float     package[2];

void  initAPandUDPserver(void)
{
  WiFi.softAP(SSID, PASSWORD);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Start UDP server
  udp.begin(LOCAL_PORT);
  Serial.printf("UDP server started on port %d\n", LOCAL_PORT);
}

void setup() {
  Serial.begin(74880);
  init_gyro_com();
  initAPandUDPserver();
  delay(200);
  calibrateGyro();
  Serial.println("Waiting for communication.");
  while(!(udp.parsePacket()));
  Serial.println("Communication established.");
}

void loop() {
    timeStamp = micros();
    get_mpu_signals();
    rateRoll -= rateCalibrationRoll;
    ratePitch -= rateCalibrationPitch;
    rateYaw -= rateCalibrationYaw;

    Kalman1D(&kalmanAngleRoll, &kalmanUncertaintyAngleRoll, \
              rateRoll, angleRoll);
    Kalman1D(&kalmanAnglePitch, &kalmanUncertaintyAnglePitch, \
              ratePitch, anglePitch);

    package[0] = kalmanAngleRoll;
    package[1] = kalmanAnglePitch;
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.write((const char*)package, 8);
    udp.endPacket();

    while(micros() - timeStamp < 4000);
}

#include "Arduino.h"
#include "button.h"
#include "read_sensor.h"
#include "log_data.h"
#include "web_download.h"

Switch dipswitch;
RTC myrtc;
Gyro gyro;
Spiffs spiffs;

String payload;
byte angle_treshold;
int x, y, z;

void setup() {
  Serial.begin(115200);  // put your setup code here, to run once:
  dipswitch.begin();
  myrtc.begin();
  gyro.begin();
  spiffs.begin();

  xTaskCreate(dip_switch_task, "dip switch task", 1024, NULL, 1, NULL);
  xTaskCreate(gyro_task, "gyro task", 2048, NULL, 1, NULL);
  xTaskCreate(spiffs_task, "spiffs task", 2048, NULL, 1, NULL);

  while (1) {
    payload = "\n============================\n" +
              String("Angle Treshold => ") + String(angle_treshold) + " degree\n" +
              "x:" + String(x) + "\ty:" + String(y) + "\tz:" + String(z) +
              "\n============================\n";

    Serial.println(payload);
    //    spiffs.read_data();
    delay(1000);
  }
}

void dip_switch_task(void *parameter)
{
  for (;;) {
    dipswitch.read_dip();
    angle_treshold = dipswitch.set_degree();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void gyro_task(void *parameter)
{
  for (;;) {
    gyro.start();
    x = gyro.sudut_x();
    y = gyro.sudut_y();
    z = gyro.sudut_z();
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
}

void spiffs_task(void *parameter)
{
  for (;;) {
    spiffs.save_data(payload);
    Serial.println("\nData saved to SPIFFS\n");
    delay(1000);
    vTaskDelay(3000 / portTICK_PERIOD_MS);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

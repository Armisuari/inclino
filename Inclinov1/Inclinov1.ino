#include "Arduino.h"
#include "button.hpp"

Switch dipswitch;

void setup() {
  Serial.begin(115200);  // put your setup code here, to run once:
  dipswitch.begin();

  xTaskCreate(
      dip_switch_task,
      "dip switch task",
      5000,
      NULL,
      1,
      NULL);

  while (1) {}
}

void dip_switch_task(void *parameter)
{
  for(;;){
    dipswitch.read_dip();
    Serial.println(dipswitch.set_degree());
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

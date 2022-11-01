#include "Arduino.h"
#include "button.hpp"

void setup() {
  Serial.begin(115200);  // put your setup code here, to run once:
  Switch A;

  while (1) {
    A.read_dip();
    delay(10);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
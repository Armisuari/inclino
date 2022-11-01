// input using switch : dip switch & push button
#pragma once

byte dip_switch[4] = { 2, 4, 18, 19 };
byte read_switch[4];
String show_dip;

struct Switch {
  Switch() {}

  void begin() {
    Serial.println(F("\n\ninitializing input pins"));
    for (byte i = 0; i < 5; i++) {
      pinMode(dip_switch[i], INPUT);
    }
  }

  void read_dip() {
    for (byte i = 0; i < 5; i++) {
      read_switch[i] = digitalRead(dip_switch[i]);
    }

    show_dip = String(read_switch[0]) + String(read_switch[1]) + String(read_switch[2]) + String(read_switch[3]);
    Serial.println(show_dip);
  }

  byte set_degree() {
    if (show_dip == "0111") {
      Serial.println(F("setpoint set to 15 degree"));
      return 15;
    } else if (show_dip == "1011") {
      Serial.println(F("setpoint set to 20 degree"));
      return 20;
    } else if (show_dip == "1101") {
      Serial.println(F("setpoint set to 45 degree"));
      return 45;
    } else if (show_dip == "1110") {
      Serial.println(F("setpoint set to 60 degree"));
      return 60;
    } else {
      Serial.println(F("setpoint not ready"));
      return 0;
    }
  }
};
// input using switch : dip switch & push button

#pragma once

byte dip_switch[4] = { 2, 4, 18, 19 };
byte read_switch[4];
String show_dip;

struct Switch {
  Switch(){
    Serial.println(F("\n\ninitializing input pins"));

    for (byte i = 0; i < 5; i++) {
      pinMode(dip_switch[i], INPUT);
    }
  }

  void read_dip()
  {
    for(byte i = 0; i<5; i++)
    {
      read_switch[i] = digitalRead(dip_switch[i]);
    }

    show_dip = String(read_switch[0]) + String(read_switch[1]) + String(read_switch[2]) + String(read_switch[3]);
    Serial.println(show_dip);
  }
};
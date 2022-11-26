// header file for leds and buzzer

#pragma once

#define relay1 25
#define relay2 26
#define indicatorfree 27

struct Indi {
  Indi() {}

void begin() {
  pinMode (relay1,OUTPUT);
  pinMode (relay2, OUTPUT);
  pinMode (indicatorfree, OUTPUT);
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(indicatorfree,LOW);
}

void high(){
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(indicatorfree,HIGH);
  Serial.println("Relay High");
}

void low(){
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(indicatorfree,LOW);
  Serial.println("Relay Low");
}

};

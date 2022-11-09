#pragma once

#include "SPIFFS.h"
#include <SPI.h>
#include "FS.h"

bool    SPIFFS_present = false;

void readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return;
  }

  Serial.println("- read from file:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

struct Spiffs {
  Spiffs() {}

  void begin() {
    if (!SPIFFS.begin(true)) {
      Serial.println("SPIFFS initialisation failed...");
      SPIFFS_present = false;
    }
    else
    {
      Serial.println(F("SPIFFS initialised... file access enabled..."));
      SPIFFS_present = true;
    }
  }

  void save_data(String payload) {
    File file = SPIFFS.open("/Datalog.txt", FILE_WRITE);
    file.print(payload);
    file.close();
  }

  void read_data() {
    readFile(SPIFFS, "/Datalog.txt");
  }
};

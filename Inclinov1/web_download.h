#pragma once
#ifdef ESP8266
#include <ESP8266WiFi.h>       // Built-in
#include <ESP8266WebServer.h>  // Built-in
#else
#include <WiFi.h>              // Built-in
#include <WebServer.h>
#endif

#define ServerVersion "1.0"
String  webpage = "";

const char* ssid     = "ESP32-AP";
const char* password = "1234567890";

#include "FS.h"
#include "webserver/CSS.h"
#include <SPI.h>

#ifdef ESP8266
ESP8266WebServer server(80);
#else
WebServer server(80);
#endif

struct Web_server {
  Web_server() {}

  void begin() {
    WiFi.softAP(ssid, password);
    Serial.println("Connecting ...");
    Serial.println("\nConnected to " + WiFi.softAPSSID() + " Use IP address: " + WiFi.softAPIP().toString()); // Report which SSID and IP is in use

    //----------------------------------------------------------------------
    ///////////////////////////// Server Commands
//    server.on("/",         HomePage);
//    server.on("/download", File_Download);
//    server.on("/upload",   File_Upload);
//    server.on("/fupload",  HTTP_POST, []() {
//      server.send(200);
//    }, handleFileUpload);
//    server.on("/stream",   File_Stream);
//    server.on("/delete",   File_Delete);
//    server.on("/dir",      SPIFFS_dir);
//
//    ///////////////////////////// End of Request commands
//    server.begin();
//    Serial.println("HTTP server started");
  }
};

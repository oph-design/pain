#include <WiFI.h>
#include "ESPAsyncWebServer.h"

const char* ssid     = "Test_ESP32";
const char* password = "12345678";
AsyncWebServer server(80);

void setup()
{
    Serial.begin(115200);
    Serial.println("\n[*] Creating AP");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.print("[+] AP Created with IP Gateway ");
    Serial.println(WiFi.softAPIP());
    server.on("/hi", HTTP_GET, [](AsyncWebServerRequest *request){
      Serial.println("I LOVE http request");
    });
    server.begin();
}

void loop(){
  
} 

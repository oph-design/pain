#include "WiFi.h"
#include <HTTPClient.h>
#define input 23
 
const char* ssid = "Test_ESP32";
const char* password =  "12345678";
int state;
int last_state = HIGH;
HTTPClient http;

 
void setup() {
 
  Serial.begin(115200);
  pinMode(input, INPUT_PULLUP);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  http.begin("http://192.168.4.1/hi");
} 

void loop() {
  state = digitalRead(input);
  if(state == HIGH && last_state == LOW){
    //Specify the URL
    http.GET();
  }
  last_state = state;
}

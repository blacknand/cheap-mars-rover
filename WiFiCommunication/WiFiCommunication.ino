#include <WiFi.h>
#include "WiFiInfo.h"

const char* ssid = "Sparky";
const char* password = "Sparky123";

void setup() {
	Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Starting connection to WiFi network ");
  Serial.println(ssid);
  Serial.println("\n");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi network ")
    Serial.println(ssid);
    Serial.println("...\n");
    delay(100);
  }

  Serial.println("Connected to WiFi network ");
  Serial.println(ssid);
  GetNetworkInfo();
}

void loop() {}

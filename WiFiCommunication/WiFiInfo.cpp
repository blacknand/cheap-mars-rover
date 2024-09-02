#include <WiFi.h>
#include <Arduino.h>
#include "WiFiInfo.h"


void GetNetworkInfo() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("-----------------------------------------------------");
    Serial.println("[*] WiFi network information for ")
    Serial.println(ssid);
    Serial.println("[+] BSSID: " + WiFi.BSSIDstr());
    Serial.print("[+] Gateway IP: ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("[+] Subnet Mask: ");
    Serial.println(WiFi.subnetMask());
    Serial.println((String)"[+] RSSI: " + WiFi.RSSI() + " dB");
    Serial.print("[+] ESP32 IP: ");
    Serial.println(WiFi.localIP());
    Serial.println("-----------------------------------------------------");
  } else 
    Serial.println("GetNetworkInfo: not connected to WiFi network");
}
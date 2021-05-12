#include <Wire.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "RTClib.h"
#include "data.h"

const char* ssid = "ABC";
const char* password = "0681845040";
unsigned long lastSendToServer = 0;
unsigned long lastTransmit = 0;
unsigned long lastReceive = 0;

WiFiClient espClient;
PubSubClient client(espClient);
CyberPlantData cpd;
RTC_Millis rtc;

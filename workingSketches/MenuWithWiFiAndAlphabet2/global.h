#include <PubSubClient.h>
#include <WiFi.h>
#include "RTClib.h"
#include "data.h"

#define MQTT_SERVER "b85b0aa3fd23.sn.mynetname.net"
#define UID "a4b4"


#define SEND_TO_SERVER_EVERY 1000ULL
#define TRANSMIT_EVERY 1000ULL
#define ARDUINO_ADRESS 126


const char* ssid = "ABC";
const char* password = "0681845040";
unsigned long lastSendToServer = 0;
unsigned long lastTransmit = 0;
unsigned long lastReceive = 0;
bool buttonIsPressed = false;

WiFiClient espClient;
PubSubClient client(espClient);
CyberPlantData cpd;
RTC_Millis rtc;

#include <PubSubClient.h>
#include <WiFi.h>
#include "RTClib.h"
#include "data.h"
#include <Preferences.h>
#include "CDRelayRegulator.h"
#include "CDPidRegulator.h"
#include "CDSoilMoistureSensor.h"
#include <LC_I2C.h>
#include <LCDMenuLib2.h>
#include <ESP32Encoder.h>
#include "Button2.h";

#define MQTT_SERVER "b85b0aa3fd23.sn.mynetname.net"                       // адреса MQTT брокера
#define SEND_TO_SERVER_EVERY                                  1000ULL     // частота надсилання даних на сервер
#define ADC_MAX                                               1023        // роздільна здатність АЦП
#define _LCDML_cfg_use_ram                                                // режим використання оперативної пам'яті
#define _LCDML_DISP_cols                                      20          // кількість літер в рядку дисплея
#define _LCDML_DISP_rows                                      4           // кількість рядків дисплея
#define _LCDML_DISP_cfg_cursor                                0x7E        // символ курсору
#define _LCDML_DISP_cfg_scrollbar                             1           // включити прокрутку збоку

const int chId[] = {0, 1, 2, 3};
const int chFreq[] = {1000, 1000, 1000, 1000};
const int chResolution[] = {16, 16, 16, 16};
const int chPin[] = {0, 4, 16, 17};
int sensors[4] = {34, 35, 32, 33};
int relay[4] = {0, 4, 16, 17};

const char* ssid = "ABCD";
const char* password = "0681845040";
unsigned long lastSendToServer = 0;
unsigned long lastTransmit = 0;
unsigned long lastReceive = 0;
bool buttonIsPressed = false;
bool longPress = false;
int pastHour = 0;
byte activeHoursCounter = 0;

WiFiClient espClient;                                                     // WiFi клієнт, для створення зв'язку із точкою доступу
PubSubClient client(espClient);                                           // Бібліотека із реалізацією MQTT клієнта (використовує WiFi клієнт бібліотеку)
CyberPlantData cpd;                                                       // Власна Бібліотека з даними
RTC_Millis rtc;                                                           // Бібліотека годинника
Preferences memory;                                                       // Бібілотека EEPROM постійної пам'яті
CDSoilMoistureSensor sensor = CDSoilMoistureSensor(34, 35, 32, 33, 100);  // Власна Бібліотека ємнісного сенсора
CDRelayRegulator reg[] = {                                                // Власна Бібліотека релейного регулятора
  CDRelayRegulator(INCREASING),
  CDRelayRegulator(INCREASING),
  CDRelayRegulator(INCREASING),
  CDRelayRegulator(INCREASING)
};
CDPidRegulator pid[] = {                                                  // Власна Бібліотека Пропорційно-Інтегрально-Диференціального регулятора
  CDPidRegulator(),
  CDPidRegulator(),
  CDPidRegulator(),
  CDPidRegulator()
};
LC_I2C lcd(0x27, 20, 4);
ESP32Encoder encoder;
Button2 button = Button2(5);

const uint8_t scroll_bar[5][8] = {
  {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001},       
  {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, 
  {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, 
  {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, 
  {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  
};

void lcdml_menu_display();
void lcdml_menu_clear();
void lcdml_menu_control();

LCDMenuLib2_menu LCDML_0 (255, 0, 0, NULL, NULL); // root menu element (do not change)
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);

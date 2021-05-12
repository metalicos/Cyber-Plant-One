#include "macros.h"

// Структура даних необхідна для простого збереження та передачі даних між
// мікроконтролерами
struct CyberPlantData {

  bool channelType[6] = {0, 0, 0, 0, 0, 0};               // Тип каналу
  bool channelLogic[6] = {0, 0, 0, 0, 0, 0};              // Логіка каналу (Контроль 0 або контроль 1)
  uint8_t channelValue[6] = {0, 0, 0, 0, 0, 0};           // Рівень відкритості каналу (для димера 0-255) (для реле 1 або 0)
  uint8_t channelControlMode[6] = {0, 0, 0, 0, 0, 0};     // Режим контролю (Ручний, ПІД)

  float pidKp[6] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1};        // Під коефіцієнт P
  float pidKi[6] = {0.05, 0.05, 0.05, 0.05, 0.05, 0.05};  // Під коефіцієнт I
  float pidKd[6] = {0.01, 0.01, 0.01, 0.01, 0.01, 0.01};  // Під коефіцієнт D
  uint16_t pidDt[6] = {10, 10, 10, 10, 10, 10};           // Під період дискретизації dt в мілісекундах
  bool pidDirection[6] = {0, 0, 0, 0, 0, 0};              // Під напрямок регулювання

  uint8_t analogSensorType[6] = {0, 0, 0, 0, 0, 0};       // Тип аналогових сенсорів
  uint32_t analogSensorData[6] = {0, 0, 0, 0, 0, 0};      // Дані із аналогових сенсорів
  uint32_t sensorControlValue[6]  = {0, 0, 0, 0, 0, 0};   // Підтримуване значення сенсорів ПІД регуляторами

  float ph = 0;                                           // Рівень кислотності рідини Ph
  float waterTemperature = 0;                             // Температура рідини
  float ec = 0;                                           // Електропровідність рідини
  uint32_t tds = 0;                                       // Кількість одиниць солі на мільйон одиниць рідини (parts per million) ppm

  float pressure = 0;                                     // Рівень атмосферного тиску
  float airHumidity = 0;                                  // Рівень відносної вологості повітря
  float airTemperature = 0;                               // Рівень температури повітря
  float altitude = 0;                                     // Висота над рівнем моря в метрах

  bool sound = false;                                     // Режим звуку
  bool waterCheck = false;                                // Режим перевірки води
  bool sleep = false;                                     // Режим сну
  uint16_t sleepAfter = 0;                                // Перейти в режим сну після мс
  uint16_t sendDataToServerEvery = 1000;                  // Надсилати дані на сервер кожних мс
  uint16_t checkSensorEvery = 1000;                       // Перевіряти сенсори кожних мс
  bool screenLight = true;                                // Підсвітка екрану

  uint8_t dateSecond;                                     // Час секунда
  uint8_t dateMinute;                                     // Час хвилина
  uint8_t dateHour;                                       // Час година
  uint8_t dateDay;                                        // Час день
  uint8_t dateMonth;                                      // Час місяць
  uint16_t dateYear;                                      // Час рік

  String channelName[6] = {
    "Channel 1",                                          // Назва каналу 1
    "Channel 2",                                          // Назва каналу 2
    "Channel 3",                                          // Назва каналу 3
    "Channel 4",                                          // Назва каналу 4
    "Channel 5",                                          // Назва каналу 5
    "Channel 6"                                           // Назва каналу 6
  };
  String wifiSSID = "SSID";                               // Назва точки дуступу
  String wifiPASS = "PASS";                               // Пароль до точки доступу
  const char *uId = UID;                                  // Унікальний номер пристрою Cyber Done

  CyberPlantData() {}
  ~CyberPlantData() {}

};

union CyberPlantDataUnion {
  CyberPlantData data;
  byte bytes[sizeof(CyberPlantData)];

  CyberPlantDataUnion() { memset(this, 0, sizeof(*this)); }
  ~CyberPlantDataUnion(){}
};

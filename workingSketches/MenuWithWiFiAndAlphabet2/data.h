#include "macros.h"
#define UID "a4b4"
struct CyberPlantData {

  // 24
  uint32_t pidKp[6] = {100, 100, 100, 100, 100, 100};     // Під коефіцієнт P
  uint32_t pidKi[6] = {50, 50, 50, 50, 50, 50};           // Під коефіцієнт I
  uint32_t pidKd[6] = {10, 10, 10, 10, 10, 10};           // Під коефіцієнт D
  uint32_t pidDt[6] = {10, 10, 10, 10, 10, 10};           // Під період дискретизації dt в мілісекундах
  uint32_t analogSensorData[6] = {0, 0, 0, 0, 0, 0};      // Дані із аналогових сенсорів
  uint32_t sensorControlValue[6]  = {0, 0, 0, 0, 0, 0};   // Підтримуване значення сенсорів ПІД регуляторами
  // 20
  char wifiSSID[20] = {'S','S','I','D','\0'};                       // Назва точки дуступу
  char wifiPASS[20] = {'P','A','S','S','\0'};                       // Пароль до точки доступу
  const char uId[20] = UID;                               // Унікальний номер пристрою Cyber Done
  // 6
  uint8_t channelType[6] = {0, 0, 0, 0, 0, 0};            // Тип каналу
  uint8_t channelLogic[6] = {0, 0, 0, 0, 0, 0};           // Логіка каналу (Контроль 0 або контроль 1)
  uint8_t channelValue[6] = {0, 0, 0, 0, 0, 0};           // Рівень відкритості каналу (для димера 0-255) (для реле 1 або 0)
  uint8_t channelControlMode[6] = {0, 0, 0, 0, 0, 0};     // Режим контролю (Ручний, ПІД)
  uint8_t pidDirection[6] = {0, 0, 0, 0, 0, 0};           // Під напрямок регулювання
  uint8_t analogSensorType[6] = {0, 0, 0, 0, 0, 0};       // Тип аналогових сенсорів
  // 4
  uint32_t ph = 0;                                        // Рівень кислотності рідини Ph
  uint32_t waterTemperature = 0;                          // Температура рідини
  uint32_t ec = 0;                                        // Електропровідність рідини
  uint32_t tds = 0;                                       // Кількість одиниць солі на мільйон одиниць рідини (parts per million) ppm
  uint32_t pressure = 0;                                  // Рівень атмосферного тиску
  uint32_t airHumidity = 0;                               // Рівень відносної вологості повітря
  uint32_t airTemperature = 0;                            // Рівень температури повітря
  uint32_t altitude = 0;                                  // Висота над рівнем моря в метрах
  // 2
  uint16_t sleepAfter = 0;                                // Перейти в режим сну після мс
  uint16_t sendDataToServerEvery = 1000;                  // Надсилати дані на сервер кожних мс
  uint16_t checkSensorEvery = 1000;                       // Перевіряти сенсори кожних мс
  uint16_t dateYear;                                      // Час рік
  // 1
  uint8_t sound = false;                                  // Режим звуку
  uint8_t waterCheck = false;                             // Режим перевірки води
  uint8_t sleep = false;                                  // Режим сну
  uint8_t screenLight = true;                             // Підсвітка екрану
  uint8_t dateSecond;                                     // Час секунда
  uint8_t dateMinute;                                     // Час хвилина
  uint8_t dateHour;                                       // Час година
  uint8_t dateDay;                                        // Час день
  uint8_t dateMonth;                                      // Час місяць

};


template <typename T> void copy(T *a, T *b, uint16_t n) {
  uint16_t i;
  for (i = 0; i < n; i++)
    a[i] = b[i];
}

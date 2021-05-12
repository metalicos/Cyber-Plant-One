#include "macros.h"
#define UID "a4b4"
struct CyberPlantData {
  bool channelType[4] = {0, 0, 0, 0};                                         // Тип каналу (Реле / Диммер) 
  bool channelLogic[4] = {0, 0, 0, 0};                                        // Логіка каналу (Логічний 0 або лог. 1)
  double analogSensorData[4] = {0.0, 0.0, 0.0, 0.0};                          // Значення сенсорів у реальному часі
  double maintainValue[4]  = {30.0, 30.0, 30.0, 30.0};                        // Підтримуване значення сенсорів регуляторами
  uint16_t channelValue[4] = {0, 0, 0, 0};                                    // Рівень відкритості каналу (для димера 0-65535) (для реле 1 або 0)
  uint8_t channelControlMode[4] = {0, 0, 0, 0};                               // Режим контролю (Ручний, Регулятор ...)
  
  bool pidDirection[4] = {0, 0, 0, 0};                                        // Напрямок регулювання пропорційно-інтегрально-диференціального регулятора
  double pidKp[4] = {0.1, 0.1, 0.1, 0.1};                                     // Пропорційна складова
  double pidKi[4] = {0.05, 0.05, 0.05, 0.05};                                 // Інтегральна складова
  double pidKd[4] = {0.01, 0.01, 0.01, 0.01};                                 // Диференціальна складова
  uint32_t pidDt[4] = {1000, 1000, 1000, 1000};                               // Час дискретизації

  bool relayDirection[4] = {0, 0, 0, 0};                                      // Напрямок регулювання релейного регулятора на гістерезисі
  double relayHysteresis[4] = {5.0, 5.0, 5.0, 5.0};                           // значення гістерезису
  double relayK[4] = {0.5, 0.5, 0.5, 0.5};                                    // коефіцієнт інерційності системи
  uint32_t relayDt[4] = {500, 500, 500, 500};                                 // час ітерації 
  

  bool sound = false;                                                         // Режим звуку
  bool waterCheck = false;                                                    // Режим перевірки води
  bool sleep = false;                                                         // Режим сну
  uint16_t sleepAfter = 0;                                                    // Перейти в режим сну після мс
  bool screenLight = true;                                                    // Підсвітка екрану
    
  uint8_t dateSecond;                                                         // Час секунда
  uint8_t dateMinute;                                                         // Час хвилина
  uint8_t dateHour;                                                           // Час година
  uint8_t dateDay;                                                            // Час день
  uint8_t dateMonth;                                                          // Час місяць
  uint16_t dateYear;                                                          // Час рік

  char wifiSSID[20] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}; // Назва точки дуступу
  char wifiPASS[20] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}; // Пароль до точки доступу

  // СИСТЕМНІ НАЛАШТУВАННЯ
  uint32_t sendDataToServerEvery = 1000;                                      // Надсилати дані на сервер кожних мс
  uint16_t checkSensorEvery = 1000;                                           // Перевіряти сенсори кожних мс
  bool turnOff = false;                                                       // Екстренне вимикання пристрою
  uint16_t restartCounter = 0;                                                // Лічильник перезавантажень контролера
  uint16_t workedTimeInSeconds = 0;                                           // Лічильник роботи контролера в секундах
  uint32_t workedTimeInHours = 0;                                             // Лічильник роботи контролера в годинах
  const char uId[20] = UID;                                                   // Унікальний номер пристрою Cyber Done
  /*
    uint32_t ph = 0;                                        // Рівень кислотності рідини Ph
    uint32_t waterTemperature = 0;                          // Температура рідини
    uint32_t ec = 0;                                        // Електропровідність рідини
    uint32_t tds = 0;                                       // Кількість одиниць солі на мільйон одиниць рідини (parts per million) ppm
    uint32_t pressure = 0;                                  // Рівень атмосферного тиску
    uint32_t airHumidity = 0;                               // Рівень відносної вологості повітря
    uint32_t airTemperature = 0;                            // Рівень температури повітря
    uint32_t altitude = 0;                                  // Висота над рівнем моря в метрах
  */
};


template <typename T> void copy(T *a, T *b, uint16_t n) {
  uint16_t i;
  for (i = 0; i < n; i++)
    a[i] = b[i];
}

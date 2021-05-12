#include "global.h"

String printDate() {
  String date = "";
  date += String(cpd.dateYear) + '/' + String(cpd.dateMonth) + '/' + String(cpd.dateDay) + ' ';
  date += String(cpd.dateHour) + ':' + String(cpd.dateMinute) + ':' + String(cpd.dateSecond);
  return date;
}


void subscribeEndpoints() {
  client.subscribe("cd/"UID"/ch/0/type");
  client.subscribe("cd/"UID"/ch/1/type");
  client.subscribe("cd/"UID"/ch/2/type");
  client.subscribe("cd/"UID"/ch/3/type");

  client.subscribe("cd/"UID"/ch/0/logic");
  client.subscribe("cd/"UID"/ch/1/logic");
  client.subscribe("cd/"UID"/ch/2/logic");
  client.subscribe("cd/"UID"/ch/3/logic");

  client.subscribe("cd/"UID"/sen/0/data");
  client.subscribe("cd/"UID"/sen/1/data");
  client.subscribe("cd/"UID"/sen/2/data");
  client.subscribe("cd/"UID"/sen/3/data");

  client.subscribe("cd/"UID"/sen/0/maintain_value");
  client.subscribe("cd/"UID"/sen/1/maintain_value");
  client.subscribe("cd/"UID"/sen/2/maintain_value");
  client.subscribe("cd/"UID"/sen/3/maintain_value");

  client.subscribe("cd/"UID"/ch/0/open_value");
  client.subscribe("cd/"UID"/ch/1/open_value");
  client.subscribe("cd/"UID"/ch/2/open_value");
  client.subscribe("cd/"UID"/ch/3/open_value");

  client.subscribe("cd/"UID"/ch/0/control");
  client.subscribe("cd/"UID"/ch/1/control");
  client.subscribe("cd/"UID"/ch/2/control");
  client.subscribe("cd/"UID"/ch/3/control");

  client.subscribe("cd/"UID"/ch/0/pid/direction");
  client.subscribe("cd/"UID"/ch/1/pid/direction");
  client.subscribe("cd/"UID"/ch/2/pid/direction");
  client.subscribe("cd/"UID"/ch/3/pid/direction");

  client.subscribe("cd/"UID"/ch/0/pid/kp");
  client.subscribe("cd/"UID"/ch/1/pid/kp");
  client.subscribe("cd/"UID"/ch/2/pid/kp");
  client.subscribe("cd/"UID"/ch/3/pid/kp");

  client.subscribe("cd/"UID"/ch/0/pid/ki");
  client.subscribe("cd/"UID"/ch/1/pid/ki");
  client.subscribe("cd/"UID"/ch/2/pid/ki");
  client.subscribe("cd/"UID"/ch/3/pid/ki");

  client.subscribe("cd/"UID"/ch/0/pid/kd");
  client.subscribe("cd/"UID"/ch/1/pid/kd");
  client.subscribe("cd/"UID"/ch/2/pid/kd");
  client.subscribe("cd/"UID"/ch/3/pid/kd");

  client.subscribe("cd/"UID"/ch/0/pid/dt");
  client.subscribe("cd/"UID"/ch/1/pid/dt");
  client.subscribe("cd/"UID"/ch/2/pid/dt");
  client.subscribe("cd/"UID"/ch/3/pid/dt");


  client.subscribe("cd/"UID"/ch/0/relay/direction");
  client.subscribe("cd/"UID"/ch/1/relay/direction");
  client.subscribe("cd/"UID"/ch/2/relay/direction");
  client.subscribe("cd/"UID"/ch/3/relay/direction");

  client.subscribe("cd/"UID"/ch/0/relay/hysteresis");
  client.subscribe("cd/"UID"/ch/1/relay/hysteresis");
  client.subscribe("cd/"UID"/ch/2/relay/hysteresis");
  client.subscribe("cd/"UID"/ch/3/relay/hysteresis");

  client.subscribe("cd/"UID"/ch/0/relay/k");
  client.subscribe("cd/"UID"/ch/1/relay/k");
  client.subscribe("cd/"UID"/ch/2/relay/k");
  client.subscribe("cd/"UID"/ch/3/relay/k");

  client.subscribe("cd/"UID"/ch/0/relay/dt");
  client.subscribe("cd/"UID"/ch/1/relay/dt");
  client.subscribe("cd/"UID"/ch/2/relay/dt");
  client.subscribe("cd/"UID"/ch/3/relay/dt");

  client.subscribe("cd/"UID"/sound");
  client.subscribe("cd/"UID"/wcheck");
  client.subscribe("cd/"UID"/sleep");
  client.subscribe("cd/"UID"/sleep_after");
  client.subscribe("cd/"UID"/screen_light");

  client.subscribe("cd/"UID"/date/second");
  client.subscribe("cd/"UID"/date/minute");
  client.subscribe("cd/"UID"/date/hour");
  client.subscribe("cd/"UID"/date/day");
  client.subscribe("cd/"UID"/date/month");
  client.subscribe("cd/"UID"/date/year");

  client.subscribe("cd/"UID"/wifi/ssid");
  client.subscribe("cd/"UID"/wifi/pass");

  client.subscribe("cd/"UID"/send_data_every");
  client.subscribe("cd/"UID"/sensor_recheck_every");
  client.subscribe("cd/"UID"/turn_off");
  client.subscribe("cd/"UID"/counter/restart");
  client.subscribe("cd/"UID"/counter/worked_in_seconds");
  client.subscribe("cd/"UID"/counter/worked_in_hours");

  client.subscribe("cd/"UID"/webcontrol");
}


String createJSON() {
  String msg = "{";
  uint8_t i;

  msg += "\"channelType\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.channelType[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"channelLogic\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.channelLogic[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"analogSensorData\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.analogSensorData[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"maintainValue\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.maintainValue[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"channelValue\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.channelValue[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"channelControlMode\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.channelControlMode[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidDirection\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.pidDirection[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidKp\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.pidKp[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidKi\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.pidKi[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidKd\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.pidKd[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidDt\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.pidDt[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }


  msg += "\"relayDirection\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.relayDirection[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"relayHysteresis\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.relayHysteresis[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"relayK\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.relayK[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"relayDt\":[";
  for (i = 0; i < 4; i++) {
    msg += "\"" + String(cpd.relayDt[i]) + "\"";
    if (i != 3)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"sound\":\"" + String(cpd.sound) + "\",";
  msg += "\"waterCheck\":\"" + String(cpd.waterCheck) + "\",";
  msg += "\"sleep\":\"" + String(cpd.sleep) + "\",";
  msg += "\"sleepAfter\":\"" + String(cpd.sleepAfter) + "\",";
  msg += "\"screenLight\":\"" + String(cpd.screenLight) + "\",";

  msg += "\"dateSecond\":\"" + String(cpd.dateSecond) + "\",";
  msg += "\"dateMinute\":\"" + String(cpd.dateMinute) + "\",";
  msg += "\"dateHour\":\"" + String(cpd.dateHour) + "\",";
  msg += "\"dateDay\":\"" + String(cpd.dateDay) + "\",";
  msg += "\"dateMonth\":\"" + String(cpd.dateMonth) + "\",";
  msg += "\"dateYear\":\"" + String(cpd.dateYear) + "\",";

  msg += "\"wifiSSID\":\"" + String(cpd.wifiSSID) + "\",";
  msg += "\"wifiPASS\":\"" + String(cpd.wifiPASS) + "\",";


  msg += "\"sendDataToServerEvery\":\"" + String(cpd.sendDataToServerEvery) + "\",";
  msg += "\"checkSensorEvery\":\"" + String(cpd.checkSensorEvery) + "\",";
  msg += "\"turnOff\":\"" + String(cpd.turnOff) + "\",";
  msg += "\"restartCounter\":\"" + String(cpd.restartCounter) + "\",";
  msg += "\"workedTimeInSeconds\":\"" + String(cpd.workedTimeInSeconds) + "\",";
  msg += "\"workedTimeInHours\":\"" + String(cpd.workedTimeInHours) + "\",";
  msg += "\"uId\":\"" + String(cpd.uId) + "\"";
  msg += "}";

  return msg;
}


void callback(char* topic, byte* payload, unsigned int length) {
  const char *data = reinterpret_cast<const char*>(payload);

  unsigned long ulValue = 0;
  sscanf( data, "#%lud#", &ulValue);

  long lValue = 0;
  sscanf( data, "#%ld#", &lValue);

  int iValue = 0;
  sscanf( data, "#%d#", &iValue);

  unsigned int uiValue = 0;
  sscanf( data, "#%ud#", &uiValue);

  float fValue = 0.0f;
  sscanf( data, "#%f#", &fValue);

  double dValue = 0.0;
  sscanf( data, "#%Lf#", &dValue);


  // Отримати тип каналу

  if (strcmp(topic, "cd/"UID"/ch/0/type") == 0) {
    cpd.channelType[0] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/type") == 0) {
    cpd.channelType[1] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/type") == 0) {
    cpd.channelType[2] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/type") == 0) {
    cpd.channelType[3] = (bool) uiValue; return;
  }


  // Отримати логічний рівень керування каналом

  if (strcmp(topic, "cd/"UID"/ch/0/logic") == 0) {
    cpd.channelLogic[0] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/type") == 0) {
    cpd.channelLogic[1] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/type") == 0) {
    cpd.channelLogic[2] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/type") == 0) {
    cpd.channelLogic[3] = (bool) uiValue; return;
  }


  // Отримати реальне значення сенсора через інтернет

  if (strcmp(topic, "cd/"UID"/sen/0/data") == 0) {
    cpd.analogSensorData[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/1/data") == 0) {
    cpd.analogSensorData[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/2/data") == 0) {
    cpd.analogSensorData[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/3/data") == 0) {
    cpd.analogSensorData[3] = (double) dValue; return;
  }


  // Отримати значення сенсора, за котрим регулюватиметься канал

  if (strcmp(topic, "cd/"UID"/sen/0/maintain_value") == 0) {
    cpd.maintainValue[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/1/maintain_value") == 0) {
    cpd.maintainValue[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/2/maintain_value") == 0) {
    cpd.maintainValue[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/3/maintain_value") == 0) {
    cpd.maintainValue[3] = (double) dValue; return;
  }


  // Отримати значення відкритості каналу для димера 0-65535 або стан для реле 0-1

  if (strcmp(topic, "cd/"UID"/ch/0/open_value") == 0) {
    cpd.channelValue[0] = (uint16_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/open_value") == 0) {
    cpd.channelValue[1] = (uint16_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/open_value") == 0) {
    cpd.channelValue[2] = (uint16_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/open_value") == 0) {
    cpd.channelValue[3] = (uint16_t) uiValue; return;
  }


  // Отримати логічний рівень для каналу 0 або 1

  if (strcmp(topic, "cd/"UID"/ch/0/control") == 0) {
    cpd.channelControlMode[0] = (uint8_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/control") == 0) {
    cpd.channelControlMode[1] = (uint8_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/control") == 0) {
    cpd.channelControlMode[2] = (uint8_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/control") == 0) {
    cpd.channelControlMode[3] = (uint8_t) uiValue; return;
  }


  // Отримати режим керування каналом 0-ручний, 1-регулятор ...

  if (strcmp(topic, "cd/"UID"/ch/0/control") == 0) {
    cpd.channelControlMode[0] = (uint8_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/control") == 0) {
    cpd.channelControlMode[1] = (uint8_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/control") == 0) {
    cpd.channelControlMode[2] = (uint8_t) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/control") == 0) {
    cpd.channelControlMode[3] = (uint8_t) uiValue; return;
  }


  // Отримати напрям керування ПІД регулятором

  if (strcmp(topic, "cd/"UID"/ch/0/pid/direction") == 0) {
    cpd.pidDirection[0] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/direction") == 0) {
    cpd.pidDirection[1] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/direction") == 0) {
    cpd.pidDirection[2] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/direction") == 0) {
    cpd.pidDirection[3] = (bool) uiValue; return;
  }


  // Отримати пропорційну складову ПІД регулятора

  if (strcmp(topic, "cd/"UID"/ch/0/pid/kp") == 0) {
    cpd.pidKp[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/kp") == 0) {
    cpd.pidKp[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/kp") == 0) {
    cpd.pidKp[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/kp") == 0) {
    cpd.pidKp[3] = (double) dValue; return;
  }


  // Отримати інтегральну складову ПІД регулятора

  if (strcmp(topic, "cd/"UID"/ch/0/pid/ki") == 0) {
    cpd.pidKi[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/ki") == 0) {
    cpd.pidKi[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/ki") == 0) {
    cpd.pidKi[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/ki") == 0) {
    cpd.pidKi[3] = (double) dValue; return;
  }


  // Отримати диференціальну складову ПІД регулятора

  if (strcmp(topic, "cd/"UID"/ch/0/pid/kd") == 0) {
    cpd.pidKd[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/kd") == 0) {
    cpd.pidKd[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/kd") == 0) {
    cpd.pidKd[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/kd") == 0) {
    cpd.pidKd[3] = (double) dValue; return;
  }


  // Отримати час дискретизації ПІД регулятора

  if (strcmp(topic, "cd/"UID"/ch/0/pid/dt") == 0) {
    cpd.pidDt[0] = (uint32_t) ulValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/dt") == 0) {
    cpd.pidDt[1] = (uint32_t) ulValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/dt") == 0) {
    cpd.pidDt[2] = (uint32_t) ulValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/dt") == 0) {
    cpd.pidDt[3] = (uint32_t) ulValue; return;
  }


  // Отримати напрям керування релейного регулятора

  if (strcmp(topic, "cd/"UID"/ch/0/relay/direction") == 0) {
    cpd.relayDirection[0] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/relay/direction") == 0) {
    cpd.relayDirection[1] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/relay/direction") == 0) {
    cpd.relayDirection[2] = (bool) uiValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/relay/direction") == 0) {
    cpd.relayDirection[3] = (bool) uiValue; return;
  }


  // Отримати значення гістерезису релейного регулятора

  if (strcmp(topic, "cd/"UID"/ch/0/relay/hysteresis") == 0) {
    cpd.relayHysteresis[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/relay/hysteresis") == 0) {
    cpd.relayHysteresis[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/relay/hysteresis") == 0) {
    cpd.relayHysteresis[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/relay/hysteresis") == 0) {
    cpd.relayHysteresis[3] = (double) dValue; return;
  }


  // Отримати коефіцієнт інерційності системи

  if (strcmp(topic, "cd/"UID"/ch/0/relay/k") == 0) {
    cpd.relayK[0] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/relay/k") == 0) {
    cpd.relayK[1] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/relay/k") == 0) {
    cpd.relayK[2] = (double) dValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/relay/k") == 0) {
    cpd.relayK[3] = (double) dValue; return;
  }


  // Отримати час ітерації

  if (strcmp(topic, "cd/"UID"/ch/0/relay/dt") == 0) {
    cpd.relayDt[0] = (uint32_t) ulValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/relay/dt") == 0) {
    cpd.relayDt[1] = (uint32_t) ulValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/relay/dt") == 0) {
    cpd.relayDt[2] = (uint32_t) ulValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/relay/dt") == 0) {
    cpd.relayDt[3] = (uint32_t) ulValue; return;
  }


  // Режим звуку
  if (strcmp(topic, "cd/"UID"/sound") == 0) {
    cpd.sound = (bool) uiValue; return;
  }
  // Режим перевірки води
  if (strcmp(topic, "cd/"UID"/wcheck") == 0) {
    cpd.waterCheck = (bool) uiValue; return;
  }
  // Режим сну
  if (strcmp(topic, "cd/"UID"/sleep") == 0) {
    cpd.sleep = (bool) uiValue; return;
  }
  // Перейти в режим сну після мс
  if (strcmp(topic, "cd/"UID"/sleep_after") == 0) {
    cpd.sleepAfter = (uint16_t) ulValue; return;
  }
  // Підсвітка екрану
  if (strcmp(topic, "cd/"UID"/screen_light") == 0) {
    cpd.screenLight = (bool) uiValue; return;
  }


  // Час секунда
  if (strcmp(topic, "cd/"UID"/date/second") == 0) {
    cpd.dateSecond = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // Час хвилина
  if (strcmp(topic, "cd/"UID"/date/minute") == 0) {
    cpd.dateMinute = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // Час година
  if (strcmp(topic, "cd/"UID"/date/hour") == 0) {
    cpd.dateHour = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // Час день
  if (strcmp(topic, "cd/"UID"/date/day") == 0) {
    cpd.dateDay = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // Час місяць
  if (strcmp(topic, "cd/"UID"/date/month") == 0) {
    cpd.dateMonth = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // Час рік
  if (strcmp(topic, "cd/"UID"/date/year") == 0) {
    cpd.dateYear = (uint16_t) ulValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }


  // Назва точки доступу
  if (strcmp(topic, "cd/"UID"/wifi/ssid") == 0) {
    sscanf(data, " %s ", cpd.wifiSSID);
    return;
  }
  // Пароль точки доступу
  if (strcmp(topic, "cd/"UID"/wifi/pass") == 0) {
    sscanf(data, " %s ", cpd.wifiPASS);
    return;
  }


  // Надсилати дані на сервер кожних мс
  if (strcmp(topic, "cd/"UID"/send_data_every") == 0) {
    cpd.sendDataToServerEvery = (uint32_t) ulValue; return;
  }
  // Перевіряти сенсори кожних мс
  if (strcmp(topic, "cd/"UID"/sensor_recheck_every") == 0) {
    cpd.checkSensorEvery = (uint16_t) uiValue; return;
  }
  // Екстренне вимикання пристрою
  if (strcmp(topic, "cd/"UID"/turn_off") == 0) {
    cpd.turnOff = (bool) uiValue; return;
  }
  // Лічильник перезавантажень контролера
  if (strcmp(topic, "cd/"UID"/counter/restart") == 0) {
    cpd.restartCounter = (uint16_t) uiValue; return;
  }
  // Лічильник роботи контролера в секундах
  if (strcmp(topic, "cd/"UID"/counter/worked_in_seconds") == 0) {
    cpd.workedTimeInSeconds = (uint16_t) uiValue; return;
  }
  // Лічильник роботи контролера в годинах
  if (strcmp(topic, "cd/"UID"/counter/worked_in_hours") == 0) {
    cpd.workedTimeInHours = (uint32_t) ulValue; return;
  }

  // Веб керування
  if (strcmp(topic, "cd/"UID"/webcontrol") == 0) {
    uint8_t action = (uint8_t) uiValue;

    if (action == 0)
      LCDML.BT_enter();
    else if (action == 1)
      LCDML.BT_up();
    else if (action == 2)
      LCDML.BT_down();
    else if (action == 3)
      LCDML.BT_left();
    else if (action == 4)
      LCDML.BT_right();
    else if (action == 5)
      LCDML.BT_quit();
    else if (action == 6)
      LCDML.MENU_goRoot();
  }

}


void setup_wifi() {
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  randomSeed(micros());
}


void reconnect() {
  while (!client.connected()) {
    if (client.connect(UID))
      subscribeEndpoints();
    else
      delay(5000);
  }
}


void setCurrentDateTime() {
  DateTime now = rtc.now();

  cpd.dateSecond = now.second();
  cpd.dateMinute = now.minute();
  cpd.dateHour = now.hour();
  cpd.dateDay = now.day();
  cpd.dateMonth = now.month();
  cpd.dateYear = now.year();
}

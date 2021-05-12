#include "global.h"

String printDate() {
  String date = "";
  date += String(cpd.dateYear) + '/' + String(cpd.dateMonth) + '/' + String(cpd.dateDay) + ' ';
  date += String(cpd.dateHour) + ':' + String(cpd.dateMinute) + ':' + String(cpd.dateSecond);
  return date;
}

void getSizeTable() {
  Serial.println("------------------- ESP ----------------------------");
  Serial.print("cpd.channelType = "); Serial.println(sizeof(cpd.channelType));
  Serial.print("cpd.channelLogic = "); Serial.println(sizeof(cpd.channelLogic));
  Serial.print("cpd.channelValue = "); Serial.println(sizeof(cpd.channelValue));
  Serial.print("cpd.channelControlMode = "); Serial.println(sizeof(cpd.channelControlMode));
  Serial.print("cpd.pidKp = "); Serial.println(sizeof(cpd.pidKp));
  Serial.print("cpd.pidKi = "); Serial.println(sizeof(cpd.pidKi));
  Serial.print("cpd.pidKd = "); Serial.println(sizeof(cpd.pidKd));
  Serial.print("cpd.pidDt = "); Serial.println(sizeof(cpd.pidDt));
  Serial.print("cpd.pidDirection = "); Serial.println(sizeof(cpd.pidDirection));
  Serial.print("cpd.analogSensorType = "); Serial.println(sizeof(cpd.analogSensorType));
  Serial.print("cpd.analogSensorData = "); Serial.println(sizeof(cpd.analogSensorData));
  Serial.print("cpd.sensorControlValue = "); Serial.println(sizeof(cpd.sensorControlValue));
  Serial.print("cpd.ph = "); Serial.println(sizeof(cpd.ph));
  Serial.print("cpd.waterTemperature = "); Serial.println(sizeof(cpd.waterTemperature));
  Serial.print("cpd.ec = "); Serial.println(sizeof(cpd.ec));
  Serial.print("cpd.tds = "); Serial.println(sizeof(cpd.tds));
  Serial.print("cpd.pressure = "); Serial.println(sizeof(cpd.pressure));
  Serial.print("cpd.airHumidity = "); Serial.println(sizeof(cpd.airHumidity));
  Serial.print("cpd.airTemperature = "); Serial.println(sizeof(cpd.airTemperature));
  Serial.print("cpd.altitude = "); Serial.println(sizeof(cpd.altitude));
  Serial.print("cpd.sound = "); Serial.println(sizeof(cpd.sound));
  Serial.print("cpd.waterCheck = "); Serial.println(sizeof(cpd.waterCheck));
  Serial.print("cpd.sleep = "); Serial.println(sizeof(cpd.sleep));
  Serial.print("cpd.sleepAfter = "); Serial.println(sizeof(cpd.sleepAfter));
  Serial.print("cpd.sendDataToServerEvery = "); Serial.println(sizeof(cpd.sendDataToServerEvery));
  Serial.print("cpd.checkSensorEvery = "); Serial.println(sizeof(cpd.checkSensorEvery));
  Serial.print("cpd.screenLight = "); Serial.println(sizeof(cpd.screenLight));
  Serial.print("cpd.dateSecond = "); Serial.println(sizeof(cpd.dateSecond));
  Serial.print("cpd.dateMinute = "); Serial.println(sizeof(cpd.dateMinute));
  Serial.print("cpd.dateHour = "); Serial.println(sizeof(cpd.dateHour));
  Serial.print("cpd.dateDay = "); Serial.println(sizeof(cpd.dateDay));
  Serial.print("cpd.dateMonth = "); Serial.println(sizeof(cpd.dateMonth));
  Serial.print("cpd.dateYear = "); Serial.println(sizeof(cpd.dateYear));
  Serial.print("cpd.wifiSSID = "); Serial.println(sizeof(cpd.wifiSSID));
  Serial.print("cpd.wifiPASS = "); Serial.println(sizeof(cpd.wifiPASS));
  Serial.print("cpd.uId = "); Serial.println(sizeof(cpd.uId));
}

void subscribeEndpoints() {
  client.subscribe("cd/"UID"/ch/0/val");
  client.subscribe("cd/"UID"/ch/1/val");
  client.subscribe("cd/"UID"/ch/2/val");
  client.subscribe("cd/"UID"/ch/3/val");
  client.subscribe("cd/"UID"/ch/4/val");
  client.subscribe("cd/"UID"/ch/5/val");

  client.subscribe("cd/"UID"/ch/0/type");
  client.subscribe("cd/"UID"/ch/1/type");
  client.subscribe("cd/"UID"/ch/2/type");
  client.subscribe("cd/"UID"/ch/3/type");
  client.subscribe("cd/"UID"/ch/4/type");
  client.subscribe("cd/"UID"/ch/5/type");

  client.subscribe("cd/"UID"/ch/0/logic");
  client.subscribe("cd/"UID"/ch/1/logic");
  client.subscribe("cd/"UID"/ch/2/logic");
  client.subscribe("cd/"UID"/ch/3/logic");
  client.subscribe("cd/"UID"/ch/4/logic");
  client.subscribe("cd/"UID"/ch/5/logic");

  client.subscribe("cd/"UID"/ch/0/ctrlmode");
  client.subscribe("cd/"UID"/ch/1/ctrlmode");
  client.subscribe("cd/"UID"/ch/2/ctrlmode");
  client.subscribe("cd/"UID"/ch/3/ctrlmode");
  client.subscribe("cd/"UID"/ch/4/ctrlmode");
  client.subscribe("cd/"UID"/ch/5/ctrlmode");

  client.subscribe("cd/"UID"/ch/0/pid/kp");
  client.subscribe("cd/"UID"/ch/1/pid/kp");
  client.subscribe("cd/"UID"/ch/2/pid/kp");
  client.subscribe("cd/"UID"/ch/3/pid/kp");
  client.subscribe("cd/"UID"/ch/4/pid/kp");
  client.subscribe("cd/"UID"/ch/5/pid/kp");

  client.subscribe("cd/"UID"/ch/0/pid/ki");
  client.subscribe("cd/"UID"/ch/1/pid/ki");
  client.subscribe("cd/"UID"/ch/2/pid/ki");
  client.subscribe("cd/"UID"/ch/3/pid/ki");
  client.subscribe("cd/"UID"/ch/4/pid/ki");
  client.subscribe("cd/"UID"/ch/5/pid/ki");

  client.subscribe("cd/"UID"/ch/0/pid/kd");
  client.subscribe("cd/"UID"/ch/1/pid/kd");
  client.subscribe("cd/"UID"/ch/2/pid/kd");
  client.subscribe("cd/"UID"/ch/3/pid/kd");
  client.subscribe("cd/"UID"/ch/4/pid/kd");
  client.subscribe("cd/"UID"/ch/5/pid/kd");

  client.subscribe("cd/"UID"/ch/0/pid/dt");
  client.subscribe("cd/"UID"/ch/1/pid/dt");
  client.subscribe("cd/"UID"/ch/2/pid/dt");
  client.subscribe("cd/"UID"/ch/3/pid/dt");
  client.subscribe("cd/"UID"/ch/4/pid/dt");
  client.subscribe("cd/"UID"/ch/5/pid/dt");

  client.subscribe("cd/"UID"/ch/0/pid/dir");
  client.subscribe("cd/"UID"/ch/1/pid/dir");
  client.subscribe("cd/"UID"/ch/2/pid/dir");
  client.subscribe("cd/"UID"/ch/3/pid/dir");
  client.subscribe("cd/"UID"/ch/4/pid/dir");
  client.subscribe("cd/"UID"/ch/5/pid/dir");

  client.subscribe("cd/"UID"/sen/0/type");
  client.subscribe("cd/"UID"/sen/1/type");
  client.subscribe("cd/"UID"/sen/2/type");
  client.subscribe("cd/"UID"/sen/3/type");
  client.subscribe("cd/"UID"/sen/4/type");
  client.subscribe("cd/"UID"/sen/5/type");

  client.subscribe("cd/"UID"/sen/0/data");
  client.subscribe("cd/"UID"/sen/1/data");
  client.subscribe("cd/"UID"/sen/2/data");
  client.subscribe("cd/"UID"/sen/3/data");
  client.subscribe("cd/"UID"/sen/4/data");
  client.subscribe("cd/"UID"/sen/5/data");

  client.subscribe("cd/"UID"/sen/0/control");
  client.subscribe("cd/"UID"/sen/1/control");
  client.subscribe("cd/"UID"/sen/2/control");
  client.subscribe("cd/"UID"/sen/3/control");
  client.subscribe("cd/"UID"/sen/4/control");
  client.subscribe("cd/"UID"/sen/5/control");

  client.subscribe("cd/"UID"/sen/6/ph");
  client.subscribe("cd/"UID"/sen/6/wtemp");
  client.subscribe("cd/"UID"/sen/6/ec");
  client.subscribe("cd/"UID"/sen/6/tds");

  client.subscribe("cd/"UID"/sen/7/pressure");
  client.subscribe("cd/"UID"/sen/7/ahum");
  client.subscribe("cd/"UID"/sen/7/atemp");
  client.subscribe("cd/"UID"/sen/7/altitude");

  client.subscribe("cd/"UID"/sound");
  client.subscribe("cd/"UID"/wcheck");
  client.subscribe("cd/"UID"/sleep");
  client.subscribe("cd/"UID"/sleep_after");
  client.subscribe("cd/"UID"/send_data_every");
  client.subscribe("cd/"UID"/sensor_recheck_every");
  client.subscribe("cd/"UID"/screen_light");

  client.subscribe("cd/"UID"/date/second");
  client.subscribe("cd/"UID"/date/minute");
  client.subscribe("cd/"UID"/date/hour");
  client.subscribe("cd/"UID"/date/day");
  client.subscribe("cd/"UID"/date/month");
  client.subscribe("cd/"UID"/date/year");

  client.subscribe("cd/"UID"/wifi/ssid");
  client.subscribe("cd/"UID"/wifi/pass");
}


String createJSON() {
  String msg = "{";
  uint8_t i;

  msg += "\"channelType\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.channelType[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"channelLogic\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.channelLogic[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"channelValue\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.channelValue[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"channelControlMode\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.channelControlMode[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidKp\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.pidKp[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidKi\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.pidKi[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidKd\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.pidKd[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidDt\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.pidDt[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"pidDirection\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.pidDirection[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"analogSensorType\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.analogSensorType[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"analogSensorData\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.analogSensorData[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"sensorControlValue\":[";
  for (i = 0; i < 6; i++) {
    msg += "\"" + String(cpd.sensorControlValue[i]) + "\"";
    if (i != 5)
      msg += ",";
    else
      msg += "],";
  }

  msg += "\"ph\":\"" + String(cpd.ph) + "\",";
  msg += "\"waterTemperature\":\"" + String(cpd.waterTemperature) + "\",";
  msg += "\"ec\":\"" + String(cpd.ec) + "\",";
  msg += "\"tds\":\"" + String(cpd.tds) + "\",";
  msg += "\"pressure\":\"" + String(cpd.pressure) + "\",";
  msg += "\"airHumidity\":\"" + String(cpd.airHumidity) + "\",";
  msg += "\"airTemperature\":\"" + String(cpd.airTemperature) + "\",";
  msg += "\"altitude\":\"" + String(cpd.altitude) + "\",";

  msg += "\"sound\":\"" + String(cpd.sound) + "\",";
  msg += "\"waterCheck\":\"" + String(cpd.waterCheck) + "\",";
  msg += "\"sleep\":\"" + String(cpd.sleep) + "\",";
  msg += "\"sleepAfter\":\"" + String(cpd.sleepAfter) + "\",";
  msg += "\"sendDataToServerEvery\":\"" + String(cpd.sendDataToServerEvery) + "\",";
  msg += "\"checkSensorEvery\":\"" + String(cpd.checkSensorEvery) + "\",";
  msg += "\"screenLight\":\"" + String(cpd.screenLight) + "\",";

  msg += "\"dateSecond\":\"" + String(cpd.dateSecond) + "\",";
  msg += "\"dateMinute\":\"" + String(cpd.dateMinute) + "\",";
  msg += "\"dateHour\":\"" + String(cpd.dateHour) + "\",";
  msg += "\"dateDay\":\"" + String(cpd.dateDay) + "\",";
  msg += "\"dateMonth\":\"" + String(cpd.dateMonth) + "\",";
  msg += "\"dateYear\":\"" + String(cpd.dateYear) + "\",";


  msg += "\"wifiSSID\":\"" + String(cpd.wifiSSID) + "\",";
  msg += "\"wifiPASS\":\"" + String(cpd.wifiPASS) + "\",";
  msg += "\"uId\":\"" + String(cpd.uId) + "\"";
  msg += "}";

  return msg;
}


void callback(char* topic, byte* payload, unsigned int length) {

  const char *data = reinterpret_cast<const char*>(payload);
  int integerValue = 0;
  sscanf( data, "#%d#", &integerValue);


  if (strcmp(topic, "cd/"UID"/ch/0/val") == 0) {
    cpd.channelValue[0] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/val") == 0) {
    cpd.channelValue[1] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/val") == 0) {
    cpd.channelValue[2] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/val") == 0) {
    cpd.channelValue[3] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/val") == 0) {
    cpd.channelValue[4] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/val") == 0) {
    cpd.channelValue[5] = (uint8_t) integerValue; return;
  }
  /**
    Channel Type Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/type") == 0) {
    cpd.channelType[0] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/type") == 0) {
    cpd.channelType[1] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/type") == 0) {
    cpd.channelType[2] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/type") == 0) {
    cpd.channelType[3] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/type") == 0) {
    cpd.channelType[4] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/type") == 0) {
    cpd.channelType[5] = (bool) integerValue; return;
  }
  /**
       Channel Logic Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/logic") == 0) {
    cpd.channelLogic[0] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/logic") == 0) {
    cpd.channelLogic[1] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/logic") == 0) {
    cpd.channelLogic[2] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/logic") == 0) {
    cpd.channelLogic[3] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/logic") == 0) {
    cpd.channelLogic[4] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/logic") == 0) {
    cpd.channelLogic[5] = (bool) integerValue; return;
  }
  /**
       Channel Control Mode Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/ctrlmode") == 0) {
    cpd.channelControlMode[0] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/ctrlmode") == 0) {
    cpd.channelControlMode[1] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/ctrlmode") == 0) {
    cpd.channelControlMode[2] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/ctrlmode") == 0) {
    cpd.channelControlMode[3] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/ctrlmode") == 0) {
    cpd.channelControlMode[4] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/ctrlmode") == 0) {
    cpd.channelControlMode[5] = (uint8_t) integerValue; return;
  }
  // /**
  //      Channel PID Kp Set
  // */
  // float floatValue;
  // sscanf( data, "#%f#", &floatValue);
  /**
       Channel PID Kp Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/pid/kp") == 0) {
    cpd.pidKp[0] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/kp") == 0) {
    cpd.pidKp[1] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/kp") == 0) {
    cpd.pidKp[2] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/kp") == 0) {
    cpd.pidKp[3] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/pid/kp") == 0) {
    cpd.pidKp[4] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/pid/kp") == 0) {
    cpd.pidKp[5] = (uint16_t) integerValue; return;
  }
  /**
       Channel PID Ki Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/pid/ki") == 0) {
    cpd.pidKi[0] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/ki") == 0) {
    cpd.pidKi[1] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/ki") == 0) {
    cpd.pidKi[2] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/ki") == 0) {
    cpd.pidKi[3] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/pid/ki") == 0) {
    cpd.pidKi[4] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/pid/ki") == 0) {
    cpd.pidKi[5] = (uint16_t) integerValue; return;
  }
  /**
     Channel PID Kd Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/pid/kd") == 0) {
    cpd.pidKd[0] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/kd") == 0) {
    cpd.pidKd[1] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/kd") == 0) {
    cpd.pidKd[2] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/kd") == 0) {
    cpd.pidKd[3] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/pid/kd") == 0) {
    cpd.pidKd[4] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/pid/kd") == 0) {
    cpd.pidKd[5] = (uint16_t) integerValue; return;
  }
  /**
       Channel PID dt Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/pid/dt") == 0) {
    cpd.pidDt[0] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/dt") == 0) {
    cpd.pidDt[1] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/dt") == 0) {
    cpd.pidDt[2] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/dt") == 0) {
    cpd.pidDt[3] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/pid/dt") == 0) {
    cpd.pidDt[4] = (uint16_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/pid/dt") == 0) {
    cpd.pidDt[5] = (uint16_t) integerValue; return;
  }
  /**
       Channel PID direction Set
  */

  if (strcmp(topic, "cd/"UID"/ch/0/pid/dir") == 0) {
    cpd.pidDirection[0] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/1/pid/dir") == 0) {
    cpd.pidDirection[1] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/2/pid/dir") == 0) {
    cpd.pidDirection[2] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/3/pid/dir") == 0) {
    cpd.pidDirection[3] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/4/pid/dir") == 0) {
    cpd.pidDirection[4] = (bool) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/ch/5/pid/dir") == 0) {
    cpd.pidDirection[5] = (bool) integerValue; return;
  }
  /**
        Тип аналогових сенсорів
  */

  if (strcmp(topic, "cd/"UID"/sen/0/type") == 0) {
    cpd.analogSensorType[0] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/1/type") == 0) {
    cpd.analogSensorType[1] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/2/type") == 0) {
    cpd.analogSensorType[2] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/3/type") == 0) {
    cpd.analogSensorType[3] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/4/type") == 0) {
    cpd.analogSensorType[4] = (uint8_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/5/type") == 0) {
    cpd.analogSensorType[5] = (uint8_t) integerValue; return;
  }
  /**
          Дані аналогових сенсорів
  */

  if (strcmp(topic, "cd/"UID"/sen/0/data") == 0) {
    cpd.analogSensorData[0] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/1/data") == 0) {
    cpd.analogSensorData[1] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/2/data") == 0) {
    cpd.analogSensorData[2] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/3/data") == 0) {
    cpd.analogSensorData[3] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/4/data") == 0) {
    cpd.analogSensorData[4] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/5/data") == 0) {
    cpd.analogSensorData[5] = (uint32_t) integerValue; return;
  }
  /**
          Підтримуване аналоговими сенсорами заначення
  */

  if (strcmp(topic, "cd/"UID"/sen/0/control") == 0) {
    cpd.sensorControlValue[0] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/1/control") == 0) {
    cpd.sensorControlValue[1] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/2/control") == 0) {
    cpd.sensorControlValue[2] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/3/control") == 0) {
    cpd.sensorControlValue[3] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/4/control") == 0) {
    cpd.sensorControlValue[4] = (uint32_t) integerValue; return;
  }
  if (strcmp(topic, "cd/"UID"/sen/5/control") == 0) {
    cpd.sensorControlValue[5] = (uint32_t) integerValue; return;
  }


  if (strcmp(topic, "cd/"UID"/sen/6/ph") == 0) {
    cpd.ph = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sen/6/wtemp") == 0) {
    cpd.waterTemperature = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sen/6/ec") == 0) {
    cpd.ec = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sen/6/tds") == 0) {
    cpd.tds = (uint16_t) integerValue; return;
  }


  if (strcmp(topic, "cd/"UID"/sen/7/pressure") == 0) {
    cpd.pressure = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sen/7/ahum") == 0) {
    cpd.airHumidity = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sen/7/atemp") == 0) {
    cpd.airTemperature = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sen/7/altitude") == 0) {
    cpd.altitude = (uint16_t) integerValue; return;
  }


  if (strcmp(topic, "cd/"UID"/sound") == 0) {
    cpd.sound = (bool) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/wcheck") == 0) {
    cpd.waterCheck = (bool) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sleep") == 0) {
    cpd.sleep = (bool) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sleep_after") == 0) {
    cpd.sleepAfter = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/send_data_every") == 0) {
    cpd.sendDataToServerEvery = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/sensor_recheck_every") == 0) {
    cpd.checkSensorEvery = (uint16_t) integerValue; return;
  }

  if (strcmp(topic, "cd/"UID"/screen_light") == 0) {
    cpd.screenLight = (bool) integerValue; return;
  }


  if (strcmp(topic, "cd/"UID"/date/second") == 0) {
    cpd.dateSecond = (uint8_t) integerValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }

  if (strcmp(topic, "cd/"UID"/date/minute") == 0) {
    cpd.dateMinute = (uint8_t) integerValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }

  if (strcmp(topic, "cd/"UID"/date/hour") == 0) {
    cpd.dateHour = (uint8_t) integerValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }

  if (strcmp(topic, "cd/"UID"/date/day") == 0) {
    cpd.dateDay = (uint8_t) integerValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }

  if (strcmp(topic, "cd/"UID"/date/month") == 0) {
    cpd.dateMonth = (uint8_t) integerValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }

  if (strcmp(topic, "cd/"UID"/date/year") == 0) {
    cpd.dateYear = (uint16_t) integerValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }

  String strValue = String(( char *) payload);

  if (strcmp(topic, "cd/"UID"/wifi/ssid") == 0) {
    sscanf(data, " %s ", cpd.wifiSSID);
    return;
  }

  if (strcmp(topic, "cd/"UID"/wifi/pass") == 0) {
    sscanf(data, " %s ", cpd.wifiPASS);
    return;
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

#include "global.h"

void saveAllDataToMemory() {
  memory.putBool("ch0Type", cpd.channelType[0]);
  memory.putBool("ch1Type", cpd.channelType[1]);
  memory.putBool("ch2Type", cpd.channelType[2]);
  memory.putBool("ch3Type", cpd.channelType[3]);

  memory.putBool("ch0Logic", cpd.channelLogic[0]);
  memory.putBool("ch1Logic", cpd.channelLogic[1]);
  memory.putBool("ch2Logic", cpd.channelLogic[2]);
  memory.putBool("ch3Logic", cpd.channelLogic[3]);

  memory.putUShort("channelVal0", cpd.channelValue[0]);
  memory.putUShort("channelVal1", cpd.channelValue[1]);
  memory.putUShort("channelVal2", cpd.channelValue[2]);
  memory.putUShort("channelVal3", cpd.channelValue[3]);

  memory.putDouble("maintVal0", cpd.maintainValue[0]);
  memory.putDouble("maintVal1", cpd.maintainValue[1]);
  memory.putDouble("maintVal2", cpd.maintainValue[2]);
  memory.putDouble("maintVal3", cpd.maintainValue[3]);

  memory.putChar("chCtrlMode0", cpd.channelControlMode[0]);
  memory.putChar("chCtrlMode1", cpd.channelControlMode[1]);
  memory.putChar("chCtrlMode2", cpd.channelControlMode[2]);
  memory.putChar("chCtrlMode3", cpd.channelControlMode[3]);

  memory.putBool("pidDir0", cpd.pidDirection[0]);
  memory.putBool("pidDir1", cpd.pidDirection[1]);
  memory.putBool("pidDir2", cpd.pidDirection[2]);
  memory.putBool("pidDir3", cpd.pidDirection[3]);

  memory.putDouble("pidKp0", cpd.pidKp[0]);
  memory.putDouble("pidKp1", cpd.pidKp[1]);
  memory.putDouble("pidKp2", cpd.pidKp[2]);
  memory.putDouble("pidKp3", cpd.pidKp[3]);

  memory.putDouble("pidKi0", cpd.pidKi[0]);;
  memory.putDouble("pidKi1", cpd.pidKi[1]);
  memory.putDouble("pidKi2", cpd.pidKi[2]);
  memory.putDouble("pidKi3", cpd.pidKi[3]);

  memory.putDouble("pidKd0", cpd.pidKd[0]);
  memory.putDouble("pidKd1", cpd.pidKd[1]);
  memory.putDouble("pidKd2", cpd.pidKd[2]);
  memory.putDouble("pidKd3", cpd.pidKd[3]);

  memory.putULong("pidDt0", cpd.pidDt[0]);
  memory.putULong("pidDt1", cpd.pidDt[1]);
  memory.putULong("pidDt2", cpd.pidDt[2]);
  memory.putULong("pidDt3", cpd.pidDt[3]);

  memory.putBool("relDir0", cpd.relayDirection[0]);
  memory.putBool("relDir1", cpd.relayDirection[1]);
  memory.putBool("relDir2", cpd.relayDirection[2]);
  memory.putBool("relDir3", cpd.relayDirection[3]);

  memory.putDouble("relHyst0", cpd.relayHysteresis[0]);
  memory.putDouble("relHyst1", cpd.relayHysteresis[1]);
  memory.putDouble("relHyst2", cpd.relayHysteresis[2]);
  memory.putDouble("relHyst3", cpd.relayHysteresis[3]);

  memory.putDouble("relK0", cpd.relayK[0]);
  memory.putDouble("relK1", cpd.relayK[1]);
  memory.putDouble("relK2", cpd.relayK[2]);
  memory.putDouble("relK3", cpd.relayK[3]);

  memory.putULong("relDt0", cpd.relayDt[0]);
  memory.putULong("relDt1", cpd.relayDt[1]);
  memory.putULong("relDt2", cpd.relayDt[2]);
  memory.putULong("relDt3", cpd.relayDt[3]);

  memory.putBool("sound", cpd.sound);
  memory.putBool("waterCheck", cpd.waterCheck);
  memory.putBool("screenLight", cpd.screenLight);
  memory.putBool("screensaver", cpd.screensaver);
  memory.putUShort("screensType", cpd.screensaverType);
  memory.putUInt("screensAfter", cpd.screensaverAfter);

  memory.putString("wifiSSID", String(cpd.wifiSSID));
  memory.putString("wifiPASS", String(cpd.wifiPASS));

  memory.putULong("sendTserver", cpd.sendDataToServerEvery);
  memory.putUShort("recheckSens", cpd.checkSensorEvery);
  memory.putBool("turnOff", cpd.turnOff);
  memory.putUShort("rstCounter", cpd.restartCounter);
  memory.putUShort("WTinSecs", cpd.workedTimeInSeconds);
  memory.putULong("WTinHours", cpd.workedTimeInHours);
}

void readAllDataFromMemoryToRAM() {
  cpd.channelType[0] = memory.getBool("ch0Type", 0);
  cpd.channelType[1] = memory.getBool("ch1Type", 0);
  cpd.channelType[2] = memory.getBool("ch2Type", 0);
  cpd.channelType[3] = memory.getBool("ch3Type", 0);

  cpd.channelLogic[0] = memory.getBool("ch0Logic", 0);
  cpd.channelLogic[1] = memory.getBool("ch1Logic", 0);
  cpd.channelLogic[2] = memory.getBool("ch2Logic", 0);
  cpd.channelLogic[3] = memory.getBool("ch3Logic", 0);

  cpd.channelValue[0] = memory.getUShort("channelVal0", 0);
  cpd.channelValue[1] = memory.getUShort("channelVal1", 0);
  cpd.channelValue[2] = memory.getUShort("channelVal2", 0);
  cpd.channelValue[3] = memory.getUShort("channelVal3", 0);

  cpd.maintainValue[0] = memory.getDouble("maintVal0", 30.0);
  cpd.maintainValue[1] = memory.getDouble("maintVal1", 30.0);
  cpd.maintainValue[2] = memory.getDouble("maintVal2", 30.0);
  cpd.maintainValue[3] = memory.getDouble("maintVal3", 30.0);

  cpd.channelControlMode[0] = memory.getChar("chCtrlMode0", 0);
  cpd.channelControlMode[1] = memory.getChar("chCtrlMode1", 0);
  cpd.channelControlMode[2] = memory.getChar("chCtrlMode2", 0);
  cpd.channelControlMode[3] = memory.getChar("chCtrlMode3", 0);

  cpd.pidDirection[0] = memory.getBool("pidDir0", 0);
  cpd.pidDirection[1] = memory.getBool("pidDir1", 0);
  cpd.pidDirection[2] = memory.getBool("pidDir2", 0);
  cpd.pidDirection[3] = memory.getBool("pidDir3", 0);

  cpd.pidKp[0] = memory.getDouble("pidKp0", 0.1);
  cpd.pidKp[1] = memory.getDouble("pidKp1", 0.1);
  cpd.pidKp[2] = memory.getDouble("pidKp2", 0.1);
  cpd.pidKp[3] = memory.getDouble("pidKp3", 0.1);

  cpd.pidKi[0] = memory.getDouble("pidKi0", 0.05);
  cpd.pidKi[1] = memory.getDouble("pidKi1", 0.05);
  cpd.pidKi[2] = memory.getDouble("pidKi2", 0.05);
  cpd.pidKi[3] = memory.getDouble("pidKi3", 0.05);

  cpd.pidKd[0] = memory.getDouble("pidKd0", 0.01);
  cpd.pidKd[1] = memory.getDouble("pidKd1", 0.01);
  cpd.pidKd[2] = memory.getDouble("pidKd2", 0.01);
  cpd.pidKd[3] = memory.getDouble("pidKd3", 0.01);

  cpd.pidDt[0] = memory.getULong("pidDt0", 1000);
  cpd.pidDt[1] = memory.getULong("pidDt1", 1000);
  cpd.pidDt[2] = memory.getULong("pidDt2", 1000);
  cpd.pidDt[3] = memory.getULong("pidDt3", 1000);

  cpd.relayDirection[0] = memory.getBool("relDir0", 0);
  cpd.relayDirection[1] = memory.getBool("relDir1", 0);
  cpd.relayDirection[2] = memory.getBool("relDir2", 0);
  cpd.relayDirection[3] = memory.getBool("relDir3", 0);

  cpd.relayHysteresis[0] = memory.getDouble("relHyst0", 5.0);
  cpd.relayHysteresis[1] = memory.getDouble("relHyst1", 5.0);
  cpd.relayHysteresis[2] = memory.getDouble("relHyst2", 5.0);
  cpd.relayHysteresis[3] = memory.getDouble("relHyst3", 5.0);

  cpd.relayK[0] = memory.getDouble("relK0", 0.5);
  cpd.relayK[1] = memory.getDouble("relK1", 0.5);
  cpd.relayK[2] = memory.getDouble("relK2", 0.5);
  cpd.relayK[3] = memory.getDouble("relK3", 0.5);

  cpd.relayDt[0] = memory.getULong("relDt0", 500);
  cpd.relayDt[1] = memory.getULong("relDt1", 500);
  cpd.relayDt[2] = memory.getULong("relDt2", 500);
  cpd.relayDt[3] = memory.getULong("relDt3", 500);

  cpd.sound =       memory.getBool("sound", false);
  cpd.waterCheck =  memory.getBool("waterCheck", false);
  cpd.screenLight = memory.getBool("screenLight", true);
  cpd.screensaver = memory.getBool("screensaver", true);
  cpd.screensaverType = memory.getUShort("screensType", 0);
  cpd.screensaverAfter = memory.getUInt("screensAfter", 10000);

  memory.getString("wifiSSID", cpd.wifiSSID, 20);
  memory.getString("wifiPASS", cpd.wifiPASS, 20);

  cpd.sendDataToServerEvery = memory.getULong("sendTserver", 1000UL);
  cpd.checkSensorEvery =      memory.getUShort("recheckSens", 10UL);
  cpd.turnOff =               memory.getBool("turnOff", false);
  cpd.restartCounter =        memory.getUShort("rstCounter", 0);
  cpd.workedTimeInSeconds =   memory.getUShort("WTinSecs", 0);
  cpd.workedTimeInHours =     memory.getULong("WTinHours", 0);
}

void setupMemory() {
  memory.begin("app-data", false);
  if (memory.getChar("isFirst", (int8_t) - 18) == -18) {
    memory.putChar("isFirst", 18);
    saveAllDataToMemory();
  }
  readAllDataFromMemoryToRAM();
  cpd.restartCounter++;
  memory.putUShort("rstCounter", cpd.restartCounter);
}

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
  client.subscribe("cd/"UID"/screen_light");
  client.subscribe("cd/"UID"/screensaver");
  client.subscribe("cd/"UID"/screensaver_type");
  client.subscribe("cd/"UID"/screensaver_after");

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
  client.subscribe("cd/"UID"/save_all");
  client.subscribe("cd/"UID"/read_all");
  //client.subscribe("cd/"UID"/reset");
  client.subscribe("cd/"UID"/reboot");
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
  msg += "\"screenLight\":\"" + String(cpd.screenLight) + "\",";
  msg += "\"screensaver\":\"" + String(cpd.screensaver) + "\",";
  msg += "\"screensaverType\":\"" + String(cpd.screensaverType) + "\",";
  msg += "\"screensaverAfter\":\"" + String(cpd.screensaverAfter) + "\",";

  
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


  // ???????????????? ?????? ????????????

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


  // ???????????????? ???????????????? ???????????? ?????????????????? ??????????????

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


  // ???????????????? ?????????????? ???????????????? ?????????????? ?????????? ????????????????

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


  // ???????????????? ???????????????? ??????????????, ???? ???????????? ???????????????????????????????? ??????????

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


  // ???????????????? ???????????????? ?????????????????????? ???????????? ?????? ???????????? 0-65535 ?????? ???????? ?????? ???????? 0-1

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


  // ???????????????? ???????????????? ???????????? ?????? ???????????? 0 ?????? 1

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


  // ???????????????? ?????????? ?????????????????? ?????????????? 0-????????????, 1-?????????????????? ...

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


  // ???????????????? ???????????? ?????????????????? ?????? ??????????????????????

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


  // ???????????????? ?????????????????????? ???????????????? ?????? ????????????????????

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


  // ???????????????? ?????????????????????? ???????????????? ?????? ????????????????????

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


  // ???????????????? ???????????????????????????? ???????????????? ?????? ????????????????????

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


  // ???????????????? ?????? ?????????????????????????? ?????? ????????????????????

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


  // ???????????????? ???????????? ?????????????????? ?????????????????? ????????????????????

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


  // ???????????????? ???????????????? ?????????????????????? ?????????????????? ????????????????????

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


  // ???????????????? ???????????????????? ???????????????????????? ??????????????

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


  // ???????????????? ?????? ????????????????

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


  // ?????????? ??????????
  if (strcmp(topic, "cd/"UID"/sound") == 0) {
    cpd.sound = (bool) uiValue; return;
  }
  // ?????????? ?????????????????? ????????
  if (strcmp(topic, "cd/"UID"/wcheck") == 0) {
    cpd.waterCheck = (bool) uiValue; return;
  }
  // ?????????????????? ????????????
  if (strcmp(topic, "cd/"UID"/screen_light") == 0) {
    cpd.screenLight = (bool) uiValue; return;
  }
  // ????????????????
  if (strcmp(topic, "cd/"UID"/screensaver") == 0) {
    cpd.screensaver = (bool) uiValue; return;
  }
  // ?????????? ????????????????
  if (strcmp(topic, "cd/"UID"/screensaver_type") == 0) {
    cpd.screensaverType = (uint16_t) uiValue; return;
  }
  // ?????? ?????????? ?????????? ?????????????????????????? ????????????????
  if (strcmp(topic, "cd/"UID"/screensaver_after") == 0) {
    cpd.screensaverAfter = (uint32_t) uiValue; return;
  }


  
  // ?????? ??????????????
  if (strcmp(topic, "cd/"UID"/date/second") == 0) {
    cpd.dateSecond = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // ?????? ??????????????
  if (strcmp(topic, "cd/"UID"/date/minute") == 0) {
    cpd.dateMinute = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // ?????? ????????????
  if (strcmp(topic, "cd/"UID"/date/hour") == 0) {
    cpd.dateHour = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // ?????? ????????
  if (strcmp(topic, "cd/"UID"/date/day") == 0) {
    cpd.dateDay = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // ?????? ????????????
  if (strcmp(topic, "cd/"UID"/date/month") == 0) {
    cpd.dateMonth = (uint8_t) uiValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }
  // ?????? ??????
  if (strcmp(topic, "cd/"UID"/date/year") == 0) {
    cpd.dateYear = (uint16_t) ulValue;
    rtc.adjust(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
    return;
  }


  // ?????????? ?????????? ??????????????
  if (strcmp(topic, "cd/"UID"/wifi/ssid") == 0) {
    sscanf(data, " %s ", cpd.wifiSSID);
    return;
  }
  // ???????????? ?????????? ??????????????
  if (strcmp(topic, "cd/"UID"/wifi/pass") == 0) {
    sscanf(data, " %s ", cpd.wifiPASS);
    return;
  }


  // ?????????????????? ???????? ???? ???????????? ???????????? ????
  if (strcmp(topic, "cd/"UID"/send_data_every") == 0) {
    cpd.sendDataToServerEvery = (uint32_t) ulValue; return;
  }
  // ???????????????????? ?????????????? ???????????? ????
  if (strcmp(topic, "cd/"UID"/sensor_recheck_every") == 0) {
    cpd.checkSensorEvery = (uint16_t) uiValue; return;
  }
  // ?????????????????? ?????????????????? ????????????????
  if (strcmp(topic, "cd/"UID"/turn_off") == 0) {
    cpd.turnOff = (bool) uiValue; return;
  }
  // ?????????????????? ?????????????????????????????? ????????????????????
  if (strcmp(topic, "cd/"UID"/counter/restart") == 0) {
    cpd.restartCounter = (uint16_t) uiValue; return;
  }
  // ?????????????????? ???????????? ???????????????????? ?? ????????????????
  if (strcmp(topic, "cd/"UID"/counter/worked_in_seconds") == 0) {
    cpd.workedTimeInSeconds = (uint16_t) uiValue; return;
  }
  // ?????????????????? ???????????? ???????????????????? ?? ??????????????
  if (strcmp(topic, "cd/"UID"/counter/worked_in_hours") == 0) {
    cpd.workedTimeInHours = (uint32_t) ulValue; return;
  }

  // ?????? ??????????????????
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

  // ???????????????? ????????????????????????
  if (strcmp(topic, "cd/"UID"/save_all") == 0) {
    saveAllDataToMemory();
  }

  // ???????????????? ???????????????????????? ?? ??????'??????
  if (strcmp(topic, "cd/"UID"/read_all") == 0) {
    readAllDataFromMemoryToRAM();
  }
  /*
    // ?????????????????????????? ?????????????????? (???????? ???????????? ??????????????????)
    if (strcmp(topic, "cd/"UID"/reset") == 0) {
      ESP.reset();
    }
  */
  // ?????????????????????????? ?????????????????? (????????????????)
  if (strcmp(topic, "cd/"UID"/reboot") == 0) {
    ESP.restart();
  }
}


void setup_wifi() {
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(cpd.wifiSSID, cpd.wifiPASS);
  /*
    if (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
  */
  randomSeed(micros());
}


void reconnect() {
  if (!client.connected()) {
    if (client.connect(UID))
      subscribeEndpoints();
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

void mqttLoop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  if (millis() - lastSendToServer > (unsigned long)cpd.sendDataToServerEvery) {
    lastSendToServer =  millis();
    client.publish("outTopic", createJSON().c_str());
    setCurrentDateTime();
    printDate();
  }
}






void setupClock() {
  rtc.begin(DateTime(cpd.dateYear, cpd.dateMonth, cpd.dateDay, cpd.dateHour, cpd.dateMinute, cpd.dateSecond));
}

void setupLCD() {
  lcd.begin();
  lcd.clear();
  lcd.backlight();

  lcd.createChar(0, (uint8_t*)scroll_bar[0]);
  lcd.createChar(1, (uint8_t*)scroll_bar[1]);
  lcd.createChar(2, (uint8_t*)scroll_bar[2]);
  lcd.createChar(3, (uint8_t*)scroll_bar[3]);
  lcd.createChar(4, (uint8_t*)scroll_bar[4]);

}


void singleClick(Button2& btn) {
  if (!encoderMovedWithPressedButton) {   // ???????? ???????????????????????? ?????????????? ???? ???? ???????????????????? ??????????????
    LCDML.BT_enter();
    Serial.println("?????????????? ????????");
  }
  encoderMovedWithPressedButton = false;  // ????????'???????????? ???????????????? ??????????????????
}

void pressed(Button2& btn) {
  buttonIsPressed = true;
}

void released(Button2& btn) {
  buttonIsPressed = false;
}

void longSingleClick(Button2& btn) {
  if (!encoderMovedWithPressedButton) {   // ???????? ???????????????????????? ?????????????? ???? ???? ???????????????????? ??????????????
    longPress = true;
    Serial.println("???????????? ????????");
  }
  encoderMovedWithPressedButton = false;  // ????????'???????????? ???????????????? ??????????????????
}

void doubleClick(Button2& btn) {
  if (!encoderMovedWithPressedButton) {   // ???????? ???????????????????????? ?????????????? ???? ???? ???????????????????? ??????????????
    LCDML.BT_quit();
    Serial.println("?????????????????? ????????");
  }
  encoderMovedWithPressedButton = false;  // ????????'???????????? ???????????????? ??????????????????
}
void tripleClick(Button2& btn) {
  if (!encoderMovedWithPressedButton) {   // ???????? ???????????????????????? ?????????????? ???? ???? ???????????????????? ??????????????
    triplePress = true;
    Serial.println("?????????????????? ????????");
  }
  encoderMovedWithPressedButton = false;  // ????????'???????????? ???????????????? ??????????????????
}

void encSetup() {
  ESP32Encoder::useInternalWeakPullResistors = UP;
  encoder.attachHalfQuad(19, 18);
  encoder.setCount(0);

  button.setLongClickTime(1000);
  // button.setDoubleClickTime(400);
  // button.setChangedHandler(changed);
  button.setPressedHandler(pressed);
  button.setReleasedHandler(released);
  // button.setTapHandler(tap);
  //button.setLongClickDetectedHandler(longClickDetected);
  button.setClickHandler(singleClick);
  button.setLongClickHandler(longSingleClick);
  button.setDoubleClickHandler(doubleClick);
  button.setTripleClickHandler(tripleClick);
}

void encLoop() {
  button.loop();
  int encCounter = encoder.getCount();
  if (encCounter > 0 && buttonIsPressed) {                                  // ?????????????? ???????????????????? ???????????? ?????? ???????????????????? ????????????
    Serial.println("?????????????????? ????????????  -  ?????????????? ???????????? -> -> -> ->");
    encoderMovedWithPressedButton = true;                                   // ?????????????????? ???????????????????????? ???????????????? ????????????????????, ???????? ?????????????? ???????????????????????? ???? ?????? ?????????????? 1??
    encoder.setCount(0);
    LCDML.BT_right();
  } else if (encCounter < 0 && buttonIsPressed) {                           // ?????????????? ???????????????????? ?????????? ?????? ???????????????????? ????????????
    Serial.println("?????????????????? ????????????  -  ?????????????? ?????????? <- <- <- <-");
    encoderMovedWithPressedButton = true;                                   // ?????????????????? ???????????????????????? ???????????????? ????????????????????, ???????? ?????????????? ???????????????????????? ???? ?????? ?????????????? 1??
    encoder.setCount(0);
    LCDML.BT_left();
  } else if (encCounter > 0) {                                              // ?????????????? ???????????????????? ????????????
    Serial.println("?????????????? ???????????? -> -> -> ->");
    encoder.setCount(0);
    LCDML.BT_down();
  } else if (encCounter < 0) {                                              // ?????????????? ???????????????????? ??????????
    Serial.println("?????????????? ?????????? <- <- <- <-");
    encoder.setCount(0);
    LCDML.BT_up();
  }
}


void checkScreenLight() {
  if (cpd.screenLight)
    lcd.backlight();
  else
    lcd.noBacklight();
}

void autoSave() {
  if (pastHour != cpd.dateHour) {
    pastHour = cpd.dateHour;
    cpd.workedTimeInHours += 1;
    activeHoursCounter++;
  }
  if (activeHoursCounter == 5) {                                          // ???? 5 ?????????? ?????????????????? ?????????????????? ????????
    activeHoursCounter = 0;
    memory.putULong("WTinHours", cpd.workedTimeInHours);
  }
}

bool getRelaySignalON(bool inputSignal, uint8_t ch) {
  return (cpd.channelLogic[ch] == false ? false : true);
}

bool getRelaySignalOFF(bool inputSignal, uint8_t ch) {
  return (cpd.channelLogic[ch] == true ? true : false);
}

void setupChannelRegulators() {
  for (byte i = 0; i < 4; i++) {
    pinMode(sensors[i], INPUT);
    if (cpd.channelType[i] == TYPE_DIMMER) {
      ledcSetup(chId[i], chFreq[i], chResolution[i]);
      ledcAttachPin(chPin[i], chId[i]);

      pid[i].setDirection(cpd.pidDirection[i]);
      pid[i].setMode(ON_ERROR);
      pid[i].setPwmLimits(0, 65535);
      pid[i].setMaintainValue(cpd.maintainValue[i]);
      pid[i].setKp(cpd.pidKp[i]);
      pid[i].setKi(cpd.pidKi[i]);
      pid[i].setKd(cpd.pidKd[i]);
      pid[i].setDt(cpd.pidDt[i]);
    }

    else if (cpd.channelType[i] == TYPE_RELAY) {
      pinMode(chPin[i], OUTPUT);
      reg[i] = GyverRelay(cpd.relayDirection[i]);
      reg[i].setpoint = cpd.maintainValue[i];
      reg[i].hysteresis = cpd.relayHysteresis[i];
      reg[i].k = cpd.relayK[i];
      reg[i].dT = cpd.relayDt[i];

      /*
        reg[i].setDirection(cpd.relayDirection[i]);
        reg[i].setMaintainValue(cpd.maintainValue[i]);
        reg[i].setHysteresis(cpd.relayHysteresis[i]);
        reg[i].setK(cpd.relayK[i]);
        reg[i].setDt(cpd.relayDt[i]);
      */
    }

  }
}


void regulate(uint8_t ch) {
  if (cpd.channelControlMode[ch] == AUTO_MODE) {
    if (cpd.channelType[ch] == TYPE_DIMMER) {
      pid[ch].setInput(cpd.analogSensorData[ch]);
      cpd.channelValue[ch] = pid[ch].getResultTimer();
      ledcWrite(chId[ch], cpd.channelValue[ch]);
    }
    if (cpd.channelType[ch] == TYPE_RELAY) {
      reg[ch].input = cpd.analogSensorData[ch];
      cpd.channelValue[ch] = reg[ch].getResultTimer();
      digitalWrite(chPin[ch], (bool) cpd.channelValue[ch]);
      /*
        reg[ch].setInput(cpd.analogSensorData[ch]);
        cpd.channelValue[ch] = reg[ch].getResultTimer();
        digitalWrite(chPin[ch], (bool) cpd.channelValue[ch]);
      */
    }
  }
  else if (cpd.channelControlMode[ch] == MANUAL_MODE || cpd.channelControlMode[ch] == WIFI_MODE) {
    if (cpd.channelType[ch] == TYPE_DIMMER) {
      ledcWrite(chId[ch], cpd.channelValue[ch]);
    }
    if (cpd.channelType[ch] == TYPE_RELAY) {
      digitalWrite(chPin[ch], (bool) cpd.channelValue[ch]);
    }
  }
}


void regulatorLoop() {

  sensor.getMoistureInPercentage(cpd.analogSensorData);
  regulate(0);
  regulate(1);
  regulate(2);
  regulate(3);
}

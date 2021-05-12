#define TYPE_RELAY 0
#define TYPE_DIMMER 1
#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1
uint8_t alphabetCounter = 0;
uint8_t letterCounter = 0;
char alphabet[67] = {'_', 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '-', '.'};
//char text[20] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
String modes[] = {"Manual", "Auto  ", "WiFi  "};
String onOff[] = {"Off", "On "};
String chType[] = {"Relay ", "Dimmer"};
int tempBackup = 0;
bool changeFlag = false;


void setupDoubleValue(const char label1[], const char label2[], uint8_t numRowWithVal, double &variable, double bannedMin, double bannedMax, const char savingName[]) {
  if (LCDML.FUNC_setup()) {
    changeFlag = false;

    lcd.setCursor(0, 0);
    lcd.print(label1);
    lcd.setCursor(0, 1);
    lcd.print(label2);
    lcd.setCursor(0, numRowWithVal);
    lcd.print(String(variable));

    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {
    if (longPress == true) {// ##########################################                         ЗБЕРІГАННЯ ДАНИХ
      longPress = false;
      changeFlag = true;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      memory.putDouble(savingName, variable);
      LCDML.FUNC_goBackToMenu();
    }

    else if (triplePress == true) {// ###################################            СТЕРТИ ВСЕ
      triplePress = false;
      changeFlag = true;
      variable = 0.0;
    }

    else if (LCDML.BT_checkDown()) {// ##################################            КРОК У ЦІЛИХ ВПРАВО
      changeFlag = true;
      variable += 1.0;

      if (variable > 100.0)
        variable = 0.0;

    }

    else if (LCDML.BT_checkUp()) {// ####################################             КРОК У ЦІЛИХ ВЛІВО
      changeFlag = true;
      variable -= 1.0;

      if (variable < 0.0)
        variable = 100.0;
    }

    else if (LCDML.BT_checkRight()) {// #################################                КРОК У СОТИХ ВПРАВО
      changeFlag = true;
      variable += 0.01;

      if (variable > bannedMax)
        variable = bannedMin;
    }

    else if (LCDML.BT_checkLeft()) {// ##################################                 КРОК У СОТИХ ВЛІВО
      changeFlag = true;
      variable -= 0.01;

      if (variable < bannedMin)
        variable = bannedMax;
    }

    if (changeFlag) {
      changeFlag = false;
      lcd.setCursor(0, numRowWithVal);
      lcd.print("                    ");
      lcd.setCursor(0, numRowWithVal);
      lcd.print(String(variable));
    }

  }

  if (LCDML.FUNC_close()) {
    changeFlag = false;
  }
}

void setupIntegerValue(const char label1[], const char label2[], uint8_t numRowWithVal, uint32_t &variable, uint32_t minV, uint32_t maxV, const char savingName[]) {
  if (LCDML.FUNC_setup()) {
    changeFlag = false;

    lcd.setCursor(0, 0);
    lcd.print(label1);
    lcd.setCursor(0, 1);
    lcd.print(label2);
    lcd.setCursor(0, numRowWithVal);
    lcd.print(String(variable));

    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {
    if (longPress == true) {// ##########################################                         ЗБЕРІГАННЯ ДАНИХ
      longPress = false;
      changeFlag = true;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      memory.putDouble(savingName, variable);
      LCDML.FUNC_goBackToMenu();
    }

    else if (triplePress == true) {// ###################################            СТЕРТИ ВСЕ
      triplePress = false;
      changeFlag = true;
      variable = 0;
    }

    else if (LCDML.BT_checkEnter()) {// #################################    ДОДАТИ ТИСЯЧУ
      changeFlag = true;
      variable += 1000;

      if (variable > maxV)
        variable = minV;
    }

    else if (LCDML.BT_checkDown()) {// ##################################            ДОДАТИ 1
      changeFlag = true;
      variable += 1;

      if (variable > maxV)
        variable = minV;

    }

    else if (LCDML.BT_checkUp()) {// ####################################             ВІДНЯТИ 1
      changeFlag = true;
      variable -= 1;

      if (variable < minV)
        variable = maxV;
    }

    else if (LCDML.BT_checkRight()) {// #################################             ДОДАТИ 100
      changeFlag = true;
      variable += 100;

      if (variable > maxV)
        variable = minV;
    }

    else if (LCDML.BT_checkLeft()) {// ##################################             ВІДНЯТИ 100
      changeFlag = true;
      variable -= 100;

      if (variable < minV)
        variable = maxV;
    }

    if (changeFlag) {
      changeFlag = false;
      lcd.setCursor(0, numRowWithVal);
      lcd.print("                    ");
      lcd.setCursor(0, numRowWithVal);
      lcd.print(String(variable));
    }

  }

  if (LCDML.FUNC_close()) {
    changeFlag = false;
  }
}

void setupChooserValue(const char label1[], const char label2[], uint8_t numRowWithVal, uint16_t &variable, String names[], uint16_t N, const char savingName[]) {
  if (LCDML.FUNC_setup()) {
    changeFlag = false;

    lcd.setCursor(0, 0);
    lcd.print(label1);
    lcd.setCursor(0, 1);
    lcd.print(label2);
    lcd.setCursor(0, numRowWithVal);
    lcd.print(names[variable]);

    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {
    if (longPress == true) {// ##########################################                         ЗБЕРІГАННЯ ДАНИХ
      longPress = false;
      changeFlag = true;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      memory.putDouble(savingName, variable);
      LCDML.FUNC_goBackToMenu();
    }

    else if (triplePress == true) {// ###################################            НА ПОЧАТОК
      triplePress = false;
      changeFlag = true;
      variable = 0;
    }

    else if (LCDML.BT_checkDown()) {// ##################################            РУХ ->
      changeFlag = true;
      variable += 1;
      variable %= N;
    }

    else if (LCDML.BT_checkUp()) {// ####################################            РУХ <-
      changeFlag = true;
      if (variable < 0)
        variable = (N - 1);
      else
        variable -= 1;
    }

    if (changeFlag) {
      changeFlag = false;
      lcd.setCursor(0, numRowWithVal);
      lcd.print("                    ");
      lcd.setCursor(0, numRowWithVal);
      lcd.print(names[variable]);
    }

  }

  if (LCDML.FUNC_close()) {
    changeFlag = false;
  }
}

void setupBoolValue(const char label1[], const char label2[], uint8_t numRowWithVal, const char trueState[], const char falseState[], bool &variable, const char savingName[]) {
  if (LCDML.FUNC_setup()) {
    changeFlag = false;

    lcd.setCursor(0, 0);
    lcd.print(label1);
    lcd.setCursor(0, 1);
    lcd.print(label2);
    lcd.setCursor(0, numRowWithVal);
    lcd.print((variable == true ? trueState : falseState));

    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {
    if (longPress == true) {
      longPress = false;
      changeFlag = true;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      memory.putBool(savingName, variable);
      LCDML.FUNC_goBackToMenu();
    }
    else if (LCDML.BT_checkDown()) {
      changeFlag = true;
      variable = !variable;
    }
    else if (LCDML.BT_checkUp()) {
      changeFlag = true;
      variable = !variable;
    }
    if (changeFlag) {
      changeFlag = false;
      lcd.setCursor(0, numRowWithVal);
      lcd.print("                    ");
      lcd.setCursor(0, numRowWithVal);
      lcd.print((variable == true ? trueState : falseState));
    }
  }

  if (LCDML.FUNC_close()) {
    changeFlag = false;
  }
}

void controlMode(uint8_t ch) {
  if (LCDML.FUNC_setup()) {

    lcd.setCursor(0, 0);
    lcd.print("CHANNEL "); lcd.print(String(ch));
    lcd.setCursor(0, 1);
    String currentMode = modes[cpd.channelControlMode[ch]];
    lcd.print("Control Mode: ");
    lcd.setCursor(14, 1);
    lcd.print(currentMode);

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (longPress == true) {
      longPress = false;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      if (ch == 0)
        memory.putChar("chCtrlMode0", cpd.channelControlMode[0]);
      else if (ch == 1)
        memory.putChar("chCtrlMode1", cpd.channelControlMode[1]);
      else if (ch == 2)
        memory.putChar("chCtrlMode2", cpd.channelControlMode[2]);
      else if (ch == 3)
        memory.putChar("chCtrlMode3", cpd.channelControlMode[3]);
      LCDML.FUNC_goBackToMenu();

    }
    else if (LCDML.BT_checkDown()) {
      cpd.channelControlMode[ch] += 1;
      cpd.channelControlMode[ch] %= 3;
      lcd.setCursor(14, 1);
      lcd.print(modes[cpd.channelControlMode[ch]]);
      Serial.println(modes[cpd.channelControlMode[ch]]);
    }
    else if (LCDML.BT_checkUp()) {
      if (cpd.channelControlMode[ch] == 0)
        cpd.channelControlMode[ch] = 2;
      else
        cpd.channelControlMode[ch] -= 1;
      lcd.setCursor(14, 1);
      lcd.print(modes[cpd.channelControlMode[ch]]);
      Serial.println(modes[cpd.channelControlMode[ch]]);
    }
  }

  if (LCDML.FUNC_close()) {
  }
}

void printChannelValue(uint8_t ch) {
  lcd.setCursor(0, 1);
  lcd.print("      ");
  lcd.setCursor(0, 1);
  if (cpd.channelType[ch] == TYPE_RELAY) {
    if (cpd.channelLogic[ch] == ACTIVE_LOW)
      lcd.print((cpd.channelValue[ch] == ACTIVE_LOW ? onOff[1] : onOff[0]));

    else if (cpd.channelLogic[ch] == ACTIVE_HIGH)
      lcd.print((cpd.channelValue[ch] == ACTIVE_HIGH ? onOff[1] : onOff[0]));
  }

  else if (cpd.channelType[ch] == TYPE_DIMMER) {
    lcd.print(String(cpd.channelValue[ch]));
  }
}

void channelOpenValue(uint8_t ch) {
  if (LCDML.FUNC_setup()) {
    tempBackup = cpd.channelControlMode[ch];                              // Зберігаємо попередній режим каналу
    cpd.channelControlMode[ch] = 0;                                       // Переводимо в ручний режим керування

    lcd.setCursor(0, 0);
    lcd.print("Channel Open Value ");
    lcd.setCursor(0, 1);
    printChannelValue(ch);

    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {
    if (longPress == true) {
      longPress = false;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }

      if (ch == 0)
        memory.putUShort("channelVal0", cpd.channelValue[0]);
      else if (ch == 1)
        memory.putUShort("channelVal1", cpd.channelValue[1]);
      else if (ch == 2)
        memory.putUShort("channelVal2", cpd.channelValue[2]);
      else if (ch == 3)
        memory.putUShort("channelVal3", cpd.channelValue[3]);
      LCDML.FUNC_goBackToMenu();

    }
    else if (LCDML.BT_checkDown()) {
      if (cpd.channelType[ch] == TYPE_RELAY) {
        cpd.channelValue[ch] += 1;
        cpd.channelValue[ch] %= 2;
      } else if (cpd.channelType[ch] == TYPE_DIMMER) {
        cpd.channelValue[ch] += 100;
        cpd.channelValue[ch] %= 65536;
      }
      printChannelValue(ch);
    }
    else if (LCDML.BT_checkUp()) {
      if (cpd.channelType[ch] == TYPE_RELAY) {
        if (cpd.channelValue[ch] == 0)
          cpd.channelValue[ch] = 1;
        else
          cpd.channelValue[ch] -= 1;
      } else if (cpd.channelType[ch] == TYPE_DIMMER) {
        if (cpd.channelValue[ch] == 0)
          cpd.channelValue[ch] = 65535;
        else
          cpd.channelValue[ch] -= 100;
      }
      printChannelValue(ch);
    }
  }

  if (LCDML.FUNC_close()) {
    cpd.channelControlMode[ch] = tempBackup;                                // Відновлюємо попередній режим каналу
  }
}


void channelType(uint8_t ch) {
  if (ch == 0)
    setupBoolValue("Channel Type", "", 1, "Dimmer", "Relay", cpd.channelType[ch], "ch0Type");
  else if (ch == 1)
    setupBoolValue("Channel Type", "", 1, "Dimmer", "Relay", cpd.channelType[ch], "ch1Type");
  else if (ch == 2)
    setupBoolValue("Channel Type", "", 1, "Dimmer", "Relay", cpd.channelType[ch], "ch2Type");
  else if (ch == 3)
    setupBoolValue("Channel Type", "", 1, "Dimmer", "Relay", cpd.channelType[ch], "ch3Type");
}

void channelLogic(uint8_t ch) {
  if (ch == 0)
    setupBoolValue("Channel Logic", "", 1, "Active HIGH", "Active LOW", cpd.channelLogic[ch], "ch0Logic");
  else if (ch == 1)
    setupBoolValue("Channel Logic", "", 1, "Active HIGH", "Active LOW", cpd.channelLogic[ch], "ch1Logic");
  else if (ch == 2)
    setupBoolValue("Channel Logic", "", 1, "Active HIGH", "Active LOW", cpd.channelLogic[ch], "ch2Logic");
  else if (ch == 3)
    setupBoolValue("Channel Logic", "", 1, "Active HIGH", "Active LOW", cpd.channelLogic[ch], "ch3Logic");
}

void screenLightFunc(uint8_t ch) {
  setupBoolValue("Screen Light", "", 1, "On", "Off", cpd.screenLight, "screenLight");
}

void waterCheckFunc(uint8_t ch) {
  setupBoolValue("Check Water", "", 1, "Yes", "No", cpd.waterCheck, "waterCheck");
}

void soundFunc(uint8_t ch) {
  setupBoolValue("Sound", "", 1, "On", "Off", cpd.sound, "sound");
}

void screensaverFunc(uint8_t ch) {
  setupBoolValue("Screensaver", "", 1, "On", "Off", cpd.screensaver, "screensaver");
}

void screensaverChooserFunc(uint8_t param) {
  //  setupBoolValue("Screensaver Chooser", "", 1, "Type 1", "Type 2", cpd.screensaverType, "screensType");
  String names[] = {"Channels Info","Sensors Info","Weather Info","Clock Info","Connection Info"};
  setupChooserValue("Screensaver Chooser", "", 1, cpd.screensaverType, names, 5, "screensType");
}

void screensaverAfterFunc(uint8_t param) {
  setupIntegerValue("Show Screensaver", "After (ms)", 2, cpd.screensaverAfter, 0, 43200000, "screensAfter") ;
}



void maintainValue(uint8_t ch) {
  if (ch == 0)
    setupDoubleValue("Maintain Value ", "", 1, cpd.maintainValue[ch], 0.0, 100.0, "maintVal0") ;
  else if (ch == 1)
    setupDoubleValue("Maintain Value ", "", 1, cpd.maintainValue[ch], 0.0, 100.0, "maintVal1") ;
  else if (ch == 2)
    setupDoubleValue("Maintain Value ", "", 1, cpd.maintainValue[ch], 0.0, 100.0, "maintVal2") ;
  else if (ch == 3)
    setupDoubleValue("Maintain Value ", "", 1, cpd.maintainValue[ch], 0.0, 100.0, "maintVal3") ;
}


void pidDirection(uint8_t ch) {
  if (ch == 0)
    setupBoolValue("PID Direction", "", 1, "DECREASING", "INCREASING", cpd.pidDirection[ch], "pidDir0");
  else if (ch == 1)
    setupBoolValue("PID Direction", "", 1, "DECREASING", "INCREASING", cpd.pidDirection[ch], "pidDir1");
  else if (ch == 2)
    setupBoolValue("PID Direction", "", 1, "DECREASING", "INCREASING", cpd.pidDirection[ch], "pidDir2");
  else if (ch == 3)
    setupBoolValue("PID Direction", "", 1, "DECREASING", "INCREASING", cpd.pidDirection[ch], "pidDir3");
}


void pidKp(uint8_t ch) {
  if (ch == 0)
    setupDoubleValue("PID Proportional", "Coefficient", 2, cpd.pidKp[ch], -15.0, 15.0, "pidKp0") ;
  else if (ch == 1)
    setupDoubleValue("PID Proportional", "Coefficient", 2, cpd.pidKp[ch], -15.0, 15.0, "pidKp1") ;
  else if (ch == 2)
    setupDoubleValue("PID Proportional", "Coefficient", 2, cpd.pidKp[ch], -15.0, 15.0, "pidKp2") ;
  else if (ch == 3)
    setupDoubleValue("PID Proportional", "Coefficient", 2, cpd.pidKp[ch], -15.0, 15.0, "pidKp3") ;
}

void pidKi(uint8_t ch) {
  if (ch == 0)
    setupDoubleValue("PID Integral", "Coefficient", 2, cpd.pidKi[ch], -15.0, 15.0, "pidKi0") ;
  else if (ch == 1)
    setupDoubleValue("PID Integral", "Coefficient", 2, cpd.pidKi[ch], -15.0, 15.0, "pidKi1") ;
  else if (ch == 2)
    setupDoubleValue("PID Integral", "Coefficient", 2, cpd.pidKi[ch], -15.0, 15.0, "pidKi2") ;
  else if (ch == 3)
    setupDoubleValue("PID Integral", "Coefficient", 2, cpd.pidKi[ch], -15.0, 15.0, "pidKi3") ;
}

void pidKd(uint8_t ch) {
  if (ch == 0)
    setupDoubleValue("PID Derivative", "Coefficient", 2, cpd.pidKd[ch], -15.0, 15.0, "pidKd0") ;
  else if (ch == 1)
    setupDoubleValue("PID Derivative", "Coefficient", 2, cpd.pidKd[ch], -15.0, 15.0, "pidKd1") ;
  else if (ch == 2)
    setupDoubleValue("PID Derivative", "Coefficient", 2, cpd.pidKd[ch], -15.0, 15.0, "pidKd2") ;
  else if (ch == 3)
    setupDoubleValue("PID Derivative", "Coefficient", 2, cpd.pidKd[ch], -15.0, 15.0, "pidKd3") ;
}

void pidDt(uint8_t ch) {
  if (ch == 0)
    setupIntegerValue("PID dT", "Interval time (ms)", 2, cpd.pidDt[ch], 0, 43200000, "pidDt0") ;
  else if (ch == 1)
    setupIntegerValue("PID dT", "Interval time (ms)", 2, cpd.pidDt[ch], 0, 43200000, "pidDt1") ;
  else if (ch == 2)
    setupIntegerValue("PID dT", "Interval time (ms)", 2, cpd.pidDt[ch], 0, 43200000, "pidDt2") ;
  else if (ch == 3)
    setupIntegerValue("PID dT", "Interval time (ms)", 2, cpd.pidDt[ch], 0, 43200000, "pidDt3") ;
}

void relayDirection(uint8_t ch) {
  if (ch == 0)
    setupBoolValue("Relay Regulator", "Direction", 2, "DECREASING", "INCREASING", cpd.relayDirection[ch], "relDir0");
  else if (ch == 1)
    setupBoolValue("Relay Regulator", "Direction", 2, "DECREASING", "INCREASING", cpd.relayDirection[ch], "relDir1");
  else if (ch == 2)
    setupBoolValue("Relay Regulator", "Direction", 2, "DECREASING", "INCREASING", cpd.relayDirection[ch], "relDir2");
  else if (ch == 3)
    setupBoolValue("Relay Regulator", "Direction", 2, "DECREASING", "INCREASING", cpd.relayDirection[ch], "relDir3");
}

void relayHysteresis(uint8_t ch) {
  if (ch == 0)
    setupDoubleValue("Relay Regulator", "Hysteresis", 2, cpd.relayHysteresis[ch], -100.0, 100.0, "relHyst0") ;
  else if (ch == 1)
    setupDoubleValue("Relay Regulator", "Hysteresis", 2, cpd.relayHysteresis[ch], -100.0, 100.0, "relHyst1") ;
  else if (ch == 2)
    setupDoubleValue("Relay Regulator", "Hysteresis", 2, cpd.relayHysteresis[ch], -100.0, 100.0, "relHyst2") ;
  else if (ch == 3)
    setupDoubleValue("Relay Regulator", "Hysteresis", 2, cpd.relayHysteresis[ch], -100.0, 100.0, "relHyst3") ;
}

void relayK(uint8_t ch) {
  if (ch == 0)
    setupDoubleValue("Relay Regulator", "Coefficient Inertia", 2, cpd.relayK[ch], -15.0, 15.0, "relK0") ;
  else if (ch == 1)
    setupDoubleValue("Relay Regulator", "Coefficient Inertia", 2, cpd.relayK[ch], -15.0, 15.0, "relK1") ;
  else if (ch == 2)
    setupDoubleValue("Relay Regulator", "Coefficient Inertia", 2, cpd.relayK[ch], -15.0, 15.0, "relK2") ;
  else if (ch == 3)
    setupDoubleValue("Relay Regulator", "Coefficient Inertia", 2, cpd.relayK[ch], -15.0, 15.0, "relK3") ;
}

void relayDt(uint8_t ch) {
  if (ch == 0)
    setupIntegerValue("Relay Regulator", "Interval time (ms)", 2, cpd.relayDt[ch], 0, 43200000, "relDt0") ;
  else if (ch == 1)
    setupIntegerValue("Relay Regulator", "Interval time (ms)", 2, cpd.relayDt[ch], 0, 43200000, "relDt1") ;
  else if (ch == 2)
    setupIntegerValue("Relay Regulator", "Interval time (ms)", 2, cpd.relayDt[ch], 0, 43200000, "relDt2") ;
  else if (ch == 3)
    setupIntegerValue("Relay Regulator", "Interval time (ms)", 2, cpd.relayDt[ch], 0, 43200000, "relDt3") ;
}

void wifiSsidFunc(uint8_t param) {

  if (LCDML.FUNC_setup()) {
    lcd.blink();
    lcd.setCursor(0, 0);
    lcd.print("WIFI SSID");
    lcd.setCursor(0, 1);
    lcd.print(cpd.wifiSSID);
    letterCounter = String(cpd.wifiSSID).length();
    lcd.setCursor(letterCounter, 1);
    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {

    if (longPress == true) {// ##########################################                         ЗБЕРІГАННЯ ДАНИХ
      longPress = false;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      memory.putString("wifiSSID", String(cpd.wifiSSID));
      LCDML.FUNC_goBackToMenu();

    }

    else if (triplePress == true) {// ###################################                               СТЕРТИ ВСЕ
      triplePress = false;
      for (uint8_t i = 0; i < 20; i++) {
        cpd.wifiSSID[i] = '\0';
        lcd.setCursor(i, 1);
        lcd.print(" ");
        delay(100);
      }
      letterCounter = 0;
      lcd.setCursor(letterCounter, 1);
      lcd.print(cpd.wifiSSID);
    }

    else if (LCDML.BT_checkEnter()) {// #################################    ВИБРАТИ І ПЕРЕЙТИ ДО НАСТУПНОЇ ЛІТЕРИ
      cpd.wifiSSID[letterCounter] = alphabet[alphabetCounter];
      alphabetCounter = 0;
      letterCounter++;
      letterCounter %= 20;
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiSSID);
    }

    else if (LCDML.BT_checkDown()) {// ##################################            ПОШУК ПОТРІБНОЇ ЛІТЕРИ ВПРАВО
      alphabetCounter++;
      alphabetCounter %= 67;
      lcd.setCursor(letterCounter, 1);
      lcd.print(alphabet[alphabetCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiSSID);
    }

    else if (LCDML.BT_checkUp()) {// ####################################             ПОШУК ПОТРІБНОЇ ЛІТЕРИ ВЛІВО
      if (alphabetCounter == 0)
        alphabetCounter = 66;
      else
        alphabetCounter--;
      lcd.setCursor(letterCounter, 1);
      lcd.print(alphabet[alphabetCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiSSID);
    }

    else if (LCDML.BT_checkRight()) {// #################################                ПЕРЕМІСТИТИ КУРСОР ВПРАВО
      letterCounter++;
      letterCounter %= 20;
      lcd.setCursor(letterCounter, 1);
      lcd.print(cpd.wifiSSID[letterCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiSSID);
    }

    else if (LCDML.BT_checkLeft()) {// ##################################                 ПЕРЕМІСТИТИ КУРСОР ВЛІВО
      if (letterCounter == 0)
        letterCounter = 19;
      else
        letterCounter--;
      lcd.setCursor(letterCounter, 1);
      lcd.print(cpd.wifiSSID[letterCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiSSID);
    }

  }

  if (LCDML.FUNC_close()) {
    lcd.noBlink();
    alphabetCounter = letterCounter = 0;
  }

}

void wifiPassFunc(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    lcd.blink();
    lcd.setCursor(0, 0);
    lcd.print(F("WIFI PASSWORD"));
    lcd.setCursor(0, 1);
    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop()) {

    if (longPress == true) {// ##########################################                         ЗБЕРІГАННЯ ДАНИХ
      longPress = false;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("SAVING DATA ");
      for (byte i = 0; i < 7; i++) {
        lcd.print(".");
        delay(250);
      }
      memory.putString("wifiPASS", String(cpd.wifiPASS));
      LCDML.FUNC_goBackToMenu();

    }

    else if (triplePress == true) {// ###################################                               СТЕРТИ ВСЕ
      triplePress = false;
      for (uint8_t i = 0; i < 20; i++) {
        cpd.wifiPASS[i] = '\0';
        lcd.setCursor(i, 1);
        lcd.print(" ");
        delay(100);
      }
      lcd.setCursor(0, 1);
      lcd.print(cpd.wifiPASS);
    }

    else if (LCDML.BT_checkEnter()) {// #################################    ВИБРАТИ І ПЕРЕЙТИ ДО НАСТУПНОЇ ЛІТЕРИ
      cpd.wifiPASS[letterCounter] = alphabet[alphabetCounter];
      alphabetCounter = 0;
      letterCounter++;
      letterCounter %= 20;
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiPASS);
    }

    else if (LCDML.BT_checkDown()) {// ##################################            ПОШУК ПОТРІБНОЇ ЛІТЕРИ ВПРАВО
      alphabetCounter++;
      alphabetCounter %= 67;
      lcd.setCursor(letterCounter, 1);
      lcd.print(alphabet[alphabetCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiPASS);
    }

    else if (LCDML.BT_checkUp()) {// ####################################             ПОШУК ПОТРІБНОЇ ЛІТЕРИ ВЛІВО
      if (alphabetCounter == 0)
        alphabetCounter = 66;
      else
        alphabetCounter--;
      lcd.setCursor(letterCounter, 1);
      lcd.print(alphabet[alphabetCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiPASS);
    }

    else if (LCDML.BT_checkRight()) {// #################################                ПЕРЕМІСТИТИ КУРСОР ВПРАВО
      letterCounter++;
      letterCounter %= 20;
      lcd.setCursor(letterCounter, 1);
      lcd.print(cpd.wifiPASS[letterCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiPASS);
    }

    else if (LCDML.BT_checkLeft()) {// ##################################                 ПЕРЕМІСТИТИ КУРСОР ВЛІВО
      if (letterCounter == 0)
        letterCounter = 19;
      else
        letterCounter--;
      lcd.setCursor(letterCounter, 1);
      lcd.print(cpd.wifiPASS[letterCounter]);
      lcd.setCursor(letterCounter, 1);
      Serial.println(cpd.wifiPASS);
    }

  }

  if (LCDML.FUNC_close()) {
    lcd.noBlink();
    alphabetCounter = letterCounter = 0;
  }

}




















void mFunc_information(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    LCDML_UNUSED(param);
    lcd.setCursor(0, 0);
    lcd.print(F("To close this"));
    lcd.setCursor(0, 1);
    lcd.print(F("function press"));
    lcd.setCursor(0, 2);
    lcd.print(F("any button or use"));
    lcd.setCursor(0, 3);
    lcd.print(F("back button"));
  }
  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }
  if (LCDML.FUNC_close()) {
  }
}

void mFunc_screensaver(uint8_t param) {
  LCDML_UNUSED(param);
  if (LCDML.FUNC_setup()) {
    lcd.setCursor(0, 0);
    lcd.print(F("screensaver"));
    lcd.setCursor(0, 1);
    lcd.print(F("press any key"));
    lcd.setCursor(0, 2);
    lcd.print(F("to leave it"));
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }
  if (LCDML.FUNC_close()) {
    LCDML.MENU_goRoot();
  }
}

void mFunc_back(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    LCDML_UNUSED(param);
    LCDML.FUNC_goBackToMenu(1);
  }
}

void mFunc_goToRootMenu(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    LCDML_UNUSED(param);
    LCDML.MENU_goRoot();
  }
}

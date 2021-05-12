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
int tempBackup = 0;

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
  lcd.setCursor(13, 1);
  lcd.print("      ");
  lcd.setCursor(13, 1);
  if (cpd.channelType[ch] == TYPE_RELAY) {
    if (cpd.channelLogic[ch] == ACTIVE_LOW) {
      lcd.print((cpd.channelValue[ch] == 0 ? onOff[0] : onOff[1]));
    } else if (cpd.channelLogic[ch] == ACTIVE_HIGH) {
      lcd.print((cpd.channelValue[ch] == 0 ? onOff[1] : onOff[0]));
    }
  } else if (cpd.channelType[ch] == TYPE_DIMMER) {
    lcd.print(String(cpd.channelValue[ch]));
  }
}

void channelOpenValue(uint8_t ch) {
  if (LCDML.FUNC_setup()) {
    tempBackup = cpd.channelControlMode[ch];                              // Зберігаємо попередній режим каналу
    cpd.channelControlMode[ch] = 0;                                       // Переводимо в ручний режим керування

    lcd.setCursor(0, 0);
    lcd.print("CHANNEL "); lcd.print(String(ch));
    lcd.setCursor(0, 1);

    lcd.print("Open Value: ");
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




void pidDirection(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "PID %d Direction", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void pidKp(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "PID %d Kp", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void pidKi(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "PID %d Ki", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void pidKd(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "PID %d Kd", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void pidDt(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "PID %d dT", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void relayDirection(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "Relay %d Direction", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void relayHysteresis(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "Relay %d Hysteresis", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void relayK(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "Relay %d K", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
}

void relayDt(uint8_t param) {
  if (LCDML.FUNC_setup()) {
    char buf[20];
    sprintf (buf, "Relay %d dT", param);
    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("Var"));
    lcd.setCursor(0, 2);
    lcd.print(F("Heheh"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if (LCDML.FUNC_loop()) {
    if (LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close()) {      // ****** STABLE END *********
    // you can here reset some global vars or do nothing
  }
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

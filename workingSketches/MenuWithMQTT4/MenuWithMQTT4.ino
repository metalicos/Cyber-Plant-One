#include "func.h"
#define TYPE_RELAY 0
#define TYPE_DIMMER 1
#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1

LCDML_add         (0  , LCDML_0         , 1  , "Information"      , NULL);
LCDML_add         (1  , LCDML_0_1         , 1  , "Sensors"      , mFunc_information);
LCDML_add         (2  , LCDML_0_1         , 2  , "Channels"      , mFunc_information);

LCDML_add         (3  , LCDML_0         , 2  , "Settings"      , NULL);
LCDML_add         (4  , LCDML_0_2         , 1  , "Channel 1"      , NULL);
LCDML_add         (5  , LCDML_0_2_1         , 1  , "Channel Type"      , NULL);
LCDML_add         (6  , LCDML_0_2_1         , 2  , "Maintain Value"      , NULL);
LCDML_addAdvanced (7  , LCDML_0_2_1         , 3  , NULL,          "Control Mode"       , controlMode,       0,            _LCDML_TYPE_default);
LCDML_addAdvanced (8  , LCDML_0_2_1         , 4  , NULL,          "Channel Open Value" , channelOpenValue,       0,            _LCDML_TYPE_default);
LCDML_add         (9  , LCDML_0_2_1         , 5  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (10  , LCDML_0_2_1_5         , 1  , NULL,          "PID Direction"       , pidDirection,       0,            _LCDML_TYPE_default);
LCDML_addAdvanced (11  , LCDML_0_2_1_5         , 2  , NULL,          "PID Kp"              , pidKp,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (12 , LCDML_0_2_1_5         , 3  , NULL,          "PID Ki"              , pidKi,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (13 , LCDML_0_2_1_5         , 4  , NULL,          "PID Kd"              , pidKd,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (14 , LCDML_0_2_1_5         , 5  , NULL,          "PID dT"              , pidDt,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (15 , LCDML_0_2_1_5         , 6  , NULL,          "Relay Direction"     , relayDirection,     0,            _LCDML_TYPE_default);
LCDML_addAdvanced (16 , LCDML_0_2_1_5         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    0,            _LCDML_TYPE_default);
LCDML_addAdvanced (17 , LCDML_0_2_1_5         , 8  , NULL,          "Relay K"             , relayK,             0,            _LCDML_TYPE_default);
LCDML_addAdvanced (18 , LCDML_0_2_1_5         , 9  , NULL,          "Relay dT"            , relayDt,            0,            _LCDML_TYPE_default);


LCDML_add         (19 , LCDML_0_2         , 2  , "Channel 2"      , NULL);
LCDML_add         (20 , LCDML_0_2_2         , 1  , "Channel Type"      , NULL);
LCDML_add         (21 , LCDML_0_2_2         , 2  , "Maintain Value"      , NULL);
LCDML_addAdvanced (22 , LCDML_0_2_2         , 3  , NULL,          "Control Mode"       , controlMode,       1,            _LCDML_TYPE_default);
LCDML_addAdvanced (23 , LCDML_0_2_2         , 4  , NULL,          "Channel Open Value" , channelOpenValue,       1,            _LCDML_TYPE_default);
LCDML_add         (24 , LCDML_0_2_2         , 5  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (25 , LCDML_0_2_2_5         , 1  , NULL,          "PID Direction"       , pidDirection,       1,            _LCDML_TYPE_default);
LCDML_addAdvanced (26 , LCDML_0_2_2_5         , 2  , NULL,          "PID Kp"              , pidKp,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (27 , LCDML_0_2_2_5         , 3  , NULL,          "PID Ki"              , pidKi,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (28 , LCDML_0_2_2_5         , 4  , NULL,          "PID Kd"              , pidKd,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (29 , LCDML_0_2_2_5         , 5  , NULL,          "PID dT"              , pidDt,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (30 , LCDML_0_2_2_5         , 6  , NULL,          "Relay Direction"     , relayDirection,     1,            _LCDML_TYPE_default);
LCDML_addAdvanced (31 , LCDML_0_2_2_5         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    1,            _LCDML_TYPE_default);
LCDML_addAdvanced (32 , LCDML_0_2_2_5         , 8  , NULL,          "Relay K"             , relayK,             1,            _LCDML_TYPE_default);
LCDML_addAdvanced (33 , LCDML_0_2_2_5         , 9  , NULL,          "Relay dT"            , relayDt,            1,            _LCDML_TYPE_default);

LCDML_add         (34 , LCDML_0_2         , 3  , "Channel 3"      , NULL);
LCDML_add         (35 , LCDML_0_2_3         , 1  , "Channel Type"      , NULL);
LCDML_add         (36 , LCDML_0_2_3         , 2  , "Maintain Value"      , NULL);
LCDML_addAdvanced (37 , LCDML_0_2_3         , 3  , NULL,          "Control Mode"       , controlMode,       2,            _LCDML_TYPE_default);
LCDML_addAdvanced (38 , LCDML_0_2_3         , 4  , NULL,          "Channel Open Value" , channelOpenValue,       2,            _LCDML_TYPE_default);
LCDML_add         (39 , LCDML_0_2_3         , 5  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (40 , LCDML_0_2_3_5         , 1  , NULL,          "PID Direction"       , pidDirection,       2,            _LCDML_TYPE_default);
LCDML_addAdvanced (41 , LCDML_0_2_3_5         , 2  , NULL,          "PID Kp"              , pidKp,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (42 , LCDML_0_2_3_5         , 3  , NULL,          "PID Ki"              , pidKi,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (43 , LCDML_0_2_3_5         , 4  , NULL,          "PID Kd"              , pidKd,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (44 , LCDML_0_2_3_5         , 5  , NULL,          "PID dT"              , pidDt,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (45 , LCDML_0_2_3_5         , 6  , NULL,          "Relay Direction"     , relayDirection,     2,            _LCDML_TYPE_default);
LCDML_addAdvanced (46 , LCDML_0_2_3_5         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    2,            _LCDML_TYPE_default);
LCDML_addAdvanced (47 , LCDML_0_2_3_5         , 8  , NULL,          "Relay K"             , relayK,             2,            _LCDML_TYPE_default);
LCDML_addAdvanced (48 , LCDML_0_2_3_5         , 9  , NULL,          "Relay dT"            , relayDt,            2,            _LCDML_TYPE_default);

LCDML_add         (49 , LCDML_0_2         , 4  , "Channel 4"      , NULL);
LCDML_add         (50 , LCDML_0_2_4         , 1  , "Channel Type"      , NULL);
LCDML_add         (51 , LCDML_0_2_4         , 2  , "Maintain Value"      , NULL);
LCDML_addAdvanced (52 , LCDML_0_2_4         , 3  , NULL,          "Control Mode"       , controlMode,       3,            _LCDML_TYPE_default);
LCDML_addAdvanced (53 , LCDML_0_2_4         , 4  , NULL,          "Channel Open Value" , channelOpenValue,       3,            _LCDML_TYPE_default);
LCDML_add         (54 , LCDML_0_2_4         , 5  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (55 , LCDML_0_2_4_5         , 1  , NULL,          "PID Direction"       , pidDirection,       3,            _LCDML_TYPE_default);
LCDML_addAdvanced (56 , LCDML_0_2_4_5         , 2  , NULL,          "PID Kp"              , pidKp,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (57 , LCDML_0_2_4_5         , 3  , NULL,          "PID Ki"              , pidKi,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (58 , LCDML_0_2_4_5         , 4  , NULL,          "PID Kd"              , pidKd,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (59 , LCDML_0_2_4_5         , 5  , NULL,          "PID dT"              , pidDt,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (60 , LCDML_0_2_4_5         , 6  , NULL,          "Relay Direction"     , relayDirection,     3,            _LCDML_TYPE_default);
LCDML_addAdvanced (61 , LCDML_0_2_4_5         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    3,            _LCDML_TYPE_default);
LCDML_addAdvanced (62 , LCDML_0_2_4_5         , 8  , NULL,          "Relay K"             , relayK,             3,            _LCDML_TYPE_default);
LCDML_addAdvanced (63 , LCDML_0_2_4_5         , 9  , NULL,          "Relay dT"            , relayDt,            3,            _LCDML_TYPE_default);

LCDML_add         (64 , LCDML_0_2         , 5  , "WiFi SSID"      , wifiSsidFunc);
LCDML_add         (65 , LCDML_0_2         , 6  , "WiFi PASS"      , wifiPassFunc);

/*
  // Example for dynamic content
  // 1. set the string to ""
  // 2. use type  _LCDML_TYPE_dynParam   instead of    _LCDML_TYPE_default
  // this function type can not be used in combination with different parameters
  // LCDMenuLib_add (id, prev_layer,      new_num, condition,   lang_char_array,     callback_function,  parameter (0-255), menu function type  )
  LCDML_addAdvanced (21 , LCDML_0         , 6  , NULL,          ""                  , mDyn_para,                0,   _LCDML_TYPE_dynParam);                     // NULL = no menu function

  // 2. Example for dyn content
  // add a function which have a upwards timer with seconds / minutes / hours
  // the timer value is continuously updated
  // the initscreentimer is disabled for this function
  LCDML_addAdvanced (22 , LCDML_0         , 7  , NULL,          ""                  , mDyn_time,                0,   _LCDML_TYPE_dynParam);                     // NULL = no menu function


  // Example for conditions (for example for a screensaver)
  // 1. define a condition as a function of a boolean type -> return false = not displayed, return true = displayed
  // 2. set the function name as callback (remove the braces '()' it gives bad errors)
  // LCDMenuLib_add(id, prev_layer,     new_num, condition,   lang_char_array, callback_function, parameter (0-255), menu function type  )
  LCDML_addAdvanced (23 , LCDML_0         , 8  , COND_hide,  "screensaver"        , mFunc_screensaver,        0,   _LCDML_TYPE_default);       // this menu function can be found on "LCDML_display_menuFunction" tab

*/
#define _LCDML_DISP_cnt    65
LCDML_createMenu(_LCDML_DISP_cnt);

// #######################################################################################################
// ########################################################################################   НАЛАШТУВАННЯ
// #######################################################################################################
void setup() {

  Serial.begin(115200);
  setupMemory();                                           // Прочитати всі збережені дані та налаштування
  setup_wifi();                                            // Налаштувати WiFi
  client.setServer(MQTT_SERVER, 1883);                     // Налаштувати MQTT сервер
  client.setCallback(callback);
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));

  encSetup();
  setupLCD();

  LCDML_setup(_LCDML_DISP_cnt);                            // налаштування бібліотеки LCDMenuLib
  LCDML.MENU_enRollover();
  
  LCDML.SCREEN_enable(mFunc_screensaver, 10000);           // налаштування заставки, що 10с неактивності
  //LCDML.SCREEN_disable();

  //LCDML.OTHER_jumpToFunc(mFunc_p2);                      // переміститися до функції меню

   setupChannelRegulators();                               // Налаштувати регулятори каналів
}



// #######################################################################################################
// #######################################################################################            ЦИКЛ
// #######################################################################################################
void loop() {
  mqttLoop();
  regulatorLoop();
  if (!cpd.turnOff) {
    checkScreenLight();
    encLoop();
    //LCDML.loop_control();
    LCDML.loop_menu();
  }
  //autoSave();
}

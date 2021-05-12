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
LCDML_addAdvanced (5  , LCDML_0_2_1         , 1  , NULL,          "Channel Type"       , channelType,           0,            _LCDML_TYPE_default);
LCDML_addAdvanced (6  , LCDML_0_2_1         , 2  , NULL,          "Channel Logic"       , channelLogic,           0,            _LCDML_TYPE_default);
LCDML_addAdvanced (7  , LCDML_0_2_1         , 3  , NULL,          "Maintain Value"     , maintainValue,         0,            _LCDML_TYPE_default);
LCDML_addAdvanced (8  , LCDML_0_2_1         , 4  , NULL,          "Control Mode"       , controlMode,           0,            _LCDML_TYPE_default);
LCDML_addAdvanced (9  , LCDML_0_2_1         , 5  , NULL,          "Channel Open Value" , channelOpenValue,      0,            _LCDML_TYPE_default);
LCDML_add         (10  , LCDML_0_2_1         , 6  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (11 , LCDML_0_2_1_6         , 1  , NULL,          "PID Direction"       , pidDirection,       0,            _LCDML_TYPE_default);
LCDML_addAdvanced (12 , LCDML_0_2_1_6         , 2  , NULL,          "PID Kp"              , pidKp,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (13 , LCDML_0_2_1_6         , 3  , NULL,          "PID Ki"              , pidKi,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (14 , LCDML_0_2_1_6         , 4  , NULL,          "PID Kd"              , pidKd,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (15 , LCDML_0_2_1_6         , 5  , NULL,          "PID dT"              , pidDt,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (16 , LCDML_0_2_1_6         , 6  , NULL,          "Relay Direction"     , relayDirection,     0,            _LCDML_TYPE_default);
LCDML_addAdvanced (17 , LCDML_0_2_1_6         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    0,            _LCDML_TYPE_default);
LCDML_addAdvanced (18 , LCDML_0_2_1_6         , 8  , NULL,          "Relay K"             , relayK,             0,            _LCDML_TYPE_default);
LCDML_addAdvanced (19 , LCDML_0_2_1_6         , 9  , NULL,          "Relay dT"            , relayDt,            0,            _LCDML_TYPE_default);


LCDML_add         (20 , LCDML_0_2         , 2  , "Channel 2"      , NULL);
LCDML_addAdvanced (21 , LCDML_0_2_2         , 1  , NULL,          "Channel Type"       , channelType,           1,            _LCDML_TYPE_default);
LCDML_addAdvanced (22 , LCDML_0_2_2         , 2  , NULL,          "Channel Logic"       , channelLogic,           1,            _LCDML_TYPE_default);
LCDML_addAdvanced (23 , LCDML_0_2_2         , 3  , NULL,          "Maintain Value"     , maintainValue,         1,            _LCDML_TYPE_default);
LCDML_addAdvanced (24 , LCDML_0_2_2         , 4  , NULL,          "Control Mode"       , controlMode,           1,            _LCDML_TYPE_default);
LCDML_addAdvanced (25 , LCDML_0_2_2         , 5  , NULL,          "Channel Open Value" , channelOpenValue,      1,            _LCDML_TYPE_default);
LCDML_add         (26 , LCDML_0_2_2         , 6  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (27 , LCDML_0_2_2_6         , 1  , NULL,          "PID Direction"       , pidDirection,       1,            _LCDML_TYPE_default);
LCDML_addAdvanced (28 , LCDML_0_2_2_6         , 2  , NULL,          "PID Kp"              , pidKp,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (29 , LCDML_0_2_2_6         , 3  , NULL,          "PID Ki"              , pidKi,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (30 , LCDML_0_2_2_6         , 4  , NULL,          "PID Kd"              , pidKd,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (31 , LCDML_0_2_2_6         , 5  , NULL,          "PID dT"              , pidDt,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (32 , LCDML_0_2_2_6         , 6  , NULL,          "Relay Direction"     , relayDirection,     1,            _LCDML_TYPE_default);
LCDML_addAdvanced (33 , LCDML_0_2_2_6         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    1,            _LCDML_TYPE_default);
LCDML_addAdvanced (34 , LCDML_0_2_2_6         , 8  , NULL,          "Relay K"             , relayK,             1,            _LCDML_TYPE_default);
LCDML_addAdvanced (35 , LCDML_0_2_2_6         , 9  , NULL,          "Relay dT"            , relayDt,            1,            _LCDML_TYPE_default);

LCDML_add         (36 , LCDML_0_2         , 3  , "Channel 3"      , NULL);
LCDML_addAdvanced (37 , LCDML_0_2_3         , 1  , NULL,          "Channel Type"       , channelType,           2,            _LCDML_TYPE_default);
LCDML_addAdvanced (38 , LCDML_0_2_3         , 2  , NULL,          "Channel Logic"       , channelLogic,           2,            _LCDML_TYPE_default);
LCDML_addAdvanced (39 , LCDML_0_2_3         , 3  , NULL,          "Maintain Value"     , maintainValue,         2,            _LCDML_TYPE_default);
LCDML_addAdvanced (40 , LCDML_0_2_3         , 4  , NULL,          "Control Mode"       , controlMode,           2,            _LCDML_TYPE_default);
LCDML_addAdvanced (41 , LCDML_0_2_3         , 5  , NULL,          "Channel Open Value" , channelOpenValue,      2,            _LCDML_TYPE_default);
LCDML_add         (42 , LCDML_0_2_3         , 6  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (43 , LCDML_0_2_3_6         , 1  , NULL,          "PID Direction"       , pidDirection,       2,            _LCDML_TYPE_default);
LCDML_addAdvanced (44 , LCDML_0_2_3_6         , 2  , NULL,          "PID Kp"              , pidKp,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (45 , LCDML_0_2_3_6         , 3  , NULL,          "PID Ki"              , pidKi,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (46 , LCDML_0_2_3_6         , 4  , NULL,          "PID Kd"              , pidKd,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (47 , LCDML_0_2_3_6         , 5  , NULL,          "PID dT"              , pidDt,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (48 , LCDML_0_2_3_6         , 6  , NULL,          "Relay Direction"     , relayDirection,     2,            _LCDML_TYPE_default);
LCDML_addAdvanced (49 , LCDML_0_2_3_6         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    2,            _LCDML_TYPE_default);
LCDML_addAdvanced (50 , LCDML_0_2_3_6         , 8  , NULL,          "Relay K"             , relayK,             2,            _LCDML_TYPE_default);
LCDML_addAdvanced (51 , LCDML_0_2_3_6         , 9  , NULL,          "Relay dT"            , relayDt,            2,            _LCDML_TYPE_default);

LCDML_add         (52 , LCDML_0_2         , 4  , "Channel 4"      , NULL);
LCDML_addAdvanced (53 , LCDML_0_2_4         , 1  , NULL,          "Channel Type"       , channelType,           3,            _LCDML_TYPE_default);
LCDML_addAdvanced (54 , LCDML_0_2_4         , 2  , NULL,          "Channel Logic"       , channelLogic,           3,            _LCDML_TYPE_default);
LCDML_addAdvanced (55 , LCDML_0_2_4         , 3  , NULL,          "Maintain Value"     , maintainValue,         3,            _LCDML_TYPE_default);
LCDML_addAdvanced (56 , LCDML_0_2_4         , 4  , NULL,          "Control Mode"       , controlMode,           3,            _LCDML_TYPE_default);
LCDML_addAdvanced (57 , LCDML_0_2_4         , 5  , NULL,          "Channel Open Value" , channelOpenValue,      3,            _LCDML_TYPE_default);
LCDML_add         (58 , LCDML_0_2_4         , 6  , "Advanced Settings"      , NULL);
LCDML_addAdvanced (59 , LCDML_0_2_4_6         , 1  , NULL,          "PID Direction"       , pidDirection,       3,            _LCDML_TYPE_default);
LCDML_addAdvanced (60 , LCDML_0_2_4_6         , 2  , NULL,          "PID Kp"              , pidKp,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (61 , LCDML_0_2_4_6         , 3  , NULL,          "PID Ki"              , pidKi,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (62 , LCDML_0_2_4_6         , 4  , NULL,          "PID Kd"              , pidKd,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (63 , LCDML_0_2_4_6         , 5  , NULL,          "PID dT"              , pidDt,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (64 , LCDML_0_2_4_6         , 6  , NULL,          "Relay Direction"     , relayDirection,     3,            _LCDML_TYPE_default);
LCDML_addAdvanced (65 , LCDML_0_2_4_6         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    3,            _LCDML_TYPE_default);
LCDML_addAdvanced (66 , LCDML_0_2_4_6         , 8  , NULL,          "Relay K"             , relayK,             3,            _LCDML_TYPE_default);
LCDML_addAdvanced (67 , LCDML_0_2_4_6         , 9  , NULL,          "Relay dT"            , relayDt,            3,            _LCDML_TYPE_default);

LCDML_add         (68 , LCDML_0_2         , 5  , "Screen Light"                           , screenLightFunc);
LCDML_add         (69 , LCDML_0_2         , 6  , "Sound"                                  , soundFunc);
LCDML_add         (70 , LCDML_0_2         , 7  , "Check Water"                            , waterCheckFunc);
LCDML_add         (71 , LCDML_0_2         , 8  , "Screensaver"                            , screensaverFunc);
LCDML_add         (72 , LCDML_0_2         , 9  , "Screensaver Chooser"                    , screensaverChooserFunc);
LCDML_add         (73 , LCDML_0_2         , 10  , "Screensaver After"                     , screensaverAfterFunc);

LCDML_add         (74 , LCDML_0_2         , 11  , "WiFi SSID"      , wifiSsidFunc);
LCDML_add         (75 , LCDML_0_2         , 12  , "WiFi PASS"      , wifiPassFunc);
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
#define _LCDML_DISP_cnt    75
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

#define _LCDML_cfg_use_ram

#include <LC_I2C.h>
#include <LCDMenuLib2.h>
#include <ESP32Encoder.h>
#include "Button2.h";
#include "func.h"

// *********************************************************************
// LCDML display settings
// *********************************************************************
// settings for LCD
#define _LCDML_DISP_cols  20
#define _LCDML_DISP_rows  4

#define _LCDML_DISP_cfg_cursor                     0x7E   // cursor Symbol
#define _LCDML_DISP_cfg_scrollbar                  1      // enable a scrollbar

LC_I2C lcd(0x27, 20, 4);
ESP32Encoder encoder;
Button2 button = Button2(5);

const uint8_t scroll_bar[5][8] = {
  {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001}, // scrollbar top
  {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, // scroll state 1
  {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, // scroll state 2
  {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, // scroll state 3
  {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  // scrollbar bottom
};

void lcdml_menu_display();
void lcdml_menu_clear();
void lcdml_menu_control();

// *********************************************************************
// Global variables
// *********************************************************************


// *********************************************************************
// Objects
// *********************************************************************
LCDMenuLib2_menu LCDML_0 (255, 0, 0, NULL, NULL); // root menu element (do not change)
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);

// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
// LCDML_0        => layer 0
// LCDML_0_X      => layer 1
// LCDML_0_X_X    => layer 2
// LCDML_0_X_X_X  => layer 3
// LCDML_0_...      => layer ...


LCDML_add         (0  , LCDML_0         , 1  , "Information"      , NULL);      
LCDML_add         (1  , LCDML_0_1         , 1  , "Sensors"      , mFunc_information);
LCDML_add         (2  , LCDML_0_1         , 2  , "Channels"      , mFunc_information);

LCDML_add         (3  , LCDML_0         , 2  , "Settings"      , NULL);  
LCDML_add         (4  , LCDML_0_2         , 1  , "Channel 1"      , NULL);
LCDML_add         (5  , LCDML_0_2_1         , 1  , "Channel Type"      , NULL);
LCDML_add         (6  , LCDML_0_2_1         , 2  , "Maintain Value"      , NULL);
LCDML_add         (7  , LCDML_0_2_1         , 3  , "Advanced"      , NULL);
LCDML_addAdvanced (8  , LCDML_0_2_1_3         , 1  , NULL,          "PID Direction"       , pidDirection,       0,            _LCDML_TYPE_default); 
LCDML_addAdvanced (9  , LCDML_0_2_1_3         , 2  , NULL,          "PID Kp"              , pidKp,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (10 , LCDML_0_2_1_3         , 3  , NULL,          "PID Ki"              , pidKi,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (11 , LCDML_0_2_1_3         , 4  , NULL,          "PID Kd"              , pidKd,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (12 , LCDML_0_2_1_3         , 5  , NULL,          "PID dT"              , pidDt,              0,            _LCDML_TYPE_default);
LCDML_addAdvanced (13 , LCDML_0_2_1_3         , 6  , NULL,          "Relay Direction"     , relayDirection,     0,            _LCDML_TYPE_default); 
LCDML_addAdvanced (14 , LCDML_0_2_1_3         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    0,            _LCDML_TYPE_default);
LCDML_addAdvanced (15 , LCDML_0_2_1_3         , 8  , NULL,          "Relay K"             , relayK,             0,            _LCDML_TYPE_default);
LCDML_addAdvanced (16 , LCDML_0_2_1_3         , 9  , NULL,          "Relay dT"            , relayDt,            0,            _LCDML_TYPE_default);


LCDML_add         (17 , LCDML_0_2         , 2  , "Channel 2"      , NULL); 
LCDML_add         (18 , LCDML_0_2_2         , 1  , "Channel Type"      , NULL);
LCDML_add         (19 , LCDML_0_2_2         , 2  , "Maintain Value"      , NULL);
LCDML_add         (20 , LCDML_0_2_2         , 3  , "Advanced"      , NULL);
LCDML_addAdvanced (21 , LCDML_0_2_2_3         , 1  , NULL,          "PID Direction"       , pidDirection,       1,            _LCDML_TYPE_default); 
LCDML_addAdvanced (22 , LCDML_0_2_2_3         , 2  , NULL,          "PID Kp"              , pidKp,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (23 , LCDML_0_2_2_3         , 3  , NULL,          "PID Ki"              , pidKi,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (24 , LCDML_0_2_2_3         , 4  , NULL,          "PID Kd"              , pidKd,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (25 , LCDML_0_2_2_3         , 5  , NULL,          "PID dT"              , pidDt,              1,            _LCDML_TYPE_default);
LCDML_addAdvanced (26 , LCDML_0_2_2_3         , 6  , NULL,          "Relay Direction"     , relayDirection,     1,            _LCDML_TYPE_default); 
LCDML_addAdvanced (27 , LCDML_0_2_2_3         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    1,            _LCDML_TYPE_default);
LCDML_addAdvanced (28 , LCDML_0_2_2_3         , 8  , NULL,          "Relay K"             , relayK,             1,            _LCDML_TYPE_default);
LCDML_addAdvanced (29 , LCDML_0_2_2_3         , 9  , NULL,          "Relay dT"            , relayDt,            1,            _LCDML_TYPE_default);

LCDML_add         (30 , LCDML_0_2         , 3  , "Channel 3"      , NULL); 
LCDML_add         (31 , LCDML_0_2_3         , 1  , "Channel Type"      , NULL);
LCDML_add         (32 , LCDML_0_2_3         , 2  , "Maintain Value"      , NULL);
LCDML_add         (33 , LCDML_0_2_3         , 3  , "Advanced"      , NULL);
LCDML_addAdvanced (34 , LCDML_0_2_3_3         , 1  , NULL,          "PID Direction"       , pidDirection,       2,            _LCDML_TYPE_default); 
LCDML_addAdvanced (35 , LCDML_0_2_3_3         , 2  , NULL,          "PID Kp"              , pidKp,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (36 , LCDML_0_2_3_3         , 3  , NULL,          "PID Ki"              , pidKi,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (37 , LCDML_0_2_3_3         , 4  , NULL,          "PID Kd"              , pidKd,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (38 , LCDML_0_2_3_3         , 5  , NULL,          "PID dT"              , pidDt,              2,            _LCDML_TYPE_default);
LCDML_addAdvanced (39 , LCDML_0_2_3_3         , 6  , NULL,          "Relay Direction"     , relayDirection,     2,            _LCDML_TYPE_default); 
LCDML_addAdvanced (40 , LCDML_0_2_3_3         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    2,            _LCDML_TYPE_default);
LCDML_addAdvanced (41 , LCDML_0_2_3_3         , 8  , NULL,          "Relay K"             , relayK,             2,            _LCDML_TYPE_default);
LCDML_addAdvanced (42 , LCDML_0_2_3_3         , 9  , NULL,          "Relay dT"            , relayDt,            2,            _LCDML_TYPE_default);

LCDML_add         (43 , LCDML_0_2         , 4  , "Channel 4"      , NULL); 
LCDML_add         (44 , LCDML_0_2_4         , 1  , "Channel Type"      , NULL);
LCDML_add         (45 , LCDML_0_2_4         , 2  , "Maintain Value"      , NULL);
LCDML_add         (46 , LCDML_0_2_4         , 3  , "Advanced"      , NULL);
LCDML_addAdvanced (47 , LCDML_0_2_4_3         , 1  , NULL,          "PID Direction"       , pidDirection,       3,            _LCDML_TYPE_default); 
LCDML_addAdvanced (48 , LCDML_0_2_4_3         , 2  , NULL,          "PID Kp"              , pidKp,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (49 , LCDML_0_2_4_3         , 3  , NULL,          "PID Ki"              , pidKi,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (50 , LCDML_0_2_4_3         , 4  , NULL,          "PID Kd"              , pidKd,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (51 , LCDML_0_2_4_3         , 5  , NULL,          "PID dT"              , pidDt,              3,            _LCDML_TYPE_default);
LCDML_addAdvanced (52 , LCDML_0_2_4_3         , 6  , NULL,          "Relay Direction"     , relayDirection,     3,            _LCDML_TYPE_default); 
LCDML_addAdvanced (53 , LCDML_0_2_4_3         , 7  , NULL,          "Relay Hysteresis"    , relayHysteresis,    3,            _LCDML_TYPE_default);
LCDML_addAdvanced (54 , LCDML_0_2_4_3         , 8  , NULL,          "Relay K"             , relayK,             3,            _LCDML_TYPE_default);
LCDML_addAdvanced (55 , LCDML_0_2_4_3         , 9  , NULL,          "Relay dT"            , relayDt,            3,            _LCDML_TYPE_default);
  
LCDML_add         (56 , LCDML_0_2         , 5  , "WiFi SSID"      , wifiSsidFunc); 
LCDML_add         (57 , LCDML_0_2         , 6  , "WiFi PASS"      , wifiPassFunc); 

/*
// Example for dynamic content
// 1. set the string to ""
// 2. use type  _LCDML_TYPE_dynParam   instead of    _LCDML_TYPE_default
// this function type can not be used in combination with different parameters
// LCDMenuLib_add(id, prev_layer,     new_num, condition,   lang_char_array, callback_function, parameter (0-255), menu function type  )
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
#define _LCDML_DISP_cnt    57

// create menu
LCDML_createMenu(_LCDML_DISP_cnt);

// *********************************************************************
// SETUP
// *********************************************************************
void setup()
{
  // serial init; only be needed if serial control is used
  Serial.begin(115200);                // start serial
  Serial.println(F(_LCDML_VERSION)); // only for examples

  encSetup();
  lcd.begin();
  lcd.clear();
  lcd.backlight();
  
  lcd.createChar(0, (uint8_t*)scroll_bar[0]);
  lcd.createChar(1, (uint8_t*)scroll_bar[1]);
  lcd.createChar(2, (uint8_t*)scroll_bar[2]);
  lcd.createChar(3, (uint8_t*)scroll_bar[3]);
  lcd.createChar(4, (uint8_t*)scroll_bar[4]);

  // LCDMenuLib Setup
  LCDML_setup(_LCDML_DISP_cnt);

  // Some settings which can be used

  // Enable Menu Rollover
  LCDML.MENU_enRollover();

  // Enable Screensaver (screensaver menu function, time to activate in ms)
  LCDML.SCREEN_enable(mFunc_screensaver, 10000); // set to 10 seconds
  //LCDML.SCREEN_disable();

  // Some needful methods

  // You can jump to a menu function from anywhere with
  //LCDML.OTHER_jumpToFunc(mFunc_p2); // the parameter is the function name
}


// special gobal variables for this example
unsigned long g_timer_1000ms = 0;
uint8_t dyn_hour = 0;
uint8_t dyn_min  = 0;
uint8_t dyn_sec  = 0;
boolean dyn_menu_is_displayed = false;

// *********************************************************************
// LOOP
// *********************************************************************
void loop()
{
  // split loop() into loop_control() and loop_menu()
  encLoop();
  //LCDML.loop_control();
  
  // add a counter (1000ms)
  if (LCDML.TIMER_ms(g_timer_1000ms, 1000))
  {
    // only update the menu when a dynamic content function is called
    // This variable is set in the LCDML_display_menu Tab on line 59/60
    if (LCDML.MENU_checkDynContent() == true)
    {
      LCDML.DISP_update();
    }

    // callculate a new value for the next update
    dyn_sec++;
    if (dyn_sec == 60) {
      dyn_sec = 0;
      dyn_min++;
      if (dyn_min == 60) {
        dyn_min = 0;
        dyn_hour++;
      }
    }
  }

  // call the "normaly" menu content
  LCDML.loop_menu();
}


void encSetup() {
  ESP32Encoder::useInternalWeakPullResistors = UP;
  encoder.attachHalfQuad(19, 18);
  encoder.setCount(0);

  // button.setLongClickTime(1000);
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
  if (encCounter > 0 && buttonIsPressed){
    encoder.setCount(0);
    LCDML.BT_right();
  } else if (encCounter < 0 && buttonIsPressed) {
    encoder.setCount(0);
    LCDML.BT_left();
  } else if (encCounter > 0) {
    encoder.setCount(0);
    LCDML.BT_down();
    //LCDML.BT_right();
  } else if (encCounter < 0) {
    encoder.setCount(0);
    LCDML.BT_up();
    //LCDML.BT_left();
  }
}

void singleClick(Button2& btn) {
  LCDML.BT_enter();

}


void pressed(Button2& btn) {
  buttonIsPressed = true;
  Serial.println("btn pressed");
}

void released(Button2& btn) {
  buttonIsPressed = false;
  Serial.println("btn released");
}

void longSingleClick(Button2& btn) {
  Serial.println("long click");
}

void doubleClick(Button2& btn) {
  LCDML.BT_quit();
}
void tripleClick(Button2& btn) {
  Serial.println("triple click\n");
}

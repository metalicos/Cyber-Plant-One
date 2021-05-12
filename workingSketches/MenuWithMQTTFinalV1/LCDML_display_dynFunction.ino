

/* ===================================================================== *
 *                                                                       *
 * Dynamic content                                                       *
 *                                                                       *
 * ===================================================================== *
 */

/*
void mDyn_para(uint8_t line){
  
  if (line == LCDML.MENU_getCursorPos()){                     // check if this function is active (cursor stands on this line)
    
    if(LCDML.BT_checkAny()){                                  // make only an action when the cursor stands on this menu item
      
      if(LCDML.BT_checkEnter()){
        
        if(LCDML.MENU_getScrollDisableStatus() == 0){         // returns the scroll disable status (0 = menu scrolling enabled, 1 = menu scrolling disabled)
          LCDML.MENU_disScroll();
        }else{
          LCDML.MENU_enScroll();                              // enable the normal menu scroll function
        }

        // do something
        // ...
      }

      if(LCDML.BT_checkUp()){                                 // This check have only an effect when MENU_disScroll is set
        g_dynParam++;
      }

      if(LCDML.BT_checkDown()){                               // This check have only an effect when MENU_disScroll is set
        g_dynParam--;
      }

      if(LCDML.BT_checkLeft())
      {
        g_dynParam++;
      }
      
      if(LCDML.BT_checkRight())
      {
        g_dynParam--;
      }
    }
  }

  char buf[20];
  sprintf (buf, "dynValue: %d", g_dynParam);

  // use the line from function parameters
  lcd.setCursor(1, line);
  lcd.print(buf);

}

uint8_t g_dynParam = 100; // when this value comes from an EEPROM, load it in setup
                          // at the moment here is no setup function (To-Do)
void mDyn_para(uint8_t line){
  
  if (line == LCDML.MENU_getCursorPos()){                     // check if this function is active (cursor stands on this line)
    
    if(LCDML.BT_checkAny()){                                  // make only an action when the cursor stands on this menu item
      
      if(LCDML.BT_checkEnter()){
        
        if(LCDML.MENU_getScrollDisableStatus() == 0){         // returns the scroll disable status (0 = menu scrolling enabled, 1 = menu scrolling disabled)
          LCDML.MENU_disScroll();
        }else{
          LCDML.MENU_enScroll();                              // enable the normal menu scroll function
        }

        // do something
        // ...
      }

      if(LCDML.BT_checkUp()){                                 // This check have only an effect when MENU_disScroll is set
        g_dynParam++;
      }

      if(LCDML.BT_checkDown()){                               // This check have only an effect when MENU_disScroll is set
        g_dynParam--;
      }

      if(LCDML.BT_checkLeft())
      {
        g_dynParam++;
      }
      
      if(LCDML.BT_checkRight())
      {
        g_dynParam--;
      }
    }
  }

  char buf[20];
  sprintf (buf, "dynValue: %d", g_dynParam);

  // use the line from function parameters
  lcd.setCursor(1, line);
  lcd.print(buf);

}




// *********************************************************************
void mDyn_time(uint8_t line)
// *********************************************************************
{
  char buf[20];
  // http://www.c-howto.de/tutorial/benutzerinteraktion/bildschirmausgaben/
  sprintf (buf, "%02d:%02d:%02d", dyn_hour, dyn_min, dyn_sec);

  // use the line from function parameters
  lcd.setCursor(1, line);
  lcd.print(buf);

  // reset initscreen timer when this function is displayed
  LCDML.SCREEN_resetTimer();
  
  // check if this function is active (cursor stands on this line)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...


  
  }
}

*/

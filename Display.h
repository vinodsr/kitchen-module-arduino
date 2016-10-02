/*
  Display.h - Library for handling the LCD sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/
#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class Display
{
  public:
    Display(bool);
    void turnOn();
    void turnOff();
    void print(String message);
    void print(String title,String message);
  private:
    LiquidCrystal lcd  = LiquidCrystal(6, 9, 5, 4, 3, 2);
    bool logging;
    
};

#endif


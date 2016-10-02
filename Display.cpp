/*
  Display.cpp - Library for handling the Display sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/

#include "Arduino.h"
#include "Display.h"
#include "Logger.h"


Display::Display(bool log)
{
  logging = log;
  lcd.begin(16, 2);
  pinMode(A5, OUTPUT);
}

void Display :: print(String msg) {
  print("Kitchen Utils v2",msg);
}
void Display :: print(String title,String msg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(title);
  lcd.setCursor(0, 1);
  lcd.print(msg);
  if(logging) {
      Logger::debug(msg);
    }
}

void Display :: turnOn() {
  digitalWrite(A5, HIGH);
}

void Display :: turnOff() {
  digitalWrite(A5, LOW);
}


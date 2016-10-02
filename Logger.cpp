/*
  Logger.cpp - Library for handling the Logger sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/

#include "Arduino.h"
#include "Logger.h"
int Logger::_level;


Logger::Logger()
{
  _level = 0;
}



void Logger :: init(){
  Serial.begin(9600);
}

void Logger :: debug(String msg) {
  if(Logger :: _level <= 0) {
   Serial.println("DEBUG:" + msg); 
  }
}

void Logger :: info(String msg) {
  if(Logger :: _level <= 1) {
    Serial.println("INFO:" + msg);
  }
}

void Logger :: error(String msg) {
  if(Logger :: _level <= 2) {
    Serial.println("ERROR:" + msg);
  }
}

void Logger::setLevel(int level) {
  _level = level;
}



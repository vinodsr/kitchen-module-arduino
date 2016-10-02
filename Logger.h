/*
  Logger.h - Logging Functions 
  Created by Vinod Surendran R, 17 Mar 2016
*/

#ifndef Logger_h
#define Logger_h

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_ERROR 2

#include "Arduino.h"

class Logger
{
  public:
    Logger();
    static void init();
    static void debug(String msg); 
    static void info(String msg);    
    static void error(String msg); 
    static void setLevel(int level);
  private:
    static int _level;
};

#endif


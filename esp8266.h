/*
  ESP8266.h - Library for handling the motion detector sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/
#ifndef ESP8266_h
#define ESP8266_h

#include "Arduino.h"

class ESP8266
{
  public:
    ESP8266(int rxPin,int txPin);
    String getVersion();
  private:
    int _rxPin,_txPin;
};

#endif
  

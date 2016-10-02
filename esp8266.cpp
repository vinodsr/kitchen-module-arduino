/*
  ESP8266.cpp - Library for handling the motion detector sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/

#include "Arduino.h"
#include "ESP8266.h"

#ifndef HAVE_HWSERIAL
  #include "SoftwareSerial.h"
 
#endif

ESP8266::ESP8266(int rxPin, int txPin)
{
   SoftwareSerial wifiSerial(rxPin, txPin); // RX, TX
  _rxPin = rxPin;
  _txPin = txPin;
}

String  ESP8266::getVersion()
{
  _currentState = digitalRead(_pin);  // read input value
  if (_currentState == _triggerState) {
    return true;
    if (_motionDetected == false ) {
      _motionDetected = true;
      return true ;
    } else {
      return false;
    }
  } else {
    _motionDetected = false;
    return false;
  }
}



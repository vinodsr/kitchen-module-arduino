/*
  MotionDetector.cpp - Library for handling the motion detector sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/

#include "Arduino.h"
#include "MotionDetector.h"

MotionDetector::MotionDetector(int pin, int triggerState)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _triggerState = triggerState;
}

boolean  MotionDetector::isDetected()
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



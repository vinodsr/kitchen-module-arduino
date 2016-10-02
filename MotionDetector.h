/*
  MotionDetector.h - Library for handling the motion detector sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/
#ifndef MotionDetector_h
#define MotionDetector_h

#include "Arduino.h"

class MotionDetector
{
  public:
    MotionDetector(int pin, int triggerState);
    boolean isDetected();
  private:
    int _pin;
    int _triggerState;
    int _currentState;
    boolean _motionDetected = false;
};

#endif


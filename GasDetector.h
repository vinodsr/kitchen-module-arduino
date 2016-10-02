/*
  GasDetector.h - Library for handling the Gas detector sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/
#ifndef GasDetector_h
#define GasDetector_h

#include "Arduino.h"

class GasDetector
{
  public:
    GasDetector(int pin);
    float getGasLevel();
  private:
    int _pin;
    float sensor_volt;
    float R0 = 1.67;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    int sensorValue;
};

#endif


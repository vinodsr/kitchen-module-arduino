/*
  GasDetector.cpp - Library for handling the Gas detector sensor
  Created by Vinod Surendran R, 17 Mar 2016
*/

#include "Arduino.h"
#include "GasDetector.h"

GasDetector::GasDetector(int pin)
{
  _pin = pin;
}

float  GasDetector::getGasLevel()
{
  sensorValue = analogRead(_pin);
  sensor_volt = (float)sensorValue / 1024 * 5.0;
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
  ratio = RS_gas / R0; // ratio = RS/R0
  return sensorValue;
}



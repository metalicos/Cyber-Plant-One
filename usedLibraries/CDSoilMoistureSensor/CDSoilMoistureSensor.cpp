#include "CDSoilMoistureSensor.h"
#include <Arduino.h>

CDSoilMoistureSensor::CDSoilMoistureSensor(int pin1,int pin2,int pin3,int pin4, uint16_t filterNum){
	_pin1=pin1;
	_pin2=pin2;
	_pin3=pin3;
	_pin4=pin4;
	_filterNum=filterNum;
}

double CDSoilMoistureSensor::calculatePercentage(uint64_t averageValue) {
  int dry = 3343;
  int wet = 1283;
  if (averageValue > dry) {
    return 0.0;
  } else if (averageValue < wet) {
    return 100.0;
  } else {
    double res = ((averageValue - 2693.7) / -18.44);
    if (res <= 0.0)
      return -999.9;
    else if (res >= 100.0)
      return 100.0;
    else
      return res;
  }
}

void CDSoilMoistureSensor::getMoistureInPercentage(double *moisture){
  unsigned long long avr1 = 0;
  unsigned long long avr2 = 0;
  unsigned long long avr3 = 0;
  unsigned long long avr4 = 0;
  
  for (uint16_t i = 0; i < _filterNum; i++) {
    avr1 += analogRead(_pin1);
    avr2 += analogRead(_pin2);
    avr3 += analogRead(_pin3);
    avr4 += analogRead(_pin4);
  }
  
  avr1 /= _filterNum;
  avr2 /= _filterNum;
  avr3 /= _filterNum;
  avr4 /= _filterNum;

  moisture[0] = calculatePercentage(avr1);
  moisture[1] = calculatePercentage(avr2);
  moisture[2] = calculatePercentage(avr3);
  moisture[3] = calculatePercentage(avr4);
}
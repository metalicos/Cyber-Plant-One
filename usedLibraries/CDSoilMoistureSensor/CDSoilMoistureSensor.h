#ifndef CDSoilMoistureSensor_h
#define CDSoilMoistureSensor_h
#include <Arduino.h>

class CDSoilMoistureSensor{
public:
	CDSoilMoistureSensor(int pin1,int pin2,int pin3,int pin4, uint16_t filterNum);
	void getMoistureInPercentage(double *moisture);	
private:
	int _pin1, _pin2, _pin3, _pin4;
	uint16_t _filterNum = 100;
	double calculatePercentage(uint64_t averageValue);
};
#endif
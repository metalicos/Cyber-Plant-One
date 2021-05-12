#include "CDRelayRegulator.h"
#include <Arduino.h>

CDRelayRegulator::CDRelayRegulator(){}

CDRelayRegulator::CDRelayRegulator(bool direction) {
	_direction = direction;
	_output = !_direction;   // виключаємо реле
}

void CDRelayRegulator::setDirection(bool direction) {
	_direction = direction;
	_output = !_direction;	// виключаємо реле
}

void CDRelayRegulator::setInput(double sensorValue){
	this->_input=sensorValue;
}

void CDRelayRegulator::setMaintainValue(double maintainValue){
	this->_maintainValue=maintainValue;
}

void CDRelayRegulator::setHysteresis(double hysteresis){
	this->_hysteresis=hysteresis;
}

void CDRelayRegulator::setK(double k){
	this->_k=k;
}
	
void CDRelayRegulator::setDt(uint32_t dT){
	this->_dT=dT;
}
	
bool CDRelayRegulator::getDirection(){
	return this->_direction;
}

double CDRelayRegulator::getInput(){
	return this->_input;
}

double CDRelayRegulator::getMaintainValue(){
	return this->_maintainValue;
}

double CDRelayRegulator::getHysteresis(){
	return this->_hysteresis;
}

double CDRelayRegulator::getK(){
	return this->_k;
}

uint32_t CDRelayRegulator::getDt(){
	return this->_dT;
}


int signum(double val) { 
	return ((val > 0) ? 1 : ((val < 0) ? -1 : 0)); 
}

bool CDRelayRegulator::compute(double _dT) {
	double signal;
	if (_dT > 0) {
		double rate = (_input - _prevInput) / _dT;
		_prevInput = _input;
		signal = _input + rate * _k;
	} else {
		signal = _input;
	}

	int8_t F = (signum(signal - _maintainValue - _hysteresis / 2) + signum(signal - _maintainValue + _hysteresis / 2)) / 2;

	if (F == 1) _output = !_direction;
	else if (F == -1) _output = _direction;
	return _output;
}

bool CDRelayRegulator::getResult() {
	CDRelayRegulator::compute((millis() - _prevTime) / 1000.0f);
	_prevTime = millis();
	return _output;
}

bool CDRelayRegulator::getResultTimer() {
	if (millis() - _prevTime > _dT) {
		_prevTime = millis();
		this->compute((double)_dT / 1000);
	}
	return _output;
}
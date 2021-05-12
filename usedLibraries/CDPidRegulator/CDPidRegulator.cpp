#include "CDPidRegulator.h"

	CDPidRegulator::CDPidRegulator(){}
	CDPidRegulator::CDPidRegulator(double newKp, double newKi, double newKd, int32_t newDt){
		setDt(newDt);
		this->_Kp = newKp;
		this->_Ki = newKi;
		this->_Kd = newKd;
	}	
	
	void CDPidRegulator::setMaintainValue(double maintainValue){
		this->_maintainValue = maintainValue;
	}
	void CDPidRegulator::setInput(double sensorValue){
		this->_input = sensorValue;
	}
	void CDPidRegulator::setKp(double Kp){
		this->_Kp = Kp;
	}
	void CDPidRegulator::setKi(double Ki){
		this->_Ki = Ki;
	}
	void CDPidRegulator::setKd(double Kd){
		this->_Kd = Kd;
	}
	void CDPidRegulator::setDt(int32_t newDt) {
		this->_dtSeconds = newDt / 1000.0;
		this->_dt = newDt;
	}
	void CDPidRegulator::setMode(bool mode) {
		this->_mode = mode;
	}
	void CDPidRegulator::setDirection(bool direction) {
		this->_direction = direction;
		this->_pwmOutputValue = 0; //на старті подати ширину імпульсу рівну 0 (закрити мосфет/диммер)
	}
	void CDPidRegulator::setPwmLimits(uint16_t pwmMinValue, uint16_t pwmMaxValue){
		this->_minPwmVal = pwmMinValue;
		this->_maxPwmVal = pwmMaxValue;
	}


	double CDPidRegulator::getMaintainValue(){
		return this->_maintainValue;
	}
	double CDPidRegulator::getKp(){
		return this->_Kp;
	}
	double CDPidRegulator::getKi(){
		return this->_Ki;
	}
	double CDPidRegulator::getKd(){
		return this->_Kd;
	}
	int32_t CDPidRegulator::getDt(){
		return this->_dt;
	}
	bool CDPidRegulator::getMode(){
		return this->_mode;
	}
	bool CDPidRegulator::getDirection(){
		return this->_direction;
	}
	uint16_t CDPidRegulator::getPwmMinLimit(){
		return this->_minPwmVal;
	}
	uint16_t CDPidRegulator::getPwmMaxLimit(){
		return this->_maxPwmVal;
	}
	
	
	double CDPidRegulator::getResult() {
		double error = _maintainValue - _input;			// похибка регулювання
		double deltaInput = _prevInput - _input;			// зміна вхідного сигналу за dt
		_prevInput = _input;								// запам'ятовуємо попереднє
		if (_direction) {								// зміна напрямку
			error = -error;
			deltaInput = -deltaInput;
		}
		_pwmOutputValue = _mode ? 0 : (error * _Kp); 				// пропорційна складова
		_pwmOutputValue += deltaInput * _Kd / _dtSeconds;				// диференціальна складова

		
		/*	
		
		// Режим інтегрального вікна
		if (++t >= PID_INTEGRAL_WINDOW) t = 0; 			// промотування t
		_integral -= errors[t];     						// мінусуємо старе	
		errors[t] = error * _Ki * _dtSeconds;  				// запам'ятовуємо в массив
		_integral += errors[t];         					// прибавляем новое	
		
		*/	
		_integral += error * _Ki * _dtSeconds;					// сумування інтегральної суми

		if (_mode) _integral += deltaInput * _Kp;		// режим пропорційно швидкості
		_integral = constrain(_integral, _minPwmVal, _maxPwmVal);// обмеження інтегральної суми
		_pwmOutputValue += _integral;								// інтегральна складова
		_pwmOutputValue = constrain(_pwmOutputValue, _minPwmVal, _maxPwmVal);	// обмежений вихід
		return _pwmOutputValue;
	}
	double CDPidRegulator::getResultTimer() {
		if (millis() - _pidTimer >= _dt) {
			_pidTimer = millis();
			getResult();
		}
		return _pwmOutputValue;
	}
	double CDPidRegulator::getResultNow() {
		setDt(millis() - _pidTimer);
		_pidTimer = millis();
		return getResult();
	}




#ifndef CDPidRegulator_h
#define CDPidRegulator_h
#include <Arduino.h>

#define INCREASING 0
#define DECREASING 1
#define ON_ERROR 0
#define ON_RATE 1
/*
	Cyber Done PID Regulator - бібліотека для імплементації пропорційно-інтегрально-диференціального закону регулювання 
	(ПІД регклятора)
*/
class CDPidRegulator {
public:
	CDPidRegulator();
	CDPidRegulator(double newKp, double newKi, double newKd, int32_t newDt = 100);
										
	void setMaintainValue(double maintainValue);					// встановити значення для підтримування регулятором
	void setInput(double sensorValue);								// встановити вхідне значення
	void setKp(double Kp);											// встановити коефіцієнт пропорційної складової
	void setKi(double Ki);											// встановити коефіцієнт інтегральної складової
	void setKd(double Kd);											// встановити коефіцієнт диференціальної складової
	void setDt(int32_t newDt);										// встановити час дискретизації
	void setMode(bool mode);										// режим: ON_ERROR (за вх. похибкою),ON_RATE (за зміною)
	void setDirection(bool direction);								// керунок:INCREASING (за зрост.),DECREASING (за спад.)
	void setPwmLimits(uint16_t pwmMinValue, uint16_t pwmMaxValue);	// ліміт ШІМ (PWM) (наприклад, для 16bit 0-65535)
	
	double getMaintainValue();										// отримати значення яке підтримує регулятор
	double getKp();													// отримати коефіцієнт пропорційної складової
	double getKi();													// отримати коефіцієнт інтегральної складової
	double getKd();													// отримати коефіцієнт диференціальної складової
	int32_t getDt();												// отримати час дискретизації
	bool getMode();													// отримати режим
	bool getDirection();											// отримати керунок
	uint16_t getPwmMinLimit();										// отримати мінімальне значення ШІМ (PWM)
	uint16_t getPwmMaxLimit();										// отримати максиммальне значення ШІМ (PWM)

	double getResult();												// повертає значення за викор. власного таймера з періодом dT
	double getResultTimer();										// повертає значення за dt час в мс вбудованого таймера 
	double getResultNow();											// повертає значення за час від останнього спрацювання регулятора
	
private:
	double _maintainValue = 0;										// значення сенсора, яке регулятор буде утримувати
	double _input = 0;												// вхідний сигнал (значення сенсора)	
	double _Kp = 0.0;												// коефіцієнт P
	double _Ki = 0.0;												// коефіцієнт I
	double _Kd = 0.0;												// коефіцієнт D	
	int32_t _dt = 100;												// час дискретизації в мілісекундах
	bool _mode = 0;													// режим: ON_ERROR (за вх. похибкою),ON_RATE (за зміною)
	bool _direction = 0;											// керунок:INCREASING (за зрост.),DECREASING (за спад.)
	uint16_t _minPwmVal = 0;										// ліміт ШІМ (PWM) мінімум
	uint16_t _maxPwmVal = 255;										// ліміт ШІМ (PWM) максимум
	
	double _dtSeconds = 0.1;										// час дискретизації у секундах
	double _prevInput = 0;											// змінна попередньої вхідної величини
	uint32_t _pidTimer = 0;											// змінна лічильника таймера
	double _integral = 0.0;											// інтегральна сума
	double _pwmOutputValue = 0;										// вихідне значення ШІМ  PID-регулятора
/*
	double errors[20];
	int t = 0;	
*/
};
#endif
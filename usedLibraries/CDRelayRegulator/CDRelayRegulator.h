#ifndef CDRelayRegulator_h
#define CDRelayRegulator_h
#include <Arduino.h>
#define INCREASING 0
#define DECREASING 1

class CDRelayRegulator{
public:
	// INCREASING - вмикаємо реле при переході через значення знизу (значення від сенсора зростає).
	// DECREASING - вмикаємо реле при переході через значення зверху (значення від сенсора спадає).
	CDRelayRegulator();
	CDRelayRegulator(bool direction = INCREASING);
	
	void setDirection(bool direction);				// напрямок регулювання (INCREASING, DECREASING)
	void setInput(double sensorValue);				// вхідний сигнал (значення з сенсора)
	void setMaintainValue(double maintainValue);	// підтримуване значення (значення, яке контролюватиме регулятор)
	void setHysteresis(double hysteresis);			// ширина вікна гістерезису
	void setK(double k);							// коефіцієнт підсилення по швидкості
	void setDt(uint32_t dT);						// час ітерації в мс
	
	bool getDirection();							// напрямок регулювання (INCREASING, DECREASING)
	double getInput();								// вхідний сигнал (значення з сенсора)
	double getMaintainValue();						// підтримуване значення (значення, яке контролюватиме регулятор)
	double getHysteresis();							// ширина вікна гістерезису
	double getK();									// коефіцієнт підсилення по швидкості
	uint32_t getDt();								// час ітерації в мс
		
	// функція повертає стан для реле (1 - включене, 0 - виключене)
	bool getResultTimer();							// розрахунок по вмунтованому таймеру
	bool compute(double dt = 0);					// моментальний розрахунок. Приймає dt в секундах. 
	bool getResult();								// моментальний розрахунок. Вмунтований таймер.
	
private:	
	double _input = 0;							
	double _maintainValue = 0;						
	bool _output = 0;							
	double _hysteresis = 0;
	double _k = 0;									
	uint32_t _dT = 1000;	
	uint32_t _prevTime = 0;
	double _prevInput = 0.0;
	bool _direction = false;
};
#endif
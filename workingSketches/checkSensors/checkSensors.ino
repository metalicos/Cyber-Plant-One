#include "GyverPID.h"
#include "GyverRelay.h"
#include "CDRelayRegulator.h"
#include "CDPidRegulator.h"
#include "CDSoilMoistureSensor.h"

const int chId[] = {0, 1, 2, 3};
const int chFreq[] = {1000, 1000, 1000, 1000};
const int chResolution[] = {16, 16, 16, 16};
const int chPin[] = {0, 4, 16, 17};
#define ADC_MAX 1023
// #define PID_INTEGRAL_WINDOW 50
int sensors[4] = {34, 35, 32, 33};
//int relay[NUM] = {0, 4, 16, 17};

CDSoilMoistureSensor sensor = CDSoilMoistureSensor(34, 35, 32, 33, 100);

CDRelayRegulator reg[] = {
  CDRelayRegulator(INCREASING),
  CDRelayRegulator(INCREASING),
  CDRelayRegulator(INCREASING),
  CDRelayRegulator(INCREASING)
};

CDPidRegulator pid[] = {
  CDPidRegulator(),
  CDPidRegulator(),
  CDPidRegulator(),
  CDPidRegulator()
};
/*
  GyverPID pid[] = {
  GyverPID(0.1, 0.05, 0.01, 10),
  GyverPID(0.1, 0.05, 0.01, 10),
  GyverPID(0.1, 0.05, 0.01, 10),
  GyverPID(0.1, 0.05, 0.01, 10)
  };

  GyverRelay reg[] = {
  GyverRelay(NORMAL),
  GyverRelay(NORMAL),
  GyverRelay(NORMAL),
  GyverRelay(NORMAL)
  };
*/
void setup() {
  Serial.begin(115200);

  for (byte i = 0; i < 4; i++) {

    ledcSetup(chId[i], chFreq[i], chResolution[i]);
    ledcAttachPin(chPin[i], chId[i]);

    pid[i].setDirection(INCREASING);
    pid[i].setMode(ON_ERROR);
    pid[i].setPwmLimits(0, 65535);
    pid[i].setMaintainValue(31.25);
    pid[i].setKp(5.2);
    pid[i].setKi(1.5);
    pid[i].setKd(0.2);
    pid[i].setDt(1000);

    /*
        reg[i].setDirection(INCREASING);
        reg[i].setMaintainValue(35.5);
        reg[i].setHysteresis(5.0);
        reg[i].setK(0.5);                 // коеф. інерційності системи
        reg[i].setDt(500);                // час ітерації
    */
  }

  for (byte i = 0; i < 4; i++) {
    pinMode(chPin[i], OUTPUT);
  }

}
/*
  double calculatePercentage(unsigned long long averageValue) {
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
  void getMoistureInPercentage(double *moisture, int filterNum) {

  unsigned long long avr1 = 0;
  unsigned long long avr2 = 0;
  unsigned long long avr3 = 0;
  unsigned long long avr4 = 0;

  for (int i = 0; i < filterNum; i++) {
    avr1 += analogRead(34);
    avr2 += analogRead(35);
    avr3 += analogRead(32);
    avr4 += analogRead(33);
  }

  avr1 /= filterNum;
  avr2 /= filterNum;
  avr3 /= filterNum;
  avr4 /= filterNum;

  moisture[0] = calculatePercentage(avr1);
  moisture[1] = calculatePercentage(avr2);
  moisture[2] = calculatePercentage(avr3);
  moisture[3] = calculatePercentage(avr4);
  }
*/

void loop() {
  double moisture[4];
  sensor.getMoistureInPercentage(moisture);
  //getMoistureInPercentage(moisture, 100);
  for (int8_t i = 0; i < 4; i++) {
    Serial.print("S"); Serial.print(i); Serial.print("="); Serial.print(moisture[i]); Serial.print(" ");
  }
  for (byte i = 0; i < 4; i++) {
    pid[i].setInput(moisture[i]);
    int pwmVal = pid[i].getResultTimer();
    Serial.print(pwmVal); Serial.print(" ");
    ledcWrite(chId[i], pid[i].getResultTimer());
    /*
      reg[i].setInput(moisture[i]);
      boolean relVal = reg[i].getResultTimer();
      Serial.print(relVal); Serial.print(" ");
      digitalWrite(chPin[i], relVal);
    */
  }
  Serial.println();
}

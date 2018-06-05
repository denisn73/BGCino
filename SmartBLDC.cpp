#include "SmartBLDC.h"

SmartPWM::SmartPWM(uint8_t pin, uint8_t polarity, uint16_t period) :
    pwmPin(pin), pwmDir(polarity), pwmFlag(0), pwmDuty(0),
    pwmInit(false), pwmPeriod(period)
{
}

void SmartPWM::attach(uint8_t pinA, uint8_t pinB, uint8_t pinC)
{
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
}


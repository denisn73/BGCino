#ifndef _SMART_BLDC_
#define _SMART_BLDC_

#include <Arduino.h>
#include "SmartPWM.h"

class SmartBLDC
{

  public :

    SmartBLDC();
    void attach(uint8_t pinA, uint8_t pinB, uint8_t pinC);
    void setOutputPower(uint16_t pwm);
    void pwm(uint16_t value);
    void handle();
    
    uint8_t  pwmInit;
    uint8_t  pwmFlag;
    uint8_t  pwmDir;
    uint8_t  pwmPin;
    uint16_t pwmDuty;

  private :

    SmartPWM phaseA, phaseB, phaseC;

    uint16_t pwmCounter = 0;
    uint16_t pwmPeriod  = DEFAULT_PWM_PERIOD;
    
};

#endif // _SMART_BLDC_

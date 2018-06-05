#ifndef _SMART_PWM_
#define _SMART_PWM_

#include <Arduino.h>

#define DEFAULT_PWM_PERIOD        2000

class SmartPWM
{

  public :

    SmartPWM(uint8_t pin, uint8_t polarity=HIGH, uint16_t period=DEFAULT_PWM_PERIOD);
    void pwm(uint16_t value);
    void handle();
    
    uint8_t  pwmInit;
    uint8_t  pwmFlag;
    uint8_t  pwmDir;
    uint8_t  pwmPin;
    uint16_t pwmDuty;

  private :

    uint16_t pwmCounter = 0;
    uint16_t pwmPeriod  = DEFAULT_PWM_PERIOD;
    
};

#endif // _SMART_PWM_


#include "SmartPWM.h"

SmartPWM::SmartPWM(uint8_t pin, uint8_t polarity, uint16_t period) :
    pwmPin(pin), pwmDir(polarity), pwmFlag(0), pwmDuty(0),
    pwmInit(false), pwmPeriod(period)
{
}

void SmartPWM::pwm(uint16_t value)
{
    if(!pwmInit) {
      pwmInit = true;
      pinMode(pwmPin, OUTPUT);
    }
    pwmDuty = value;
}

void SmartPWM::handle()
{
    if(pwmCounter==0) {                              // начало периода:
        pwmFlag = (pwmDuty > 0);                     // флаг если есть заполнение
        digitalWrite(pwmPin, (pwmFlag==pwmDir));     // устанавливаем состояние пина по флагу
    } else {                                         // в течении периода:
        if(pwmFlag) {                                // если флаг взведен
          if(pwmPeriod > pwmDuty) {                  // по переполнению заполнения
            pwmFlag = 0;                             // обнуляем флаг
            digitalWrite(pwmPin, (pwmFlag==pwmDir)); // устанавливаем состояние пина в ноль
          }                                          // если заполнение > 2000
        }                                            // то пин не сбросит состояние в ноль
    }
    // инкрементируем и обнуляем период по переполнению
    if(++pwmCounter >= pwmPeriod) pwmCounter = 0;
}


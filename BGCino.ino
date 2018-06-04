#include <Wire.h>
#include <FastPID.h>
#include <MPU6050_tockn.h>
#include "BrushlessServo.h"

#include "config.h"

FastPID PID(PID_P, PID_I, PID_D, PID_HZ, PID_BITS, PID_SIGNED);

MPU6050 mpu6050(Wire);

BrushlessServo bldc[3];

void setup() {
  
  Serial.begin(115200);
  Wire.begin();
  
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // назначение пинов мотора
  bldc[PITCH].attach(BLDC_A0, BLDC_B0, BLDC_C0);
  bldc[ROLL].attach(BLDC_A1, BLDC_B1, BLDC_C1);
  bldc[YAW].attach(BLDC_A2, BLDC_B2, BLDC_C2);
  
  // макс. значение PWM синусоиды
  bldc[PITCH].setOutputPower(BLDC_POWER);
  bldc[ROLL].setOutputPower(BLDC_POWER);
  bldc[YAW].setOutputPower(BLDC_POWER);
  
  // кол-во периодов синусоиды на оборот
  bldc[PITCH].setCycles(BLDC_CYCLES);
  bldc[ROLL].setCycles(BLDC_CYCLES);
  bldc[YAW].setCycles(BLDC_CYCLES);

}

void loop() {
  
//  mpu6050.update();
//
//  static uint32_t lastMillis = millis();
//
//  if(millis() - lastMillis >= 1000) {
//  
//    Serial.print("angleX : ");
//    Serial.print(mpu6050.getAngleX());
//    Serial.print("\tangleY : ");
//    Serial.print(mpu6050.getAngleY());
//    Serial.print("\tangleZ : ");
//    Serial.println(mpu6050.getAngleZ());
//
//    bldc[PITCH].write(mpu6050.getAngleX());
//    bldc[ROLL].write(mpu6050.getAngleY());
//    bldc[YAW].write(mpu6050.getAngleZ());
//    
//    lastMillis = millis();
//    
//  }

//  int setpoint = random(0, 1023) / 2; 
//  int feedback = random(0, 1023);
//  uint32_t before, after;
//  before = micros();
//  uint8_t output = PID.step(setpoint, feedback);
//  after = micros();
//  
//  //analogWrite(PIN_OUTPUT, output);
//  Serial.print("runtime: "); 
//  Serial.print(after - before);
//  Serial.print(" sp: ");
//  Serial.print(setpoint); 
//  Serial.print(" fb: "); 
//  Serial.print(feedback);
//  Serial.print(" out: ");
//  Serial.println(output);

  static uint8_t dir = 1;
  static uint8_t val = 1;
  if(dir) {
    if(val++>=180) dir = 0;
  } else {
    if(--val==0) dir = 1;
  }

  Serial.print("BLDC[PITCH].write: ");
  Serial.println(val);
  bldc[PITCH].write(val);
  Serial.println();
  
  delay(250);

}

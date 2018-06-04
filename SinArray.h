// Brushless motor library
// copyright Alexandre Iooss, 2017-2018
// Please see README.txt for license information

// This objet stores sin values in memory for faster calculations.

#ifndef SIN_ARRAY_h
#define SIN_ARRAY_h

#include "Arduino.h"

//#define SIN_GENERATOR

#define N_VALUES                 512
#define STORE_TYPE_RANGE       32767

class SinArray
{
  
public:

  void   generate();                 // Initialization
  double getSinDegree(double a);     // Get sin with a in degree
  double getSin(double r);           // Get sin with r in radian

private:
  
  double getSinByOffset(int offset); // Move to a offset between 0 and PRECISION
  
};

#endif

#include <cmath>

#include "OneZero.h"

OneZero::OneZero() : 
del(0.0),
b1(0.0){}

void OneZero::setB1(float b){
  b1 = b;
}
    
float OneZero::tick(float input){
  float output = input + del*b1;
  del = input;
  return output*0.5;
}

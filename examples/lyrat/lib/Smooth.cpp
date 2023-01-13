#include <cmath>

#include "Smooth.h"

Smooth::Smooth() : 
del(0.0),
s(0.999)
{
}

void Smooth::setPole(float p){
  s = p;
}
    
float Smooth::tick(float input){
  float output = (1 - s)*input + s*del;
  del = output;
  return output;
}

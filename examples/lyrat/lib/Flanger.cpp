#include <cmath>

#include "Flanger.h"

Flanger::Flanger(int SR) : 
del(100),
index(0.9),
depth(1.0),
echo(SR,100),
sine(SR)
{
  setFrequency(1);
  setFeedback(0.9);
  setDel(10);
}

void Flanger::setFeedback(float f){
  echo.setFeedback(f);
}
    
void Flanger::setDel(int d){
  del = d;
}

void Flanger::setIndex(float i){
  index = i;
}

void Flanger::setDepth(float d){
  depth = d;
}

void Flanger::setFrequency(float f){
  sine.setFrequency(f);
}
    
float Flanger::tick(float input){
  float LFO = sine.tick()*0.5 + 0.5;
  echo.setDel(del*(1-LFO*index));
  float output = echo.tick(input)*depth;
  return output;
}

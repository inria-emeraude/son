#include <cmath>

#include "Phasor.h"

Phasor::Phasor(int SR) : 
phasorDelta(0.0),
phasor(0.0),
samplingRate(SR){
  setFrequency(440);
}

void Phasor::setFrequency(float f){
  phasorDelta = f/samplingRate;
}
    
float Phasor::tick(){
  float currentSample = phasor;
  phasor += phasorDelta;
  phasor = phasor - std::floor(phasor);
  return currentSample;
}

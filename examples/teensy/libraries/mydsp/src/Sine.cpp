#include <cmath>

#include "Sine.h"

#define SINE_TABLE_SIZE 16384

Sine::Sine(int SR) : 
sineTable(SINE_TABLE_SIZE),
phasor(SR),
gain(1.0),
samplingRate(SR){}

void Sine::setFrequency(float f){
  phasor.setFrequency(f);
}
    
void Sine::setGain(float g){
  gain = g;
}
    
float Sine::tick(){
  int index = phasor.tick()*SINE_TABLE_SIZE;
  return sineTable.tick(index)*gain;
}

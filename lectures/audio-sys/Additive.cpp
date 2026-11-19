#include <cmath>

#include "Additive.h"

#define SINE_TABLE_SIZE 16384

Additive::Additive(int SR) :
sineTable(SINE_TABLE_SIZE),
phasor(SR),
gain(1.0),
samplingRate(SR){}

void Additive::setFrequency(float f){
  phasor.setFrequency(f);
}
    
void Additive::setGain(float g){
  gain = g;
}
    
float Additive::tick(){
  int index = phasor.tick()*SINE_TABLE_SIZE;
  int index2 = (int) (index*1.5)%SINE_TABLE_SIZE;
  return (sineTable.tick(index)+sineTable.tick(index2))*gain*0.5;
}

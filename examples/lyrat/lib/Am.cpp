#include <cmath>

#include "Am.h"

#define SINE_TABLE_SIZE 16384

Am::Am(int SR) : 
sineTable(SINE_TABLE_SIZE),
cPhasor(SR),
mPhasor(SR),
modIndex(1.0),
gain(1.0),
samplingRate(SR){}

void Am::setCFreq(float f){
  cPhasor.setFrequency(f);
}

void Am::setMFreq(float f){
  mPhasor.setFrequency(f);
}

void Am::setIndex(float i){
  modIndex = i;
}
    
void Am::setGain(float g){
  gain = g;
}
    
float Am::tick(){
  int cIndex = cPhasor.tick()*SINE_TABLE_SIZE;
  int mIndex = mPhasor.tick()*SINE_TABLE_SIZE;
  float posMod = sineTable.tick(mIndex)*0.5 + 0.5;
  return sineTable.tick(cIndex)*(1 - posMod*modIndex)*gain;
}

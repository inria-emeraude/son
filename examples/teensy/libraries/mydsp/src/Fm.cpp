#include <cmath>

#include "Fm.h"

#define SINE_TABLE_SIZE 16384

Fm::Fm(int SR) : 
sineTable(SINE_TABLE_SIZE),
cPhasor(SR),
mPhasor(SR),
cFreq(440.0),
modIndex(100.0),
gain(1.0),
samplingRate(SR){}

void Fm::setCFreq(float f){
  cFreq = f;
}

void Fm::setMFreq(float f){
  mPhasor.setFrequency(f);
}

void Fm::setIndex(float i){
  modIndex = i;
}
    
void Fm::setGain(float g){
  gain = g;
}
    
float Fm::tick(){
  int mIndex = mPhasor.tick()*SINE_TABLE_SIZE;
  float modulator = sineTable.tick(mIndex);
  cPhasor.setFrequency(cFreq + modulator*modIndex);
  int cIndex = cPhasor.tick()*SINE_TABLE_SIZE;
  return sineTable.tick(cIndex)*gain;
}

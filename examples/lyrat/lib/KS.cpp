#include <cmath>

#include "KS.h"

KS::KS(int SR) : 
feedback(0.999),
samplingRate(SR),
zeroDel(0.0),
readIndex(1),
writeIndex(0),
del(0),
trig(false)
{
  int maxDel = 1024;
  delBuffer = new float[maxDel];
  for(int i=0; i<maxDel; i++){
    delBuffer[i] = 0.0;
  }
  setFreq(440);
}

KS::~KS()
{
  delete[] delBuffer;
}

void KS::setFeedback(float f){
  feedback = f;
}
    
void KS::setFreq(float f){
  del = samplingRate/f;
}

void KS::trigger(){
  trig = true;
}

float KS::oneZero(float x){
  float output = (x + zeroDel)*0.5; 
  zeroDel = output;
  return output;
}
    
float KS::tick(){
  float excitation;
  if(trig){
    excitation = 1.0;
    trig = false;
  }
  else{
    excitation = 0.0;
  }
  float output = excitation + oneZero(delBuffer[readIndex])*feedback;
  delBuffer[writeIndex] = output;
  readIndex = (readIndex+1)%del;
  writeIndex = (writeIndex+1)%del;
  return output;
}

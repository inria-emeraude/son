#ifndef FM_H_INCLUDED
#define FM_H_INCLUDED

#include "SineTable.h"
#include "Phasor.h"

class Fm{
public:
  Fm(int SR);
  
  void setCFreq(float f);
  void setMFreq(float f);
  void setIndex(float i);
  void setGain(float g);
  float tick();
private:
  SineTable sineTable;
  Phasor cPhasor,mPhasor;
  float cFreq,modIndex,gain;
  int samplingRate;
};

#endif  // FM_H_INCLUDED
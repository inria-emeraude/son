#ifndef AM_H_INCLUDED
#define AM_H_INCLUDED

#include "SineTable.h"
#include "Phasor.h"

class Am{
public:
  Am(int SR);
  
  void setCFreq(float f);
  void setMFreq(float f);
  void setIndex(float i);
  void setGain(float g);
  float tick();
private:
  SineTable sineTable;
  Phasor cPhasor,mPhasor;
  float modIndex,gain;
  int samplingRate;
};

#endif  // AM_H_INCLUDED
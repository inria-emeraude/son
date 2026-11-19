#ifndef ADDITIVE_H_INCLUDED
#define ADDITIVE_H_INCLUDED

#include "SineTable.h"
#include "Phasor.h"

class Additive{
public:
  Additive(int SR);
  
  void setFrequency(float f);
  void setGain(float g);
  float tick();
private:
  SineTable sineTable;
  Phasor phasor;
  float gain;
  int samplingRate;
};

#endif  // ADDITIVE_H_INCLUDED

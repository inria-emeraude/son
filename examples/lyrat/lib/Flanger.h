#ifndef FLANGER_H_INCLUDED
#define FLANGER_H_INCLUDED

#include "Echo.h"
#include "Sine.h"

class Flanger{
public:
  Flanger(int SR);
  
  void setFeedback(float f);
  void setDel(int d);
  void setIndex(float i);
  void setDepth(float d);
  void setFrequency(float f);
  float tick(float input);
private:
  int del;
  float index, depth;
  Echo echo;
  Sine sine;
};

#endif  // FLANGER_H_INCLUDED
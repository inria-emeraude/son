#ifndef PHASOR_H_INCLUDED
#define PHASOR_H_INCLUDED

class Phasor{
public:
  Phasor(int SR);
  
  void setFrequency(float f);
  float tick();
private:
  float phasorDelta, phasor;
  int samplingRate;
};

#endif  // PHASOR_H_INCLUDED
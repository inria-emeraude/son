#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

class dsp;
class MapUI;

class MyDsp : public AudioStream
{
  public:
    MyDsp();
    ~MyDsp();
    
    virtual void update(void);
    void setFreq(float freq);
    void setCutoff(float freq);
    void setGate(int gate);
    
  private:
    MapUI* fUI;
    dsp* fDSP;
    float **outputs;
};

#endif

#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Fm.h"

class MyDsp : public AudioStream
{
  public:
    MyDsp();
    ~MyDsp();
    
    virtual void update(void);
    void setCFreq(float freq);
    void setMFreq(float freq);
    void setIndex(float i);
    void setGain(float gain);
    
  private:
    Fm fm;
};

#endif

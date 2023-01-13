#ifndef __AUDIODSP_H
#define __AUDIODSP_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class dsp;
class MapUI;

class AudioDsp
{
public:
  AudioDsp(int SR, int BS);
  ~AudioDsp();
  bool start();
  void stop();
  void setFreq(float freq);
  void setCutoff(float freq);
private:
  void audioTask();
  static void audioTaskHandler(void* arg);
  
  int fSampleRate, fBufferSize, fNumOutputs;
  TaskHandle_t fHandle;
  bool fRunning;
  
  MapUI* fUI;
  dsp* fDSP;
  float **outputs;
};

#endif
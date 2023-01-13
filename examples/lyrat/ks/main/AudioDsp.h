#ifndef __AUDIODSP_H
#define __AUDIODSP_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../../lib/KS.h"

class AudioDsp
{
public:
  AudioDsp(int SR, int BS);
  bool start();
  void stop();
  void setFreq(float freq);
  void trigger();
private:
  void audioTask();
  static void audioTaskHandler(void* arg);
  
  int fSampleRate, fBufferSize, fNumOutputs;
  TaskHandle_t fHandle;
  bool fRunning;
  
  KS ks;
};

#endif
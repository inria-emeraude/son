#ifndef __AUDIODSP_H
#define __AUDIODSP_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../../lib/Sine.h"
#include "../../lib/Echo.h"

class AudioDsp
{
public:
  AudioDsp(int SR, int BS);
  bool start();
  void stop();
  void setFreq(float freq);
private:
  void audioTask();
  static void audioTaskHandler(void* arg);
  
  int fSampleRate, fBufferSize, fNumOutputs;
  TaskHandle_t fHandle;
  bool fRunning;
  
  Sine sine;
  Echo echo;
};

#endif
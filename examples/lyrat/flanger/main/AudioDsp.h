#ifndef __AUDIODSP_H
#define __AUDIODSP_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../../lib/Flanger.h"

class AudioDsp
{
public:
  AudioDsp(int SR, int BS);
  bool start();
  void stop();
private:
  void audioTask();
  static void audioTaskHandler(void* arg);
  
  int fSampleRate, fBufferSize, fNumInputs, fNumOutputs;
  TaskHandle_t fHandle;
  bool fRunning;
  
  Flanger flangerL, flangerR;
};

#endif
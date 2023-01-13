#ifndef __AUDIODSP_H
#define __AUDIODSP_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../../lib/Noise.h"
#include "../../lib/OneZero.h"

class AudioDsp
{
public:
  AudioDsp(int SR, int BS);
  bool start();
  void stop();
  void setB1(float b1);
private:
  void audioTask();
  static void audioTaskHandler(void* arg);
  
  int fSampleRate, fBufferSize, fNumOutputs;
  TaskHandle_t fHandle;
  bool fRunning;
  
  Noise noise;
  OneZero oneZero;
};

#endif
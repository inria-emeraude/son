#include "MyDsp.h"

#define AUDIO_OUTPUTS 2

#define MULT_16 32767
#define DIV_16 0.0000305185

MyDsp::MyDsp() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
distortionL(),
distortionR()
{
  // setting up DSP objects
  distortionL.setDrive(0.5);
  distortionL.setGain(0.5);
  distortionR.setDrive(0.5);
  distortionR.setGain(0.5);
}

MyDsp::~MyDsp(){}

void MyDsp::update(void) {
  audio_block_t* inBlock[AUDIO_OUTPUTS];
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    inBlock[channel] = receiveReadOnly(channel);
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        float currentSample = 0; 
        if(inBlock[channel]){
          currentSample = inBlock[channel]->data[i]*DIV_16;
        }
        if(channel == 0) currentSample = distortionL.tick(currentSample);
        else if(channel == 1) currentSample = distortionR.tick(currentSample);
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      if(inBlock[channel]) release(inBlock[channel]);
      release(outBlock[channel]);
    }
  }
}

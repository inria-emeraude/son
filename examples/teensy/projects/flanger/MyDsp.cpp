#include "MyDsp.h"

#define AUDIO_OUTPUTS 2

#define MULT_16 32767
#define DIV_16 0.0000305185

MyDsp::MyDsp() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
flangerL(AUDIO_SAMPLE_RATE_EXACT),
flangerR(AUDIO_SAMPLE_RATE_EXACT)
{
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
        if(channel == 0) currentSample = flangerL.tick(currentSample);
        else if(channel == 1) currentSample = flangerR.tick(currentSample);
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

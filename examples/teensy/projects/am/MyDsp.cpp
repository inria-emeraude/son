#include "MyDsp.h"

#define AUDIO_OUTPUTS 1

#define MULT_16 32767

MyDsp::MyDsp() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
am(AUDIO_SAMPLE_RATE_EXACT)
{
}

MyDsp::~MyDsp(){}

void MyDsp::setCFreq(float freq){
  am.setCFreq(freq);
}

void MyDsp::setMFreq(float freq){
  am.setMFreq(freq);
}

void MyDsp::setIndex(float freq){
  am.setIndex(freq);
}

// set sine wave gain
void MyDsp::setGain(float gain){
  am.setGain(gain);
}

void MyDsp::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        float currentSample = am.tick();
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    }
  }
}

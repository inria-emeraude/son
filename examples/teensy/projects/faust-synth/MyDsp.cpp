#include "MyDsp.h"
#include "FaustSynth.h"

#define AUDIO_OUTPUTS 2

#define MULT_16 32767

MyDsp::MyDsp() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS])
{
  fDSP = new mydsp();
  fDSP->init(AUDIO_SAMPLE_RATE_EXACT);
  fUI = new MapUI();
  fDSP->buildUserInterface(fUI);
  outputs = new float*[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; ++channel){
    outputs[channel] = new float[AUDIO_BLOCK_SAMPLES];
  }
}

MyDsp::~MyDsp(){
  delete fDSP;
  delete fUI;
  for (int channel = 0; channel < AUDIO_OUTPUTS; ++channel){
    delete[] outputs[channel];
  }
  delete [] outputs;
}

void MyDsp::setFreq(float freq){
  fUI->setParamValue("freq",freq);
}

void MyDsp::setCutoff(float freq){
  fUI->setParamValue("cutoff",freq);
}

void MyDsp::setGate(int gate){
  fUI->setParamValue("gate",gate);
}

void MyDsp::update(void) {
  fDSP->compute(AUDIO_BLOCK_SAMPLES,NULL,outputs);
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        int16_t val = outputs[channel][i]*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    }
  }
}

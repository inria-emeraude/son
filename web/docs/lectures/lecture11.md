# Lecture 11: Faust on the Teensy and Advanced Control

## Generating and Using a Faust C++ Object

**In order to run the examples in this lecture, you should install the Faust distribution on your system from the [Faust Git Repository](https://github.com/grame-cncm/faust).**

At the most fundamental level, the Faust compiler is a command line tool translating a Faust DSP object into C++ code. For example, assuming that Faust is properly installed on your system, given the following simple Faust program implementing a filtered sawtooth wave oscillator ([`FaustSynth.dsp`](https://github.com/grame-cncm/embaudio/blob/master/faust/FaustSynth.dsp)):

```
import("stdfaust.lib");
freq = nentry("freq",200,50,1000,0.01);
gain = nentry("gain",0.5,0,1,0.01) : si.smoo;
gate = button("gate") : si.smoo;
cutoff = nentry("cutoff",10000,50,10000,0.01) : si.smoo;
process = os.sawtooth(freq)*gain*gate : fi.lowpass(3,cutoff) <: _,_;
```

running:

```
faust FaustSynth.dsp
```

will output the C++ code corresponding to this file in the terminal. 

Faust comes with a system of C++ wrapper (called architectures in the Faust ecosystem) which can be used to customize the generated C++ code. [`faustMininal.h`](https://github.com/grame-cncm/embaudio/blob/master/faust/faustMinimal.h) is a minimal architecture file including some C++ objects that can be used to facilitate interactions with the generated DSP:

```
#include <cmath>
#include <cstring>

#include "faust/gui/MapUI.h"
#include "faust/gui/meta.h"
#include "faust/dsp/dsp.h"

// BEGIN-FAUSTDSP

<<includeIntrinsic>>

<<includeclass>>

// END-FAUSTDSP
```

For instance, `MapUI` allows us to access the parameters of a Faust DSP object using the `setParamValue` method, etc.

To generate a C++ file using this architecture, you can run:

```
faust -i -a faustMinial.h FaustSynth.dsp -o FaustSynth.h
```

which will produce a [`FaustSynth.h`](https://github.com/grame-cncm/embaudio/blob/master/examples/teensy/projects/faust-synth/FaustSynth.h) file (feel free to click on it).

The `-i` inlines all the included C++ `.h` files in the generated file.

The [`faust-synth`](https://github.com/grame-cncm/embaudio/blob/master/examples/teensy/projects/faust-synth) Teensy example project demonstrates how `FaustSynth.h` can be used. First, it is included in [`MyDsp.cpp`](https://github.com/grame-cncm/embaudio/blob/master/examples/teensy/projects/faust-synth/MyDsp.cpp) and the following elements are declared in [the corresponding header file](https://github.com/grame-cncm/embaudio/blob/master/examples/teensy/projects/faust-synth/MyDsp.h):

```
private:
  MapUI* fUI;
  dsp* fDSP;
  float **outputs;
```

`dsp` is the actual Faust DSP, `MapUI` will be used to interact with it, and `outputs` is the multidimensional output buffer. These objects are then allocated in the constructor of `MyDsp.cpp`:

```
fDSP = new mydsp();
fDSP->init(AUDIO_SAMPLE_RATE_EXACT);
fUI = new MapUI();
fDSP->buildUserInterface(fUI);
outputs = new float*[AUDIO_OUTPUTS];
for (int channel = 0; channel < AUDIO_OUTPUTS; ++channel){
  outputs[channel] = new float[AUDIO_BLOCK_SAMPLES];
}
```

`buildUserInterface` is used to connect `fUI` to `fDSP` and then memory is allocated for the output buffer. Note that memory should be de-allocated in the destructor after this. In the `update` method, we just call the `compute` method of `fDSP` and then reformat the generated samples to transmit them via i2s:

```
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
``` 

Note that `outputs` is used as an intermediate here and the first dimension of the array is the channel number and the second dimension the samples themselves. 

The various parameters of the Faust object can then be changed just by calling the `setParamValue` method. The first argument of the method corresponds to the name of the parameter as specified in the Faust program:

```
void MyDsp::setFreq(float freq){
  fUI->setParamValue("freq",freq);
}

void MyDsp::setCutoff(float freq){
  fUI->setParamValue("cutoff",freq);
}

void MyDsp::setGate(int gate){
  fUI->setParamValue("gate",gate);
}
```

## Better Control on the Teensy

In addition to controlling DSP parameters on the Teensy using external sensors connected to the board's GPIOs, other techniques can potentially be used. We briefly summarize this section.

### MIDI

[MIDI](https://en.wikipedia.org/wiki/MIDI) is THE standard in the world of music to control digital devices. It has been around since 1983 and even though it is very "low tech," it is still heavily used. While MIDI was traditionally transmitted over MIDI ports, USB is used nowadays to send MIDI.

USB MIDI is natively supported on the Teensy through the Teensy USB MIDI library: <https://www.pjrc.com/teensy/td_midi.html>. Interfacing this library with your DSP programs should be very straightforward. Please, also note that Teensys can be used to send MIDI messages over USB which means that implementing your own midi controller using a Teensy is fairly straightforward as well. If you're curious about this, you can check this page: <https://ccrma.stanford.edu/courses/250a-winter-2018/labs/2/>.

### OSC

[Open Sound Control (OSC)](https://en.wikipedia.org/wiki/Open_Sound_Control) is a more modern communication standard used in the field of music technology. It is based on UDP which means that information can be transmitted via Ethernet or Wi-Fi. OSC uses a system of address/values to access the different parameters of a system. An OSC message can therefore look like:

```
/synth/freq 440
```

On the Teensy, dealing with OSC is a bit more tricky than MIDI because the Teensy 4.0 provided as part of your class kit don't have a built-in Ethernet port. Hence, the only way to get an Ethernet connection to the Teensy is to buy an external Ethernet adapter (that will likely connect to the Teensy through i2c, etc.). Another option is to buy a Teensy 4.1 which hosts an Ethernet chip (an Ethernet connector can just be soldered to the board).

## Exercises

### Faust Triangle Oscillator

The Faust libraries host a triangle wave oscillator:

```
os.triangle
```

Try to replace the sawtooth wave oscillator from the previous example by a triangle wave oscillator in Faust and run it on the Teensy.

### Flanger

The Faust libraries host a [flanger function](https://faustlibraries.grame.fr/libs/phaflangers/#pfflanger_mono):

```
pf.flanger_mono
```

Turn your Teensy into a flanger effect processor!

# Final Projects

Final projects constitute the heart of this course: students are 100% evaluated on projects. While you should feel free to use any of the code studied during class, found on the web, or generated using tools such as [Faust](https://faust.grame.fr), the following criterion should be taken into account:

* Doing what you were asked to do is good, but doing more is better :);
* Novelty, creativity, and initiatives are crucial: consider your project as a potential startup idea, think about how it can be better than what already exists. Along the same lines, try to have a "product" as finished and as polished as possible;
* Consider the research and scientific aspect of what you're doing: most project ideas will involve some bibliographical work before getting your hands dirty, this will help you get a sense of what has already been done by others and it will save you time when readying your poster.

## Evaluation

Projects will be evaluated through:

* A poster and a demo of your project which will be featured during a poster session taking place on 03/03/2023;
* A webpage presenting your project.

The quality and the presentation of the poster and of the webpage will be taken into account towards your final grade.

As for the project itself, you will be evaluated on its:

* robustness/stability;
* interface;
* novelty;
* rigorousness;
* overall quality;
* potential link to research.

## Final Project Ideas

### Auto-Tune

Auto-tune (<https://en.wikipedia.org/wiki/Auto-Tune>) is a sound effect which automatically correct the pitch of a sound by quantizing it to the nearest note of the chromatic scale. The goal of this project is make an "autotune box/audio processor" based on the Teensy. In addition to figuring out how to implement the algorithm (which should involve pitch shifting and frequency tracking), you should think about the interface that your project will have (which parameters can be controlled?, etc.).

### Vocoder

A Vocoder <https://en.wikipedia.org/wiki/Vocoder> is an audio effect which replaces the natural sound of human voice with an artificial/synthesized one by preserving intelligibility of speech. It can be used to create a "robot/ghost voice." The goal of this project is to make a "vocoder box/audio processor" based on the Teensy. In addition to figuring out how to implement the algorithm (which should involve pitch shifting and frequency tracking), you should think about the interface that your project will have (which parameters can be controlled?, etc.).

### Pitch-Shifting Module

Pitch-Shifting consists in transposing (up or down) the sound of an input source so that it sounds lower or higher. Pitch shifting can potentially be implemented using 2 different techniques: (i) using an FFT to transpose the spectrum and then an inverse FFT to put it back in the time domain, (ii) using the doppler effect produced by changing the length of delay lines in real-time. Hence, the goal of this project is to make a "pitch shifting box/audio processor" based on the Teensy. In addition to figuring out how to implement the algorithm (which should involve pitch shifting and frequency tracking), you should think about the interface that your project will have (which parameters can be controlled?, etc.).

### Hearing Aid

At the most fundamental level, hearing aids just implement a bunch of equalization filters (see TODO) increasing the volume of some bands in the spectrum of a sound (the ones that an individual can't hear well anymore). The goal of this project is to implement an hearing aid prototype based on the Teensy. If time allows it, you should try to measure the audiogram of someone with hearing loss to test your system in a real-world context.

### Cochlear Implant Simulator

Cochlear implants (<https://en.wikipedia.org/wiki/Cochlear_implant>) allow many people who were condemned to be deaf their entire life to now hear some sound and even speech if they're well trained. This paper: <https://embaudio.grame.fr/cochlear.pdf> describes precisely how a cochlear implant simulator can be implemented using DSP. The goal of this project is to create a sound processing box simulating the sound of a cochlear implant. For that, you will probably need some of the filters described [here](TODO).

### Noise Reduction Headset

The goal of this project is to implement a headset processing surrounding sound in real-time to improve intelligibility in loud industrial environments. Say you're working in a factory and one of your colleagues is talking to you even though a machine next to you is making a lot of sound, how do you process the input to enhance the intelligibility of your colleague? Some of the filters described [here](TODO) might be useful.

### Sonification System

Data sonification is a trending method for analyzing data in real-time. The brain stethoscope (<https://youtu.be/pnGzVW_7cfM>) is a good example of that. Choose a sensor technology and develop a sonification technology around it.

### Superman Hearing

Try to make your own version of Facebook's "superman hearing" system (<https://about.fb.com/news/2020/09/facebook-reality-labs-research-future-of-audio/>).

### Guitar Pedal Effect

There exist dozens of guitar pedal effects: <https://en.wikipedia.org/wiki/Effects_unit>. The goal of this project is to make a guitar pedal "stompbox". Don't forget to think about the interface and the shape of the final product.

### Sound Synthesis Module

Modular synthesizers (<https://en.wikipedia.org/wiki/Modular_synthesizer>) became very popular in recent years. Each hardware module implements and sound synthesis or processing technique and offers an interface made of buttons, knobs, etc. The goal of this project is to implement your own sound synthesis module based on a Teensy. If you own a modular synth yourself, think about how your module could integrate to your toolchain, etc.

### EP (Vinyl) Simulator

Love the sound of EPs (<https://en.wikipedia.org/wiki/Extended_play>)? Implement a system that plugs to your living room sound system and makes the sound of any device you plug to it sound like an EP. For that, you will first have to document yourself on the impact on sound of this analog technology. There exists a couple of scientific papers that describe this fairly well. Make sure that you think about the interface that your system will have and about the form that your final product will take, etc.

### Feedback Cancellation Microphone

Feedback happens when a microphone and speaker implement a feedback loop. This results in a very annoying sound which sound engineers try to avoid as much as possible during concerts. Try to make a microphone carrying out real-time audio DSP to limit feedback. There exist many scientific papers on this topic which means that you will first have to document yourself on this topic.

### Augmented Speaker

Make a speaker processing its audio input in real time to add audio effects, improve the quality of sound, etc. The goal of this project is to focus more on the product design aspect to try to design an appealing object. Think about the interface that system could have (maybe accessible through a smartphone? Etc.).

### Musical Instrument

The goal of this project is to make musical instrument based on a Teensy. The domain of New Interfaces for Musical Expression (NIME): <https://www.nime.org/> has been booming in recent years and hundreds of musical instruments have been created. Feel free to get more inspiration here: <https://ccrma.stanford.edu/courses/250a-winter-2022>!

### MIDI-Controlled Polyphonic Synthesizer

Build a polyphonic (multiple notes can be played at the same time) synthesizer based on a USB MIDI keyboard (using the [Teensy USB MIDI Library](https://www.pjrc.com/teensy/td_midi.html)). The keyboard should connect directly to the Teensy through the USB port. The synth should have multiple parameters to control through MIDI CCs. For this project, you'll have to find a way to externally power your Teensy since the USB port will be used for connecting the MIDI keyboard, etc.

### Granular Synthesizer

Granular synthesis <https://en.wikipedia.org/wiki/Granular_synthesis> consists in looping a short sound sample to generate sound textures with it. The goal of this project is to make a granular synthesis module based on a Teensy. You should think about the interface that your system will have (i.e., which parameter to control, etc.). Note that since you will have to record audio samples on the Teensy, you will likely have to use an SD card for this because of the limited amount of memory available on the Teensy.

### DAFx

DAFx is THE conference on digital audio effects: <https://www.dafx.de/>. The goal of this project is to pickup any paper in the DAFx literature and implement it on the Teensy.

### Any Other Idea...

Feel free to work on anything else but talk to us first :).

## Some Tips

### Making Resonant Lowpass, Bandpass and Highpass

This short tutorial demonstrates how to implement a series of filters that can be configured as resonant lowpass, bandpass, and highpasses.

For this, you will first need to implement a biquad filter: [https://en.wikipedia.org/wiki/Digital_biquad_filter](https://en.wikipedia.org/wiki/Digital_biquad_filter) (direct form 2 is preferred). You will then have to format the coefficients of that filter using the [bilinear transform](https://en.wikipedia.org/wiki/Bilinear_transform) such that:

```
tf2s(b2,b1,b0,a1,a0,w1) = tf2(b0d,b1d,b2d,a1d,a2d)
with {
  c   = 1/tan(w1*0.5/SR);
  csq = c*c;
  d   = a0 + a1 * c + csq;
  b0d = (b0 + b1 * c + b2 * csq)/d;
  b1d = 2 * (b0 - b2 * csq)/d;
  b2d = (b0 - b1 * c + b2 * csq)/d;
  a1d = 2 * (a0 - csq)/d;
  a2d = (a0 - a1*c + csq)/d;
};
```

where `tf2` is a direct form 2 biquad and SR the sampling rate.

Finally, you'll have to format the coefficients of the `tf2s` filter such that:

```
resonlp(fc,Q,gain) = tf2s(b2,b1,b0,a1,a0,wc)
with {
     wc = 2*PI*fc;
     a1 = 1/Q;
     a0 = 1;
     b2 = 0;
     b1 = 0;
     b0 = gain;
};
```

(for the resonant lowpass)

```
resonbp(fc,Q,gain) = tf2s(b2,b1,b0,a1,a0,wc)
with {
     wc = 2*PI*fc;
     a1 = 1/Q;
     a0 = 1;
     b2 = 0;
     b1 = gain;
     b0 = 0;
};
```

(for the resonant bandpass)

```
resonhp(fc,Q,gain,x) = gain*x-resonlp(fc,Q,gain,x);
```

(for the resonant highpass).

Please, note that Q controls the bandwidth of the filter such that: `Q = fc/BW`.

Wrap this up by plugging a broadband signal generator (e.g., sawtooth oscillator or white noise generator) to the filter. Come up with some nice mapping controlled with hardware sensors (i.e., rotary pot, etc.).

### Peak Equalizers

Peak equalizers are yet another kind of filters allowing to reduce or increase some bands in the spectrum of a sound. A peak equalizer can take the following form:

```
peak_eq(Lfx,fx,B) = tf2s(1,b1s,1,a1s,1,wx) with {
  T = 1.0/SR;
  Bw = B*T/sin(wx*T); // prewarp s-bandwidth for more accuracy in z-plane
  a1 = PI*Bw;
  b1 = g*a1;
  g = db2linear(abs(Lfx));
  if(Lfx>0) {
    b1s = b1;
    a1s = a1;
  }
  else {
    b1s = a1;
    a1s = b1;
  }
  wx = 2*PI*fx;
};
```

where the definition of `tf2s` (direct-form 2 biquadratic filter operating the bilinear transform) can be found in [Towards Resonant Filter](#towards-resonant-filters). `Lfx` controls the level of the filter in dB (0 for no filtering, negative value for band reduction, and positive value for band amplification). `fx` is the center frequency, `B` the bandwidth in Hz.



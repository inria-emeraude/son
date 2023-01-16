# Final Project

## Final Porject Ideas

### Project Idea 1: Towards Resonant Filters

The goal of this project is to implement a resonant filter that can be configured as a lowpass, bandpass, or highpass. For this, you will first need to implement a biquad filter: [https://en.wikipedia.org/wiki/Digital_biquad_filter](https://en.wikipedia.org/wiki/Digital_biquad_filter) (direct form 2 is preferred). You will then have to format the coefficients of that filter using the [bilinear transform](https://en.wikipedia.org/wiki/Bilinear_transform) such that:

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

### Project Idea 2: Hearing Aids

Basic hearing aids just implement a set of peak equalizing filters connected in sequence and taking the following form:

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

Make an hearing aids allowing us to control at least five bands.

### Project Idea 3: MIDI-Controlled Synthesizer

(This project idea is more targeted towards musicians.)

Implement a MIDI-controlled synthesizer based on the Teensy using the [Teensy USB MIDI Library](https://www.pjrc.com/teensy/td_midi.html). For that, you will need a midi keyboard (we can provide one if necessary). You'll also have to externally power your Teensy (we can help with that). Beyond implementing a cool-sounding synth, we encourage you to think about how polyphony could be implemented.

In the end, you wanna have a MIDI keyboard connected to your Teensy and sound coming out of it...

### Project Idea 4: Guitar Pedal Effect

If you know what you're doing, feel free to implement any guitar pedal effect that you like and that hasn't been studied in class on the Teensy (e.g., distortion, chorus, phaser, etc.).

### Project Idea 5: Sound Synthesis Module

If you know what you're doing, feel free to implement any sound synthesis algorithm that you like and that hasn't been studied in class on the Teensy (e.g., granular synthesis, physical modeling, vocoder, etc.).

### Project Idea 6: Cochlear Implant Simulation

Implement a [cochlear implant](https://en.wikipedia.org/wiki/Cochlear_implant) simulator on the Teensy using the description provided in [this paper](cochlear.pdf).


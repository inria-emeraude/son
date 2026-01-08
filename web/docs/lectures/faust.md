# Introduction to Faust

## Useful Resources

* Faust Website: <https://faust.grame.fr>
* Faust Documentation: <https://faustdoc.grame.fr>
* Faust Libraries Documentation: <https://faustlibraries.grame.fr>
* Faust Online IDE: <https://faustide.grame.fr>

All programs below can be executed in the Faust Online IDE, give them a try ;).

## Sawtooth Synth

```
import("stdfaust.lib");
f = hslider("freq",400,50,2000,0.01);
g = hslider("gain",1,0,1,0.01);
t = button("gate");
envelope = t : en.adsr(0.1,0.01,0.8,0.5);
process = os.sawtooth(f)*g*envelope <: _,_;
effect = dm.zita_light;
```

## Panner

```
import("stdfaust.lib");
g = hslider("gain",1,0,1,0.01) : si.smoo;
pan(p) = _ <: _*(1-psqrt),_*psqrt
with{
    psqrt = p : sqrt;
};
process = pan(g);
```

## Oscillator From Scratch

```
import("stdfaust.lib");
saw(f) = (A~B)/p*2-1
with{
    p = ma.SR/f;
    A = _;
    B = (_+1)%p;
};
sine(f) = (saw(f)*0.5 + 0.5)*2*ma.PI : sin;
freq = hslider("freq[acc: 0 0 -10 0 10]",400,50,2000,0.01) : si.smoo;
s = checkbox("switch");
process = sine(freq)*(s==0) + saw(freq)*(s==1);
```

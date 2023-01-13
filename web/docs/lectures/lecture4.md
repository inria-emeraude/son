# Lecture 4: Hardware Control and Audio Codec Configuration

The two main goals of this lecture are:

* to show you how to control DSP algorithms running on your Teensy using hardware controllers (i.e., potentiometers and buttons);
* to give you a basic understanding of how audio codecs work and how they can be configured using the i2c protocol.

## Hardware Control

### Electronic Basics

While the goal of this class is not to teach electronics nor to make projects involving complicated circuitry, some basic circuits do need to be implemented in order to control the various parameters of the DSP algorithms studied in class using hardware controllers such as buttons and potentiometers. Hence, in case you feel like your electronics skills are a bit rusty, feel free to review the following page: <https://ccrma.stanford.edu/wiki/Introduction_to_Electronics_(condensed)>.

### Teensy 4.0 Pinout

The Teensy pins map can be seen in the following figure (directly taken from the [PJRC website](https://www.pjrc.com/teensy/pinout.html)). Most pins can be used as digital I/Os. Some pins noted "A(N)" can be used as analog inputs. Please, also note that 3.3v power can be retrieved from the top right corner pin and the ground from the top left pin. Make sure to never connect the 5.5v Vin pin to any other pin of the Teensy: that would probably fry it (the Cortex M7 inside the Teensy operates at 3.3v)!

<figure>
<img src="img/pinout0.png" class="mx-auto d-block" width="70%">
<img src="img/pinout1.png" class="mx-auto d-block" width="70%">
<figcaption><center>Teensy pinout.</center></figcaption>
</figure>

The Teensy audio shield uses a bunch of pins on the Teensy for i2c and i2s communication:

<figure>
<img src="img/teensy4_audio_pins.jpg" class="mx-auto d-block" width="50%">
<figcaption><center>Teensy audio shield pins.</center></figcaption>
</figure>

This means that these pins (besides GND and 3.3v, of course) cannot be used for something else (i.e., connecting external sensors).

### Bringing Power to Your Breadboard

The first step in making your first circuit with the Teensy is to bring power to the breadboard included in your kit using jumper wires:

<figure>
<img src="img/teensy.jpg" class="mx-auto d-block" width="80%">
<figcaption><center>Teensy connected to the breadboard.</center></figcaption>
</figure>

Basically connect the 3.3v pin to the red strip and the GND pin to the black strip of the breadboard.

**WARNING: Do not connect the 5.5v pin to the breadboard!**

### Adding a Rotary Potentiometer to the Circuit

Your kit should come with a couple of rotary potentiometers:

<figure>
<img src="img/pot.jpg" class="mx-auto d-block" width="80%">
<figcaption><center>Rotary potentiometer mounted on the breadboard.</center></figcaption>
</figure>

Place it on the breadboard, and connect its leftmost pin to power and its rightmost pin to the ground. Finally, connect its center pin to the A0 pin of the Teensy using a jumper wire. Please, note that we're using this pin since it is not used by the audio shield (see previous section).

### Testing the Potentiometer

In the current configuration, the potentiometer will deliver a 3.3v current at its center pin if it is fully turned to the right side, and 0v if it is fully turned to the left side. The following Teensy program:

```
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(100);
}
```

displays the values measured at the A0 pin on the Teensy in the serial debugger. Values should be between 0 and 1023 (10 bits values). Make sure that the values you're getting are consistent with the position of the potentiometer.

### Controlling DSP Parameters With the Potentiometer

Now that you know how to retrieve potentiometer values in the Teensy, plugging it to your audio DSP should be pretty straightforward. Hence, we can reuse the `crazy-sine` example and do:

```
#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  int sensorValue = analogRead(A0);
  float freq = sensorValue + 100;
  myDsp.setFreq(freq);
}
```

Note that `sensorValue` needs to be turned into a frequency in hertz so we just add 100 to it to get a frequency between 100 and 1123 hertz.

Now take some time to have fun ;)!

### Using a Button

Using a button with the Teensy is slightly more involving since the use of a pulldown resistor is required (alternatively, a pullup resistor could be used, of course). This is due to the fact that buttons are "just" circuit breakers: they don't have a dedicated output pin like potentiometers. The pulldown resistor is used to suck potential floating currents out of the output pin of the button in order to get a stable signal to be measured on the Teensy. Hence, the following circuit must be implemented:

<figure>
<img src="img/circuit.jpg" class="mx-auto d-block" width="80%">
<figcaption><center>Circuit to connect a button to the Teensy.</center></figcaption>
</figure>

There's no need to use an analog pin on the Teensy to measure the voltage at the output of the button since we're looking at discrete values here (0 or 1). Hence, the button shall be connected to a digital pin (number 0, for example). Expanding on the previous example, we could write:

```
#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

void setup() {
  pinMode(0, INPUT); // configuring digital pin 0 as an input
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  if (digitalRead(0)) { // button is pressed
    myDsp.setGain(1);
  }
  else {
    myDsp.setGain(0);
  }
  int sensorValue = analogRead(A0);
  float freq = sensorValue + 100;
  myDsp.setFreq(freq);
}
```

(Assuming that a `setGain` method has been implemented, which is not the case in the previous example. It shouldn't be too hard though ;) )

### Exercise: Looping Between Notes by Pressing a Button

Expand the "note looper" that [you implemented as part of lecture 3](lecture3.md/#looping-through-a-small-tune) so that new notes are triggered when a button is pressed (as opposed to be triggered automatically). Every time the button is pressed, a new note is produced. This means that you'll have to turn your push button into a switch using software techniques... Finally, make sure that gain is controllable using a rotary potentiometer.

**Solution:**

In `crazy-sine.ino`:

```
#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

float mtof(float note){
  return pow(2.0,(note-69.0)/12.0)*440.0;
}

int tune[] = {62,78,65,67,69};
int cnt = 0;

bool change = true;
bool on = false;

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  pinMode(0, INPUT);
}

void loop() {
  if (digitalRead(0)) { // button is pressed
    if(!on) change = true;
    on = true;
  }
  else {
    if(on) change = true;
    on = false;
  }

  if(change){ // if the status of the button changed
    if(on){ // if the button is pressed
      myDsp.setFreq(mtof(tune[cnt]));
      cnt = (cnt+1)%5;
    }
    change = false; // status changed
  }
}
```

## Audio Codec Configuration

## Audio Codec

An audio codec is a hardware component providing an ADC and a DAC for audio purposes. Hence, it typically has analog audio inputs and outputs (stereo, in general) and digital audio inputs and outputs. Most audio codecs support standard audio sampling rate (i.e., 44.1, 48kHz, etc.) and bit depth (i.e., 16, 24 bits, etc.). Some high-end audio codecs also support higher sampling rates (e.g., 96, 192 kHz, etc.) and bit depth (32 bits, mostly) as well as more than a stereo interface (e.g., 4x4, 8x8, etc.). The price range of audio codecs can vary significantly impacting the quality of the components, i.e., audio is usually extremely sensitive to the quality of the hardware components of a system. 

Audio codecs usually use two different communication channels to connect to the processor unit (whether it's a CPU, a microcontroller, etc.):

* an [i2c](https://en.wikipedia.org/wiki/I%C2%B2C) bus is used to configure the codec,
* an [i2s](https://en.wikipedia.org/wiki/I%C2%B2S) bus is used to transmit digital audio data.

i2c (pronounced I-squared-C) is a serial communication protocol heavily used in the field of microelectronics. Most digital elements in an electronic circuit communicate using i2c. 

i2s (pronounced I-squared-S) is also a serial communication protocol but targeting specifically audio applications. We'll see that they're very close to each other in practice later in this class.

The [Teensy Audio Shield](https://www.pjrc.com/store/teensy3_audio.html) hosts an audio codec (SGTL5000) which is connected to the Teensy using the following model:

<figure>
<img src="img/hardware.jpg" class="mx-auto d-block" width="80%">
<figcaption><center>Interfacing of a microcontroller with an audio codec.</center></figcaption>
</figure>

You can check the Teensy audio shield connection map in the [Teensy Pinout](#teensy-40-pinout) section for more details on how the audio shield is actually connected to the Teensy.

Before audio data can be streamed to the audio codec through i2s, it needs to be configured with an audio driver which basically just sends a set of instructions from the microcontroller to the codec using i2c. The goal of this lecture is to get a basic understanding of how audio drivers work in the context of embedded systems.

## Quick Tour of the SGTL5000

The SGTL5000 is a low-power 24-bit, 8 kHz to 96 kHz audio codec. Its data sheet can be found on the [course repository](https://github.com/grame-cncm/embaudio20/raw/master/pdfs/SGTL5000.pdf) (feel free to download it now because you'll extensively need it later in this lecture). On the first page of the data sheet, you will find a block diagram indicating the different components of the codec:

<figure>
<img src="img/sgtl5000Diag.jpg" class="mx-auto d-block" width="100%">
<figcaption><center>Block diagram of the SGTL5000</center></figcaption>
</figure>

As you can see, the SGTL5000 hosts a stereo ADC and DAC. The codec has a stereo line input and a mono mic input (both accessible through solderable pins on the audio shield). The difference between the two is that the line input goes straight to the ADC while the mic input goes through a preamp first. The gain of the preamp can be adjusted independently from that of the line input. A similar pattern is used for the outputs and the DAC which are available as line outputs (through solderable pins on the audio shield) or amplified outputs (through the headphone jack on the audio shield).

Finally, the codec also has a digital interface which is used for i2c (depicted at the bottom of the block diagram) and i2s (depicted on the left side of the block diagram) communication.

## Configuring an Audio Codec

All audio codecs work the same way and are configured through their i2c bus. A system of register/value is used for that. A register corresponds to a set of parameters and a 16 bits value can be provided to configure them.

A list of all available registers of the SGTL5000 can be seen on page 31-59 of the [data sheet](https://github.com/grame-cncm/embaudio20/raw/master/pdfs/SGTL5000.pdf). Have a quick look at it! For example, register 0x0010 (which is documented on p. 36) allows us to configure the DAC left and right channel volume in dB. Hence setting that register to the `3C3C` (0011110000111100 binary value) will set the volume to 0dB on both channels. If you're hex/binary is a bit rusty, you can use this tool: <https://www.rapidtables.com/convert/number/hex-to-binary.html> to carry out the conversion.

## Audio Codec Driver

Writing an audio codec driver consists of sending the right sequence of register/value through i2c to the codec. This will set the signal routing, the i2s format, the sampling rate, the bit depth, etc. 

[`control_sgtl5000.cpp`](https://github.com/PaulStoffregen/Audio/blob/master/control_sgtl5000.cpp) of the Teensy Audio Library implements a driver for the SGTL5000 codec. The `write` method can be used to set a register and its corresponding 16-bit value. Note that the Arduino `Wire` library is used for that. The `enable` method sets a bunch of register values to provide a basic working configuration to the codec in the context of the Teensy. A bunch of methods are implemented to set high-level parameters of the codec, such as `volume`, `micGain`, `lineInLevel`, etc. Note that a bunch of macros are defined at the beginning for various registers (which constitutes a potential alternative to the codec datasheet, etc.).

In most cases, calling:

```
AudioControlSGTL5000 audioShield;
audioShield.enable();
```

in the `.ino` file will be sufficient to get the audio codec going and send it i2s data.

Since the `write` method of `AudioControlSGTL5000` is protected, it cannot be called outside of the class. Hence, to write custom methods to configure the codec and which are not currently available in `AudioControlSGTL5000`, one would have to write a custom version of [`control_sgtl5000.cpp`](https://github.com/PaulStoffregen/Audio/blob/master/control_sgtl5000.cpp).

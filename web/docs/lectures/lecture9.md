# Lecture 9: Some other usefull things to know

This page gathered information that are useful to many of you (but not all of you probably), depending on the topic of your project. Many of your realization are prototyped in existing examples in the arduino IDE.

## Playing WAV file on the teensy with the SD-card
If you want to play sound file, two possibilities:

1. Use the USB-IN to stream audio from the computer (explained after) but you have no control on the file streamed from the teensy
2. Store WAV files on the SD-Card and read them with the `AudioPlaySdWav` object.

An example explaining how to use the SD-card reader  can be found in `file -> examples -> Audio ->> WaveFilePlayer` 

Be careful to use the WAV file provided by teensy (https://www.pjrc.com/teensy/td_libs_AudioDataFiles.html) because some arbitraty WAV file may be not compatible with the on the AudioPlaySdWav player.

## Streaming Sound from through USB
TODO

## microphone: how to solder it
If your microphone has no JACK input port, you have to solder it. Microphone are stereo but the teensy input microphone is mono. The soldering of the JACK microphone is quite touchy. please get in touch with Teachers.
TODO

## Using line in instead of microphone
For some usage, for a guitar pedal effect for instance, the microphone (which is amplified) might be to sensitive for a "Line" signal such as the one getting out of a guitar. In reducing the microphone gain is not sufficient to eliminate saturation, you can use the "Line IN" port (port printed out below the audio shield) to solder another JACK adaptor.



## Use a MIDI keayboard or controller
Many of you will want to use a midi controler (midi keyboard for instance) to control the teensy. A very simple way to do that is to use a *virtual midi keyboard* that will emulate a MIDI keybard on you computer and send midi signal to the teensy through the MIDI-USB interface.

1. A very common virtual MIDI keyboard is vmpk (https://vmpk.sourceforge.io/), it works on Linux, Windows and Mac.

2. In the arduino IDE, you will have to configure the USB-Type: `tools -> USB-type -> "MIDI+Serial"`

3. There are many MIDI-USB example in the IDE, you can start with `Files -> Examples -> Teensy -> USB_MIDI -> InputFunctionBasic`

4. Once the program running in the Teensy, you can launch the virtual keyboard  and select `Edit -> MIDI Connexions ->  ouptut port connexions -> Teensy MIDI`

5. Be aware that, on some systems, you will have to restart the virtual keyboard *each time* you reprogram the Teensy.

## Midi controller through the PC, not directly.
Once you have debugged your program with the virtual keyboard, you can plug a real (physical) MIDI keyboard to your computer and use your computer to transmit MIDI signal to the teensy with MIDI-USB. 

## Note Frequency identification
Many application will require to identify the fundamental frequency of a sound (i.e. the note of the sound). There are many ways to do that, one can use a FFT and identify the note on the spectrum. However, as we will see below, FFT is quite a heavy computationnal program and it is complicated to set-up.

A simple way to do that in C++ is to use the `Note Frequency` example in the arduino IDE (`File -> Examples -> Audio -> Analysis -> NoteFrequency`)

### FAUST `ef.transpose()` function.
The ef.transpose function is often useful, however, it uses too much memory to run on the teensy. You can still use this function but you have to

1. copy the code of the transpose function (in the library github site, `misceffect.lib` file) in your faust program

2. modify the line `maxDelay = 65536;` to `maxDelay = 1024`

3. Change `ef.transpose` by `transpose`

4. Set the first parameter of `transpose` to 1000.

Then you should be able to export your program to Tennsy.

### FFT or not FFT
The Fourier transform is a powerful tool for many audio effect. However FFT is quite heavy computationnaly and difficult to set up so one must be aware that it will take some time to setup.

FFT in Faust in **not working**. There is a FFT Faust program but it is called at each sample which is unrealistic (i.e. uses to much computing power).

There is a  `AudioAnalyzeFFT1024` object in the teensy Audio library that  Compute a 1024 point Fast Fourier Transform  frequency analysis, with real value output. It is mainly used for spectral visualization. The example `File -> Examples -> Audio -> Analysis -> FFT` can be easily adapted to analyze the spectrum of the sound comming from the microphone (by default, it uses the line input).

However, this object should be used in the loop of the `.ino` file. it will be too heavy to be used in the update function. Another point is that there is no example with a inverse FFT, there existe an inverse FFT function, but it cannor really by used to reconstruct the signal because it is not precise enough.

Hence, at that point, FFT can be used for visualisation but not really to perform frequency domain sound transformations.


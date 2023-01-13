# AUD Course Teensy Examples

This folder contains example programs written in "pure" C++ implementing real-time audio DSP systems for the Teensy 4.+ equipped with a Teensy audio shield.

## Installing

The `libraries` folder contains a simple DSP library (`mydsp`) that should be placed in your Arduino `libraries` folder (typically) in `/home/you/Arduino/libraries/mydsp`.

The `projects` folder contains Arduino projects that should be opened directly from your Arduino IDE. 

## Running

After installing the `mydsp` library, open one of the projects with the Arduino IDE and compile/run it on your Teensy.

## Using Makefiles Instead of the Arduino IDE

This is a work in progress!

First, you wanna clone the Teensy core repo on your system: <https://github.com/PaulStoffregen/cores>

Then, you wanna navigate to `cores/teensy4` and just run `make`...

The main target file is `main.cpp`. It should all work pretty smoothly, the main difficulty is that in order to use this system to compile the aforementioned examples, lots of dependencies must be resolved. Hence, some work remains to be done to take those into account in the MakeFile (i.e., adding `#include <Audio.h>` in `main.cpp` produces a lot of errors, etc.). 

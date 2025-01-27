# Final Projects

Final projects constitute the heart of this course: students are 100% evaluated on projects. While you should feel free to use any of the code studied during class, found on the web, or generated using tools such as [Faust](https://faust.grame.fr), the following criterion should be taken into account:

* Doing what you were asked to do is good, but doing more is better :);
* Novelty, creativity, and initiatives are crucial: consider your project as a potential startup idea, think about how it can be better than what already exists. Along the same lines, try to have a "product" as finished and as polished as possible;
* Consider the research and scientific aspect of what you're doing: most project ideas will involve some bibliographical work before getting your hands dirty, this will help you get a sense of what has already been done by others and it will save you time when readying your poster.

## Evaluation

Projects will be evaluated through:

* A poster (pdf) presenting your project;
* Your code submitted on Moodle;
* A demo of your project which will be featured during a demo session taking place on 28/02/2025. During this session, students will use the poster of their project directly on their computer as a support for providing additional information to the "public" (i.e., the other students and the instructors/evaluators).

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

Auto-tune (<https://en.wikipedia.org/wiki/Auto-Tune>) is a sound effect which automatically corrects the pitch of a sound by quantizing it to the nearest note of the chromatic scale. The goal of this project is to make an "autotune box/audio processor" based on the Teensy. In addition to figuring out how to implement the algorithm (which should involve pitch shifting and frequency tracking), you should think about the interface that your project will have (which parameters can be controlled?, etc.).

### Vocoder

A Vocoder <https://en.wikipedia.org/wiki/Vocoder> is an audio effect which replaces the natural sound of human voice with an artificial/synthesized one by preserving intelligibility of speech. It can be used to create a "robot/ghost voice." The goal of this project is to make a "vocoder box/audio processor" based on the Teensy. In addition to figuring out how to implement the algorithm (which should involve pitch shifting and frequency tracking), you should think about the interface that your project will have (which parameters can be controlled?, etc.).

### Pitch-Shifting Module

Pitch-Shifting consists in transposing (up or down) the sound of an input source so that it sounds lower or higher. Pitch shifting can potentially be implemented using 2 different techniques: (i) using an FFT to transpose the spectrum and then an inverse FFT to put it back in the time domain, (ii) using the doppler effect produced by changing the length of delay lines in real-time. Hence, the goal of this project is to make a "pitch shifting box/audio processor" based on the Teensy. In addition to figuring out how to implement the algorithm (which should involve pitch shifting and frequency tracking), you should think about the interface that your project will have (which parameters can be controlled?, etc.).

### Hearing Aid

At the most fundamental level, hearing aids just implement a bunch of equalization filters (see [Peak Equalizers](lectures/lecture7.md#peak-equalizers)) increasing the volume of some bands in the spectrum of a sound (the ones that an individual can't hear well anymore). The goal of this project is to implement an hearing aid prototype based on the Teensy. If time allows it, you should try to measure the audiogram of someone with hearing loss to test your system in a real-world context.

### Cochlear Implant Simulator

Cochlear implants (<https://en.wikipedia.org/wiki/Cochlear_implant>) allow many people who were condemned to be deaf their entire life to now hear some sound and even speech if they're well trained. This paper: <https://embaudio.grame.fr/cochlear.pdf> describes precisely how a cochlear implant simulator can be implemented using DSP. The goal of this project is to create a sound processing box simulating the sound of a cochlear implant. For that, you will probably need some of the filters described [here](lectures/lecture7.md#making-resonant-lowpass-bandpass-and-highpass).

### Sonification System

Data sonification is a trending method for analyzing data in real-time. The brain stethoscope (<https://youtu.be/pnGzVW_7cfM>) is a good example of that. Choose a sensor technology and develop a sonification technology around it.

### Superman Hearing

Try to make your own version of Facebook's "superman hearing" system (<https://about.fb.com/news/2020/09/facebook-reality-labs-research-future-of-audio/>).

### Guitar Pedal Effect

There exist dozens of guitar pedal effects: <https://en.wikipedia.org/wiki/Effects_unit>. The goal of this project is to make a guitar pedal "stompbox." Don't forget to think about the interface and the shape of the final product.

### Sound Synthesis Module

Modular synthesizers (<https://en.wikipedia.org/wiki/Modular_synthesizer>) became very popular in recent years. Each hardware module implements and sound synthesis or processing technique and offers an interface made of buttons, knobs, etc. The goal of this project is to implement your own sound synthesis module based on a Teensy. If you own a modular synth yourself, think about how your module could integrate to your toolchain, etc.

### EP (Vinyl) Simulator

Love the sound of EPs (<https://en.wikipedia.org/wiki/Extended_play>)? Implement a system that plugs to your living room sound system and makes the sound of any device you plug to it sound like an EP. For that, you will first have to document yourself on the impact on sound of this analog technology. There exists a couple of scientific papers that describe this fairly well. Make sure that you think about the interface that your system will have and about the form that your final product will take, etc.

### Feedback Cancellation Microphone

Feedback happens when a microphone and speaker implement a feedback loop. This results in a very annoying sound which sound engineers try to avoid as much as possible during concerts. Try to make a microphone carrying out real-time audio DSP to limit feedback. There exist many scientific papers on this topic which means that you will first have to document yourself on this topic.

### Augmented Speaker

Make a speaker processing its audio input in real time to add audio effects, improve the quality of sound, etc. The goal of this project is to focus more on the product design aspect to try to design an appealing object. Think about the interface that system could have (maybe accessible through a smartphone? Etc.).

### Musical Instrument

The goal of this project is to make musical instrument based on a Teensy. The domain of New Interfaces for Musical Expression (NIME): <https://www.nime.org/> has been booming in recent years and hundreds of musical instruments have been created. Feel free to get more inspiration here: <https://ccrma.stanford.edu/courses/250a-spring-2023>!

### MIDI-Controlled Polyphonic Synthesizer

Build a polyphonic (multiple notes can be played at the same time) synthesizer based on a USB MIDI keyboard (using the [Teensy USB MIDI Library](https://www.pjrc.com/teensy/td_midi.html)). The keyboard should connect directly to the Teensy through the USB port. The synth should have multiple parameters to control through MIDI CCs. For this project, you'll have to find a way to externally power your Teensy since the USB port will be used for connecting the MIDI keyboard, etc.

### Granular Synthesizer

Granular synthesis <https://en.wikipedia.org/wiki/Granular_synthesis> consists in looping a short sound sample to generate sound textures with it. The goal of this project is to make a granular synthesis module based on a Teensy. You should think about the interface that your system will have (i.e., which parameter to control, etc.). Note that since you will have to record audio samples on the Teensy, you will likely have to use an SD card for this because of the limited amount of memory available on the Teensy.

### DAFx

DAFx is THE conference on digital audio effects: <https://www.dafx.de/>. The goal of this project is to pickup any paper in the DAFx literature and implement it on the Teensy.

### Any Other Idea...

Feel free to work on anything else but talk to us first :).



# SON: 3TC Audio Project @ INSA Lyon

In this project, students program an embedded system (the Teensy 4.0: <https://www.pjrc.com/store/teensy40.html>) for real-time audio signal processing applications. By doing so, they learn the basics of audio software architecture, audio signal processing in C++, and embedded system programming (C++). The idea is also to encourage students to develop a sense of independent work/entrepreneurship.

The 2 weeks project period starts with a workshop on embedded real-time audio signal processing. During this workshop, students are walked through the architecture of a real-time audio DSP system (e.g., audio callback, buffering, sampling, etc.), and learn various basic techniques for audio signal processing (e.g., filters, oscillators, sound synthesis techniques, sound processing techniques, sound analysis techniques, etc.) taking a very practical approach.

After this period, various project ideas are suggested to students. Projects can focus more on DSP or on the "product/hardware" aspect. Students work in groups of 2 on projects.

The project period culminates in a final presentation taking the form of a poster/demo session where each group of students has a booth and can present its project, etc.

Students are provided with plenty of fully-operational starter code/projects so that they have "something that works" right from the beginning.

## Instructors

* [Romain Michon](http://perso.citi-lab.fr/rmichon/) (Inria)
* [Tanguy Risset](http://perso.citi.insa-lyon.fr/trisset/) (INSA Lyon)
* Clemens Wegener (Inria)
* Benjamin Quiédeville (Inria/GRAME)

## Resources

* Course GitHub Repository: <https://github.com/inria-emeraude/son>
* Teensy Audio Library: <https://www.pjrc.com/teensy/td_libs_Audio.html>
* A soldering room (next to radiocom room)
* The SON kit for a group of two students:

<center>
<img src="img/son-kit.jpg"  width="70%">
</p><figcaption>A pair of headphones, one Teensy 4.0 with its companion audio shield, two buttons, two potentiometers, one breadboard, and a couple of resistors and jumper cables (do not loose these components!).
</figcaption>
</center>

## Requirements

* Installing Teensyduino as explained in [Lecture 1](lectures/setup.md).

## Course Overview

* **Lecture 1: [Course Introduction and Programming Environment Setup](lectures/setup.md)** -- *02/02/2026 08h00-10h00*
* **Lecture 2: [Audio Signal Processing Fundamentals](lectures/audio-dsp.md)**  -- *02/02/2026 14h00-16h00*
* **Lecture 3: [Digital Audio Systems Architectures and Audio Callback](lectures/audio-sys.md)** -- *02/02/2026 16h00-18h00* 
* **Lecture 4: [Hardware Control and Audio Codec Configuration](lectures/control.md)** -- *04/02/2026 08h00-10h00*
* **Lecture 5: [Introduction to Faust](lectures/faust.md)** -- *04/02/2026 10h00-12h00*
* **Lecture 6: [Audio Processing Basics I](lectures/dsp1.md)** -- *05/02/2026 08h00-10h00* 
* **Lab** -- *05/02/2026 10h00-12h00*
* **Lecture 7: [Audio Processing Basics II](lectures/dsp2.md)** -- *06/02/2026 08h00-10h00*
* **Lecture 8: [Faust on the Teensy and Advanced Control](lectures/faust-teensy.md)** -- *06/02/2026 10h00-12h00*
* **Project Validation Session** -- *06/02/2026 16h00-18h00*
* **[Some Other Useful Things to Know](lectures/useful.md)**
* **Independent work on Projects** -- *09/02/2026 - 27/02/2026*

| | G1 | G2 | G3 | G4 |
|---|---|---|---|---|
| **TP1** | 09/02/2026 -- 08h00-10h00 -- TD C | 09/02/2026 -- 08h00-10h00 -- TD D | 09/02/2026 -- 08h00-10h00 -- TD E | 09/02/2026 -- 08h00-10h00 -- TD F |
| **TP2** | 09/02/2026 -- 14h00-16h00 -- TD E | 09/02/2026 -- 14h00-16h00 -- TD C | 09/02/2026 -- 14h00-16h00 -- TD D | 09/02/2026 -- 14h00-16h00 -- TD F |
| **TP3** | 09/02/2026 -- 16h00-18h00 -- TD E | 09/02/2026 -- 16h00-18h00 -- TD C | 09/02/2026 -- 16h00-18h00 -- TD D | 09/02/2026 -- 16h00-18h00 -- TD F |
| **TP4** | 11/02/2026 -- 08h00-10h00 -- TD E | 11/02/2026 -- 08h00-10h00 -- TD C | 11/02/2026 -- 08h00-10h00 -- TD D | 11/02/2026 -- 08h00-10h00 -- TD F |
| **TP5** | 11/02/2026 -- 10h00-12h00 -- TD E | 11/02/2026 -- 10h00-12h00 -- TD C | 11/02/2026 -- 10h00-12h00 -- TD D | 11/02/2026 -- 10h00-12h00 -- TD F |
| **TP6** | 11/02/2026 -- 14h00-16h00 -- TD C | 11/02/2026 -- 14h00-16h00 -- TD D | 11/02/2026 -- 14h00-16h00 -- TD F | 11/02/2026 -- 14h00-16h00 -- TD E |
| **TP7** | 11/02/2026 -- 16h00-18h00 -- TD C | 11/02/2026 -- 16h00-18h00 -- TD D | 11/02/2026 -- 16h00-18h00 -- TD F | 11/02/2026 -- 16h00-18h00 -- TD E |
| **TP8** | 12/02/2026 -- 08h00-10h00 -- TD F | 12/02/2026 -- 08h00-10h00 -- TD E | 12/02/2026 -- 08h00-10h00 -- TD D | 12/02/2026 -- 08h00-10h00 -- TD C |
| **TP9** | 13/02/2026 -- 08h00-10h00 -- TD C | 13/02/2026 -- 08h00-10h00 -- TD F | 13/02/2026 -- 08h00-10h00 -- TD E | 13/02/2026 -- 08h00-10h00 -- TD D |
| **TP10** | 13/02/2026 -- 10h00-12h00 -- TD C | 13/02/2026 -- 10h00-12h00 -- TD F | 13/02/2026 -- 10h00-12h00 -- TD E | 13/02/2026 -- 10h00-12h00 -- TD D |
| **MLS/TP11** | 13/02/2026 -- 14h00-16h00 -- TD E |  13/02/2026 -- 14h00-16h00 -- TD C |  13/02/2026 -- 14h00-16h00 -- TD D |  13/02/2026 -- 14h00-16h00 -- TD F |
| **MLS/TP12** | 13/02/2026 -- 16h00-18h00 -- TD E | 13/02/2026 -- 16h00-18h00 -- TD C | 13/02/2026 -- 16h00-18h00 -- TD D | 13/02/2026 -- 16h00-18h00 -- TD F |
| **TP13** | 23/02/2026 -- 08h00-10h00 -- TD E | 23/02/2026 -- 08h00-10h00 -- TD D | 23/02/2026 -- 08h00-10h00 -- TD F | 23/02/2026 -- 08h00-10h00 -- TD C |
| **TP14** | 24/02/2026 -- 14h00-16h00 -- TD F | 24/02/2026 -- 14h00-16h00 -- TD C | 24/02/2026 -- 14h00-16h00 -- TD E | 24/02/2026 -- 14h00-16h00 -- TD D |
| **TP15** | 25/02/2026 -- 08h00-10h00 -- TD E | 25/02/2026 -- 08h00-10h00 -- TD C | 25/02/2026 -- 08h00-10h00 -- TP Info C | 25/02/2026 -- 08h00-10h00 -- TD D |
| **TP16** | 25/02/2026 -- 10h00-12h00 -- TD E | 25/02/2026 -- 10h00-12h00 -- TD C | 25/02/2026 -- 10h00-12h00 -- TP Info C | 25/02/2026 -- 10h00-12h00 -- TD D |
| **TP17** | 25/02/2026 -- 14h00-16h00 -- TP Info C | 25/02/2026 -- 14h00-16h00 -- TD E | 25/02/2026 -- 14h00-16h00 -- TD D | 25/02/2026 -- 14h00-16h00 -- TD C |
| **TP18** | 25/02/2026 -- 16h00-18h00 -- TD Info C | 25/02/2026 -- 16h00-18h00 -- TD E | 25/02/2026 -- 16h00-18h00 -- TD D | 25/02/2026 -- 16h00-18h00 -- TD C |
| **TP19** | 26/02/2026 -- 08h00-10h00 -- TD C | 26/02/2026 -- 08h00-10h00 -- TD E | 26/02/2026 -- 08h00-10h00 -- TD D | 26/02/2026 -- 08h00-10h00 -- TP Info C |

* **Final Presentations (G1 + G2)** -- *27/02/2026 08h00-12h00*
* **Final Presentations (G3 + G4)** -- *27/02/2025 14h00-18h00*


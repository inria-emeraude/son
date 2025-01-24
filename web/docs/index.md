# SON: 3TC Audio Project @ INSA Lyon

In this project, students program an embedded system (the Teensy 4.0: <https://www.pjrc.com/store/teensy40.html>) for real-time audio signal processing applications. By doing so, they learn the basics of audio software architecture, audio signal processing in C++, and embedded system programming (C++). The idea is also to encourage students to develop a sense of independent work/entrepreneurship.

The 3 weeks project period starts with a workshop on embedded real-time audio signal processing. During this workshop, students are walked through the architecture of a real-time audio DSP system (e.g., audio callback, buffering, sampling, etc.), and learn various basic techniques for audio signal processing (e.g., filters, oscillators, sound synthesis techniques, sound processing techniques, sound analysis techniques, etc.) taking a very practical approach.

After this period, various project ideas are suggested to students. Projects can focus more on DSP or on the "product/hardware" aspect. Students work in groups of 2 on projects.

The project period culminates in a final presentation taking the form of a poster/demo session where each group of students has a booth and can present his project, etc.

Students are provided with plenty of fully-operational starter code/projects so that they have "something that works" right from the beginning.

## Instructors

* [Romain Michon](http://perso.citi-lab.fr/rmichon/) (Inria)
* [Tanguy Risset](http://perso.citi.insa-lyon.fr/trisset/) (INSA Lyon)
* Thomas Rushton (Inria)
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

* Installing Teensyduino as explained in [Lecture 1](lectures/lecture1.md).

## Course Overview

* **Lecture 1: [Course Introduction and Programming Environment Setup](lectures/lecture1.md)** -- *10/02/2025 14h00-16h00*
* **Lecture 2: [Audio Signal Processing Fundamentals](lectures/lecture2.md)** -- *10/02/2025 16h00-18h00*
* **Lecture 3: [Digital Audio Systems Architectures and Audio Callback](lectures/lecture3.md)** -- *12/02/2025 08h00-10h00*
* **Lab** -- *12/02/2025 10h00-12h00*
* **Lecture 4: [Hardware Control and Audio Codec Configuration](lectures/lecture4.md)** -- *12/02/2025 14h00-16h00*
* **Lecture 5: Introduction to Faust (Yann Orlarey)** -- *12/02/2025 16h00-18h00*
* **Lecture 6: [Audio Processing Basics I](lectures/lecture6.md)** -- *13/02/2025 08h00-10h00*
* **Lab** -- *13/02/2025 10h00-12h00*
* **Lecture 7: [Audio Processing Basics II](lectures/lecture7.md)** -- *14/02/2025 08h00-10h00*
* **Lecture 8: [Faust on the Teensy and Advanced Control](lectures/lecture8.md)** -- *14/02/2025 10h00-12h00*
* **Independent work on Projects** -- *18/02/2025 - 28/02/2025*

| | G1 | G2 | G3 | G4 |
|---|---|---|---|---|
| **TP1** | 18/02/2025 -- 14h00-16h00 -- TD C | 18/02/2025 -- 14h00-16h00 -- TD D | 18/02/2025 -- 14h00-16h00 -- TD E | 18/02/2025 -- 14h00-16h00 -- TD F |
| **TP2** | 19/02/2025 -- 08h00-10h00 -- TD E | 19/02/2025 -- 08h00-10h00 -- TD D | 19/02/2025 -- 08h00-10h00 -- TD C | 19/02/2025 -- 08h00-10h00 -- TD F |
| **TP3** | 19/02/2025 -- 10h00-12h00 -- TD E | 19/02/2025 -- 10h00-12h00 -- TD D | 19/02/2025 -- 10h00-12h00 -- TD C | 19/02/2025 -- 10h00-12h00 -- TD F |
| **TP4** | 19/02/2025 -- 14h00-16h00 -- TD F | 19/02/2025 -- 14h00-16h00 -- TD E | 19/02/2025 -- 14h00-16h00 -- TD D | 19/02/2025 -- 14h00-16h00 -- TD C |
| **TP5** | 19/02/2025 -- 16h00-18h00 -- TD F | 19/02/2025 -- 16h00-18h00 -- TD E | 19/02/2025 -- 16h00-18h00 -- TD D | 16/02/2025 -- 16h00-18h00 -- TD C |
| **TP6** | 20/02/2025 -- 08h00-10h00 -- TD F | 20/02/2025 -- 08h00-10h00 -- TD C | 20/02/2025 -- 08h00-10h00 -- TD D | 20/02/2025 -- 08h00-10h00 -- TD E |
| **TP7** | 20/02/2025 -- 10h00-12h00 -- TD F | 20/02/2025 -- 10h00-12h00 -- TD C | 20/02/2025 -- 10h00-12h00 -- TD D | 20/02/2025 -- 10h00-12h00 -- TD E |
| **TP8** | 21/02/2025 -- 08h00-10h00 -- TD D | 21/02/2025 -- 08h00-10h00 -- TD F | 21/02/2025 -- 08h00-10h00 -- TD E | 21/02/2025 -- 08h00-10h00 -- TD C |
| **TP9** | 21/02/2025 -- 10h00-12h00 -- TD D | 21/02/2025 -- 10h00-12h00 -- TD E | 21/02/2025 -- 10h00-12h00 -- TD F | 21/02/2025 -- 10h00-12h00 -- TD C |
| **TP10** | 21/02/2025 -- 16h00-18h00 -- TD F | 21/02/2025 -- 16h00-18h00 -- TD C | 21/02/2025 -- 16h00-18h00 -- TD D | 21/02/2025 -- 16h00-18h00 -- TD E |
| **MLS/TP11** | 24/02/2025 -- 08h00-10h00 -- TD F | 24/02/2025 -- 08h00-10h00 -- TD C | 24/02/2025 -- 08h00-10h00 -- TD D | 24/02/2025 -- 08h00-10h00 -- TD E |
| **MLS/TP12** | 24/02/2025 -- 16h00-18h00 -- TD C | 24/02/2025 -- 16h00-18h00 -- TD F | 24/02/2025 -- 14h00-16h00 -- TD D | 24/02/2025 -- 10h00-12h00 -- TD E |
| **TP13** | 25/02/2025 -- 14h00-16h00 -- TD D | 25/02/2025 -- 14h00-16h00 -- TD C | 25/02/2025 -- 14h00-16h00 -- TD E | 24/02/2025 -- 14h00-16h00 -- TD E |
| **TP14** | 26/02/2025 -- 08h00-10h00 -- TD E | 26/02/2025 -- 08h00-10h00 -- TD D | 26/02/2025 -- 08h00-10h00 -- TD C | 26/02/2025 -- 08h00-10h00 -- TD F |
| **TP15** | 26/02/2025 -- 10h00-12h00 -- TD E | 26/02/2025 -- 10h00-12h00 -- TD D | 26/02/2025 -- 10h00-12h00 -- TD C | 26/02/2025 -- 10h00-12h00 -- TD F |
| **TP16** | 26/02/2025 -- 14h00-16h00 -- TD D | 26/02/2025 -- 14h00-16h00 -- TD C | 26/02/2025 -- 14h00-16h00 -- TD F | 26/02/2025 -- 14h00-16h00 -- TD E |
| **TP17** | 26/02/2025 -- 14h00-16h00 -- TD D | 26/02/2025 -- 14h00-16h00 -- TD C | 26/02/2025 -- 14h00-16h00 -- TD F | 26/02/2025 -- 14h00-16h00 -- TD E |
| **TP18** | 26/02/2025 -- 16h00-18h00 -- TD D | 26/02/2025 -- 16h00-18h00 -- TD F | 26/02/2025 -- 16h00-18h00 -- TD E | 26/02/2025 -- 16h00-18h00 -- TD C |
| **TP19** | 27/02/2025 -- 08h00-10h00 -- TD F | 27/02/2025 -- 08h00-10h00 -- TD C | 27/02/2025 -- 08h00-10h00 -- TD E | 27/02/2025 -- 08h00-10h00 -- TD D |


* **Final Presentations (G1 + G2)** -- *28/02/2025 08h00-12h00*
* **Final Presentations (G3 + G4)** -- *28/02/2025 14h00-18h00*


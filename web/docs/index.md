# SON 2027: 3TC Audio Project @ INSA Lyon 

In this project, students program an embedded system (the Teensy 4.0: <https://www.pjrc.com/store/teensy40.html>) for real-time audio signal processing applications. By doing so, they learn the basics of audio software architecture, audio signal processing in C++, and embedded system programming (C++). The idea is also to encourage students to develop a sense of independent work/entrepreneurship. The course was originally created by  [Romain Michon](http://perso.citi-lab.fr/rmichon/) in 2023. In 2027 Romain Michon will be mooving to U. Saint-\'Etienne, Tanguy Risset will be the course responsible.

The 3 weeks project period starts with a workshop on embedded real-time audio signal processing. During this workshop, students are walked through the architecture of a real-time audio DSP system (e.g., audio callback, buffering, sampling, etc.), and learn various basic techniques for audio signal processing (e.g., filters, oscillators, sound synthesis techniques, sound processing techniques, sound analysis techniques, etc.) taking a very practical approach.

After this period, various project ideas are suggested to students and a 2 weeks project will start. Students work *in groups of 2* on projects. Projects can focus more on DSP or on the "product/hardware" aspect. 

The project period culminates in a final presentation taking the form of a poster/demo session where each group of students has a booth and can present its project, etc.

Students are provided with plenty of fully-operational starter code/projects so that they have "something that works" right from the beginning.

## Instructors 
(mail contact: firstname.lastname@insa-lyon.fr)

* [Tanguy Risset](http://perso.citi.insa-lyon.fr/trisset/) (INSA Lyon, )
* Alexandre Bento (INSA Lyon)
* Clemens Wegener (Inria)
* Benjamin Quiédeville (GRAME)
* Guest star: [Romain Michon](http://perso.citi-lab.fr/rmichon/) (U. Saint-Etienne) creator of the SON course

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

* **Lecture 1: [Course Introduction and Programming Environment Setup](lectures/setup.md)** -- *02/02/2027 14h00-16h00*
* **Lecture 2: [Audio Signal Processing Fundamentals](lectures/audio-dsp.md)**  -- *03/02/2027 :08h00-10h00*
* **Lecture 3: [Digital Audio Systems Architectures and Audio Callback](lectures/audio-sys.md)** -- *03/02/2027 10h00-12h00* 
* **Lecture 4: [Hardware Control and Audio Codec Configuration](lectures/control.md)** -- *04/02/2027 08h00-10h00*
* **Lecture 5: [Audio Processing Basics I](lectures/dsp1.md)** -- *04/02/2027 10h00-12h00* 
* **Lecture 6: [Audio Processing Basics II](lectures/dsp2.md)** -- *05/02/2027 08h00-10h00*
* Lecture 7 **Lab** ending exercices in Claude Chappe -- *05/02/2027 10h00-12h00*
* **Lecture 8: **  Lab: ending all exercices in TD Rooms -- *08/02/2027 08h00-10h00*
* **Lecture 9**: [Introduction to Faust](lectures/faust.md) and [Faust on the Teensy and Advanced Control](lectures/faust-teensy.md)** -- *08/02/2027 14h00-16h00*
*  **Lecture 9** **Project Validation Session** -- *08/02/2027 16h00-18h00*
* **[Some Other Useful Things to Know](lectures/useful.md)**
* **Independent work on Projects** -- *09/02/2027 - 19/02/2027*

| | G1 | G2 | G3 | G4 |
|---|---|---|---|---|
| **TP0** | 10/02/2027 -- 08h00-12h00 -- TD C | 09/02/2027 -- 08h00-12h00 -- TD D | 10/02/2027 -- 08h00-12h00 -- TD E | 10/02/2027 -- 08h00-12h00 -- TD F |
| **TP1** | 10/02/2027 -- 14h00-16h00 -- TD E | 10/02/2027 -- 14h00-16h00 -- TD C | 10/02/2027 -- 14h00-16h00 -- TD D | 10/02/2027 -- 14h00-16h00 -- TD F |
| **TP2** | 11/02/2027 -- 08h00-12h00 -- TD E | 09/02/2027 -- 08h00-12h00 -- TD C | 09/02/2027 -- 08h00-12h00 -- TD D | 09/02/2027 -- 08h00-12h00 -- TD F |
| **TP3** | 12/02/2027 -- 08h00-12h00 -- TD E | 12/02/2027 -- 08h00-12h00 -- TD C | 12/02/2027 -- 08h00-12h00 -- TD D | 12/02/2027 -- 08h00-12h00 -- TD F |

---
| | G1 | G2 | G3 | G4 |
|---|---|---|---|---|
| **MLS** | 12/02/2027 -- 14h00-15h00 -- TD C | 12/02/2027 -- 15h00-16h00 -- TD C | 12/02/2027 -- 16h00-17h00 -- TD D | 12/02/2027 -- 17h00-18h00 -- TD F |

| | G1 | G2 | G3 | G4 |
|---|---|---|---|---|
| **TP5** | 16/02/2027 -- 14h00-18h00 -- TD C | 16/02/2027 -- 14h00-18h00 -- TD D | 16/02/2027 -- 14h00-18h00 -- TD F | 15/02/2027 -- 08h00-12h00 -- TD E |
| **TP6** | 17/02/2027 -- 08h00-12h00 -- TD C | 17/02/2027 -- 08h00-12h00 -- TD D | 17/02/2027 -- 08h00-12h00 -- TD F | 17/02/2027 -- 08h00-12h00 -- TD E |
| **TP7** | 17/02/2027 -- 14h00-18h00 -- TD C | 17/02/2027 -- 14h00-18h00 -- TD D | 17/02/2027 -- 14h00-18h00 -- TD F | 17/02/2027 -- 14h00-18h00 -- TD E |
| **TP8** | 18/02/2027 -- 08h00-12h00 -- TD F | 18/02/2027 -- 08h00-12h00 -- TD E | 18/02/2027 -- 08h00-12h00 -- TD D | 18/02/2027 -- 08h00-12h00 -- TD C |

* **Final Presentations (G3 + G4)** -- *19/02/2027 08h00-12h00*
* **Final Presentations (G1 + G2)** -- *19/02/2025 14h00-18h00*


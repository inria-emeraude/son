# Lecture 10: Embedded Operating Systems

This course will present the important notions of embedded operating systems and show how a primitive operating system (protothreads) can be deployed on teensy.

## Slides

It is (temporarily) available through sildes [here](lecture10/img/cours_2_os.pdf)

## A teensy program with protothreads 
Download the [protothreads_blink.tar](lecture10/img/protothreads_blink.tar) archive and uncompress it. 

Have a look at the ``protothread_blink.ino`` program. This programs defines two protothreads:`thread_red_led` that switch the LED state every  seconds, and `thread_sine` that changes the sine tune every 0.25 seconds. Both these thread are unlock by a dedicated timer. 

Can you understand how it works? 

This example, of course, is a bit trivial because the changes in the LED state and the sine tune could have been done in timer callbacks. But, first,  we try to avoid writing to much code in the call back and, second, one has to imagine other conditions for unlocking the threads such as internal variable states or input on UART... 

 What happens if one ``PT_WAIT_UNTIL`` is commented out? For instance in ``thread_led_ref``:
 
 ``//PT_WAIT_UNTIL(pt, TIMER_LED_RED_ON == 1);``

Note finaly, note that many variables have been set as global variables as local protothread variables are not remanent.


## Add a UART printing 
copy this ``protothreads_blink`` directory to a new ``protothreads_count`` and modify the program to print on UART serial port, every second,   the number of blinking of the LED since the beginning of the program.  This imply the following tasks (see [UART teensy Documentation](https://www.pjrc.com/teensy/td_uart.html)):

- Initialize serial communication at 9600 bauds using `Serial.begin(9600);`
-  Declare a global variable `blink_count`
- Declare a new timer counting each second (up to four interval timers can be used in teensy 4.0)
- Increment `blink_count` at each blink
- Print (using `Serial.print`) the value of `blink_count` in new timer callback.
 
Use the command ``minicom -D /dev/ttyACM0`` to visualize what is send on serial port by the teensy. 

## Control LED and sound with keyboard
copy this ``protothreads_count`` directory to a new ``protothreads_control``

declare a new protothread ``static PT_THREAD(thread_receive(struct pt *pt))` that will receive characters on UART serial port for the host computer. the condition in the `PT_WAIT_UNTIL` will be `Serial.available()>0` (indicating that the receiving buffer contains some characters, see [UART teensy Documentation](https://www.pjrc.com/teensy/td_uart.html)). As soon as a character is typed, echo its ascii code. 

Use that mecanism to control the sound and LED:

- Typing 's' will switch off/on the sound (i.e. setting ``myDsp.setFreq(0)`) 
- Typing 'o' will switch off/on the LED blinking.

Hint: you can switch the value of a variable `var` between 0 and 1 using the Xor operator: `var = var ^ 1;`




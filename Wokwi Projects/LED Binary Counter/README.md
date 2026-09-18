# LED Binary Counter

Very simple circuit and example project to demonstrate GPIO fundamentals on a STM32 Nucleo board simulation.  Uses a pushswitch to increment an internal uint_8t counter by one each press, which is then displayed out to a binary counter of LEDs, for a range of 0-7.  A second pushswitch drives a reset functionality, which resets the internal counter to 0.  Both can only perform their function once per press, keeping the button held will not cause additional triggers.

Very basic project to get back to terms with I/O.  The switches drive 5V to pins D2 and D4, which are recorded by a digitalRead(...) each frame in the loop.  When pressed, we use a previous value lock to make sure we aren't processing events more than one time, then on HIGH read, increment or reset the counter respectively, and then change the LED ouputs.  LEDs are driven by pins D8-10, with a 220ohm resistor to make sure we don't fry an LED unintentiionally.  Overall a very basic design, but its good to start with the fundamentals.

Circuit diagram is included below:
![Circuit Diagram](Wokwi Projects\LED Binary Counter\assets\LEDCounterDiagram.png)
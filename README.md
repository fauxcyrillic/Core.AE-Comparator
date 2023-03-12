# Core.AE-Comparator

Multi-mode signal comparator for Wonkystuff Core.ae module
https://wonkystuff.net/product/core1-ae-v1-2-black/
---

Upload using the WAV file as detailed in the programming instructions: https://wonkystuff.net/programming-core1/

**Usage**
(Set all pots counter-clockwise)

Send a signal into CV-B
Optional second signal into CV-C
CV-D is the comparison voltage, can be determined via CV-in or manually using pot D

Pot A - mode switch
- counter clockwise: 1 comparator (signal in B) vs. reference (D)

  while signal > reference: m-c is HIGH, output s-c is LOW, and vice versa.
  
- clockwise: 2 independent comparators (signals in B & C) vs. 1 reference (still D)

  m-c HIGH when signal B-in > reference, s-c HIGH when signal C-in > reference.

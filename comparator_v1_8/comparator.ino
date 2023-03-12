/* 
 v1.8 comparator now with switchable modes!
 (with thanks to pt3r for introducing the concept)
 ------------------------------------------------
 Set all pots fully counter-clockwise to begin.
 Input CV-B is your first signal.
 Input CV-C is an optional second signal.
 You can set the reference voltage either manually with pot D 
 or by sending a CV into that input.

 Position of pot A determines the mode:

 A = counter clockwise: 1 comparator (signal in B) vs. reference (D),
 m-c is triggered while signal > reference, output s-c is inverted.

 A = clockwise: 2 comparators (signals in B & C) vs. 1 reference (still D),
 m-c triggered when B-in > reference, s-c when C-in > reference,
 no inverted output in this mode.

 Try using the m-a and s-a outputs for a slightly slewed output.
*/

uint16_t mode;

void setup() {
  // initialise the pins
  pinMode(A0, INPUT); // A input, we'll use this to switch modes
  pinMode(A1, INPUT); // B (signal 1)
  pinMode(A2, INPUT); // D (reference voltage)
  pinMode(A3, INPUT); // C (signal 2)
  pinMode(PB1, OUTPUT); // m out
  pinMode(PB0, OUTPUT); // s out
  digitalWrite(0, LOW); 
  digitalWrite(1, LOW); 
}


void loop() {
  // get the value of our 'mode' position
  uint16_t sig1V = analogRead(A1) | 0x0003;
  uint16_t refV = analogRead(A2) | 0x0003;
  uint16_t sig2V = analogRead(A3) | 0x0003;
  mode = analogRead(A0);
  
  if (mode <= 768) // A is CCW
  {
    sig2V = 0; // not using this input
    // compare one signal against reference voltage
    if (sig1V > refV)
    {
      digitalWrite(1, HIGH); // main output
      digitalWrite(0, LOW); // 2nd output is inverted
    }
    else
    {
      digitalWrite(1, LOW);
      digitalWrite(0, HIGH);
    }
  }
   else // A is CW
   {    
    if (sig1V > refV) // set status of m-c output
    {
      digitalWrite(1, HIGH);
    }
    else 
    {
      digitalWrite(1, LOW);
    }
    if (sig2V > refV) // set status of s-c output
    {
      digitalWrite(0, HIGH);
    }
    else
    {
      digitalWrite(0, LOW);
    }
   }
}

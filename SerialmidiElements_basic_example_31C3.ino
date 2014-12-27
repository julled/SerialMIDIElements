// SerialMIDIElements template for 31C3 Workshop
// by Julian Dorner
// petrosilius@posteo.de

#include <SerialMIDIElements.h>

boolean debug       = false;     // print to serial instead of midi
boolean secondary   = false;     // disabled secondary midi messages
int     midiChannel = 1;         // midi channel number

// setup a button on Arduino-pin 2 on for ControlChange 1
Button        but1(2,    midiChannel,1,secondary,debug); 
// setup a button on Arduino-pin 3 on for ControlChange 2
Button        but2(3,    midiChannel,2,secondary,debug); 
// setup a button on Arduino-pin 4 on for ControlChange 3
Button        but3(4,    midiChannel,3,secondary,debug); 
// setup a button on Arduino-pin 5 on for ControlChange 4
Button        but4(5,    midiChannel,4,secondary,debug);

// setup a Encoder on Arduino-pin 6 and 7 for ControlChange 11
MIDIEncoder   enc1(6,7,  midiChannel,11,secondary, debug);
// setup an encoder on Arduino-pins 8 and 9 for ControlChange 12
MIDIEncoder   enc2(8,9,  midiChannel,12,secondary, debug);

// setup a Potentiometer on Arduino-pin analog0 on for ControlChange 21
Potentiometer pot1(A0,   midiChannel,21,secondary,debug);
// setup a Potentiometer on Arduino-pin analog1 on for ControlChange 22
Potentiometer pot2(A1,   midiChannel,22,secondary,debug);
// setup a Potentiometer on Arduino-pin analog2 on for ControlChange 23
Potentiometer pot3(A3,   midiChannel,23,secondary,debug);
// setup a Potentiometer on Arduino-pin analog3 on for ControlChange 24
Potentiometer pot4(A4,   midiChannel,24,secondary,debug);




void setup(){
  Serial.begin(115200); 
}

void loop(){
  // add here all the input component reads
  but1.read();  
  but2.read();
  but3.read();  
  but4.read();
  
  enc1.read();
  enc2.read();
  
  pot1.read(); // read knob and send midi messages
  pot2.read(); // read knob and send midi messages
  pot3.read(); // read knob and send midi messages
  pot4.read(); // read knob and send midi messages
}

// SerialMIDIElements template for 31C3 Workshop
// by Julian Dorner
// petrosilius@posteo.de
#include <SerialMIDIElements.h>

boolean debug=false;     // print to serial instead of midi
boolean secondary=false; // enable secondary midi messages
int midiChannel=1;       // midi channel number

// setup a button on pin 4 on for CC 1
Button but1(4,midiChannel,1,secondary,debug); 
// setup a Potentiometer on pin A0 on for CC 2
Potentiometer pot1(A0,midiChannel,2,secondary,debug);
// setup a Encoder on pin 2 and 3 for CC 3
MIDIEncoder enc1(2,3,midiChannel,3,secondary, debug); // setup an encoder on pins 2 and 3

void setup(){
  Serial.begin(115200); 
}

void loop(){
  // add here all the input component reads
  pot1.read(); // read knob and send midi messages
  enc1.read();
  but1.read();  
}



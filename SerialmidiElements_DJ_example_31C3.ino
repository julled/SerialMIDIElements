// SerialMIDIElements DJ Example for 31C3 Workshop
// by Julian Dorner
// petrosilius@posteo.de

#include <SerialMIDIElements.h>

boolean debug       = false;     // print to serial instead of midi
boolean secondary   = false;     // disabled secondary midi messages
int     midiChannel = 1;         // midi channel number

// setup Buttons
// setup a button on Arduino-pin 2 on for ControlChange 1
Button        but1(2,    midiChannel,1,secondary,debug); 
Button        but2(3,    midiChannel,2,secondary,debug); 
Button        but3(4,    midiChannel,3,secondary,debug); 
Button        but4(5,    midiChannel,4,secondary,debug);
Button        but5(6,    midiChannel,5,secondary,debug); 
Button        but6(7,    midiChannel,6,secondary,debug); 
Button        but7(8,    midiChannel,7,secondary,debug); 
Button        but8(9,    midiChannel,8,secondary,debug);
// setup Encoderbuttons(Switches)
Button        but9(10,    midiChannel,9,secondary,debug); 
Button        but10(11,   midiChannel,10,secondary,debug);

// setup Encoders
// setup a Encoder on Arduino-pin 12 and 13 for ControlChange 11
MIDIEncoder   enc1(12,13,  midiChannel,11,secondary, debug);
MIDIEncoder   enc2(A0,A1,  midiChannel,12,secondary, debug);
MIDIEncoder   enc3(A2,A3,  midiChannel,13,secondary, debug);

// setup Potentiometers
// setup a Potentiometer on Arduino-pin analog4 on for ControlChange 20
Potentiometer pot1(A4,   midiChannel,20,secondary,debug);
Potentiometer pot2(A5,   midiChannel,21,secondary,debug);
Potentiometer pot3(A6,   midiChannel,22,secondary,debug);
Potentiometer pot4(A7,   midiChannel,23,secondary,debug);


void setup(){
  Serial.begin(115200); 
}

void loop(){
  // add here all the input component reads
  but1.read();  
  but2.read();
  but3.read();  
  but4.read();
  but5.read();  
  but6.read();
  but7.read();  
  but8.read();
  but9.read();  
  but10.read();
  but11.read();  

  enc1.read();
  enc2.read();
  enc3.read();
  
  pot1.read(); // read knob and send midi messages
  pot2.read(); // read knob and send midi messages
  pot3.read(); // read knob and send midi messages
  pot4.read(); // read knob and send midi messages
}

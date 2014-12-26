// MIDI Elements button class
// Library to simplifly handling of compontents for MIDI controllers
// Created by Tomash Ghz
// www.tomashg.com
// ghz.tomash@gmail.com
// 
// Edited 12.2014 by Julian Dorner for a workshop @ 31C3
// Edited for standard Arduinos via Serial-Midi-softwarebridge
// => SerialMIDIElements 
// petrosilius@posteo.de

#include "Button.h"

//-----------------------------------------------------------------------------------
// constructor
Button::Button(byte p){
	Button(p,0,0,false,true);
}

Button::Button(byte p, byte c, byte n){
	Button(p,c,n,false,false);
}

Button::Button(byte p, byte c, byte n, bool sec){
	Button(p,c,n,sec,false);
}

Button::Button(byte p, byte c, byte n, bool sec, bool debug){ // pin, number, channel
	pin=p;
	number=n;
	channel=c;
	secondary=sec;
	debugging=debug;
	velocity=127;
	
	pinMode(pin, INPUT_PULLUP); // enable the pin for input
		
	bButn = new MIDIBounce(pin, 10); // create new bounce object for pin
}

// destructor
Button::~Button(){
	delete bButn;
}

// read
void Button::read(){
	if (bButn->update()) {//state changed

      if (bButn->read()==LOW) {//is pressed
        noteOnOff(true);
      }
      else {
        noteOnOff(false);
      }
    }
}

// read value
bool Button::readValue(bool &changed){
	changed=bButn->update(); //state changed

      if (bButn->read()==LOW) {//is pressed
        return true;
      }
      else {
        return false;
      }
}

// set note on velocity
void Button::setVelocity(byte v){
	velocity=v;
}

//send midinote on off
void Button::noteOnOff(bool v){
  if(v){
    if (debugging) {//debbuging enabled
      Serial.print("Button ");
      Serial.print(number);
      Serial.println(" pressed.");
    }
	else{
		Serial.write(0xB0 | (channel));
		Serial.write(number);
		Serial.write(velocity);
		if(secondary)
		{
			Serial.write(0xB0 | (channel));
			Serial.write(number);
			Serial.write(127);
		}
	}
	/*else{ // send midi note
		usbMIDI.sendNoteOn(number, velocity, channel);
		if(secondary)
			usbMIDI.sendControlChange(number, 127, channel);
	}*/
  }
  else{
	if (debugging) {//debbuging enabled
      Serial.print("Button ");
      Serial.print(number);
      Serial.println(" released.");
    }
	else{
		if(secondary)
		{
			Serial.write(0xB0 | (channel));
			Serial.write(number);
			Serial.write(0);
		}
		Serial.write(0xB0 | (channel));
		Serial.write(number);
		Serial.write(0);		
			/*	if(secondary)
			usbMIDI.sendControlChange(number, 0, channel);
		usbMIDI.sendNoteOff(number, 0, channel);*/
	}
  }
}
//-----------------------------------------------------------------------------------
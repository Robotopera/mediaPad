#include <HID-Project.h>
#include <HID-Settings.h>
#pragma once

//todo merge with ks's Button.h

const KeyboardKeycode key1Function = KEY_F13;
const KeyboardKeycode key2Function = KEY_F14;
const KeyboardKeycode key3Function = KEY_F15;
const KeyboardKeycode key4Function = KEY_F16;
const KeyboardKeycode key5Function = KEY_F17;
const KeyboardKeycode key6Function = KEY_F18;
const KeyboardKeycode key7Function = KEY_F19;
const KeyboardKeycode key8Function = KEY_F20;
const ConsumerKeycode knobPressFunction = MEDIA_VOLUME_MUTE;
const ConsumerKeycode knobClockwiseFunction = MEDIA_VOLUME_UP;
const ConsumerKeycode knobCounterClockwiseFunction = MEDIA_VOLUME_DOWN;

// set pin numbers for the eight buttons:
const int key1Pin = 5;
const int key2Pin = 6;
const int key3Pin = 7;
const int key4Pin = 8;
const int key5Pin = 16;
const int key6Pin = 14;
const int key7Pin = 15;
const int key8Pin = 18;
const int mutePin = 4;
const int CLK = 3;
const int DT = 2;
int currentStateCLK;
int lastStateCLK;
int press = false;  
const int delayVal = 400;

void setup() { // initialize the buttons' inputs:
  pinMode(key1Pin, INPUT_PULLUP);
  pinMode(key2Pin, INPUT_PULLUP);
  pinMode(key3Pin, INPUT_PULLUP);
  pinMode(key4Pin, INPUT_PULLUP);
  pinMode(key5Pin, INPUT_PULLUP);
  pinMode(key6Pin, INPUT_PULLUP);
  pinMode(key7Pin, INPUT_PULLUP);  
  pinMode(key8Pin, INPUT_PULLUP);  
  pinMode(mutePin, INPUT_PULLUP);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  currentStateCLK = digitalRead(CLK); 
  NKROKeyboard.begin();
}

void loop() {
  // control the keyboard:
        
  if (digitalRead(key1Pin) == LOW) {
    NKROKeyboard.add(key1Function);
    press = true;
  } else {
    NKROKeyboard.remove(key1Function);
    }
    
  if (digitalRead(key2Pin) == LOW) {
    NKROKeyboard.add(key2Function);
    press = true;
  } else {
    NKROKeyboard.remove(key2Function);
    }
    
  if (digitalRead(key3Pin) == LOW) {
    NKROKeyboard.add(key3Function);
    press = true;
  } else {
    NKROKeyboard.remove(key3Function);
    }

  if (digitalRead(key4Pin) == LOW) {
    NKROKeyboard.add(key4Function);
    press = true;
  } else {
    NKROKeyboard.remove(key4Function);
    }
    
  if (digitalRead(key5Pin) == LOW) {
    NKROKeyboard.add(key5Function);
    press = true;
  } else {
    NKROKeyboard.remove(key5Function);
    }
    
  if (digitalRead(key6Pin) == LOW) {
    NKROKeyboard.add(key6Function);
    press = true;
  } else {
    NKROKeyboard.remove(key6Function);
    }

  if (digitalRead(key7Pin) == LOW) {
    NKROKeyboard.add(key7Function);
    press = true;
  } else {
    NKROKeyboard.remove(key7Function);
    }

  if (digitalRead(key8Pin) == LOW) {
    NKROKeyboard.add(key8Function);
    press = true;
  } else {
    NKROKeyboard.remove(key8Function);
    }
    
  if (digitalRead(mutePin) == LOW) {
    Consumer.write(knobPressFunction);
    press = true;
  }
  
   currentStateCLK = digitalRead(CLK); // Reads the "current" state of the outputA
   // If the f5ious and the current state of the outputA are different, that means a Pulse has occured
   if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
      // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(DT) != currentStateCLK) {
       Consumer.write(knobCounterClockwiseFunction);
     } else {
       Consumer.write(knobClockwiseFunction);
     }
   } 
    lastStateCLK = currentStateCLK; // Updates the previous state of the outputA with the current state
   if (press == true) {
   NKROKeyboard.send();
   delay(delayVal);
   NKROKeyboard.releaseAll(); //TODO figure out way for NKROKeyboard.send() to run when key stops being pressed
   } else {
    delay(1);
   }
   press = false;

 }

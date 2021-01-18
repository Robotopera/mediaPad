#include <HID-Project.h>
#include <HID-Settings.h>
#pragma once

// set pin numbers for the eight buttons:
const int f4Button = 14;
const int f5Button = 16;
const int f6Button = 8;
const int f7Button = 7;
const int f1Button = 15;
const int f2Button = 6;
const int f3Button = 5;
const int muteButton = 4;
const int CLK = 2;
const int DT = 3;
int currentStateCLK;
int lastStateCLK;
int press = false;  
const int delayVal = 400;

void setup() { // initialize the buttons' inputs:
  pinMode(f4Button, INPUT_PULLUP);
  pinMode(f5Button, INPUT_PULLUP);
  pinMode(f6Button, INPUT_PULLUP);
  pinMode(f7Button, INPUT_PULLUP);
  pinMode(f1Button, INPUT_PULLUP);
  pinMode(f2Button, INPUT_PULLUP);
  pinMode(f3Button, INPUT_PULLUP);
  pinMode(muteButton, INPUT_PULLUP);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  currentStateCLK = digitalRead(CLK); 
  NKROKeyboard.begin();
}

void loop() {
  // use the pushbuttons to control the keyboard:
  if (digitalRead(f7Button) == LOW) {
    NKROKeyboard.add(KEY_RIGHT_SHIFT);
    press = true;
    delay(100);
  } else {
    NKROKeyboard.remove(KEY_RIGHT_SHIFT);
    }
  
  if (digitalRead(f4Button) == LOW) {
    NKROKeyboard.add(KEY_F16);
    press = true;
  } else {
    NKROKeyboard.remove(KEY_F16);
    }
    
  if (digitalRead(f5Button) == LOW) {
    NKROKeyboard.add(KEY_F17);
    press = true;
  } else {
    NKROKeyboard.remove(KEY_F17);
    }
    
  if (digitalRead(f6Button) == LOW) {
    NKROKeyboard.add(KEY_F18);
    press = true;
  } else {
    NKROKeyboard.remove(KEY_F18);
    }
        
  if (digitalRead(f1Button) == LOW) {
    NKROKeyboard.add(KEY_F13);
    press = true;
  } else {
    NKROKeyboard.remove(KEY_F13);
    }
    
  if (digitalRead(f2Button) == LOW) {
    NKROKeyboard.add(KEY_F14);
    press = true;
  } else {
    NKROKeyboard.remove(KEY_F14);
    }
    
  if (digitalRead(f3Button) == LOW) {
    NKROKeyboard.add(KEY_F15);
    press = true;
  } else {
    NKROKeyboard.remove(KEY_F15);
    }
    
  if (digitalRead(muteButton) == LOW) {
    Consumer.write(MEDIA_VOLUME_MUTE);
    press = true;
  }
  
   currentStateCLK = digitalRead(CLK); // Reads the "current" state of the outputA
   // If the f5ious and the current state of the outputA are different, that means a Pulse has occured
   if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
      // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(DT) != currentStateCLK) {
       Consumer.write(MEDIA_VOLUME_DOWN);
     } else {
       Consumer.write(MEDIA_VOLUME_UP);
     }
   } 
    lastStateCLK = currentStateCLK; // Updates the f5ious state of the outputA with the current state
   if (press == true) {
   NKROKeyboard.send();
   delay(delayVal);
   NKROKeyboard.releaseAll();
   } else {
    delay(1);
   }
   press = false;

//  if (digitalRead(CLK) == LOW) {
//    Consumer.write(MEDIA_VOLUME_DOWN);
//  }
//  if (digitalRead(DT) == LOW) {
//    Consumer.write(MEDIA_VOLUME_UP);
//  }
 }

#include "Arduino.h"
#include "MyLed.h"

MyLed::MyLed(int pin){
  _pin = pin;
  _state = false;
  pinMode(_pin, OUTPUT);
}

void MyLed::invert(){
  _state=!_state;
  update();
}

void MyLed::update(){
  digitalWrite(_pin,_state);
}

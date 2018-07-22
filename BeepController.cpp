#include "Arduino.h"
#include "BeepController.h"
#include "LiquidCrystal.h"

void BeepController::clicked400() {
  _led400.invert();
  _stateIndex = _stateIndex ^ 0x01;
  update(_stateIndex);
}
void BeepController::clicked1500() {
  _led1500.invert();
  _stateIndex = _stateIndex ^ 0x02;
  update(_stateIndex);
}
void BeepController::clicked3700() {
  _led3700.invert();
  _stateIndex = _stateIndex ^ 0x04;
  update(_stateIndex);
}

void BeepController::update(byte state) {
  _lcd.clear();
  if(state==0){
    noTone(_beepPin);
    _lcd.print(0);
  }else{
    int hz =_states[state];
    tone(_beepPin, hz);
    _lcd.print(hz);
  }
}

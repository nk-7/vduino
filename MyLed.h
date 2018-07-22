#ifndef MyLed_h
#define MyLed_h

#include "Arduino.h"

class MyLed {
  public:
    MyLed(int pin);
    void invert();
  private:
    int _pin;
    volatile boolean _state;
    void update();
  };
#endif

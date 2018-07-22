#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "Arduino.h"

class StateMachine {
  public:
    bool update(byte state);
  private:
    byte step = 0;
};

#endif
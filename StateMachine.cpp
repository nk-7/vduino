#include "StateMachine.h"
#include "Arduino.h"

bool StateMachine::update(byte leds){
    if(leds == 0){
        step = 0;
    }

    if(step == 0 && leds == 1) {
        step = 1;
        return false;
    } else if(step == 1 && leds == 5) {
        step = 2;
        return false;
    } else if(step == 2 && leds == 1) {
        step = 3;
        return false;
    } else if(step == 3 && leds == 3) {
        // DONE!!!
        return true;
        step = -1;
    }
}
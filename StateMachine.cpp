#include "StateMachine.h"
#include "Arduino.h"

bool StateMachine::update(byte leds){
    if(leds == 0){
        Serial.println("Step reseted to 0.");
        step = 0;
        return false;
    }

    if(step == 0 && leds == 1) {
        step = 1;
        Serial.println("Step changed 0 -> 1.");
        return false;
    } else if(step == 1 && leds == 5) {
        step = 2;
        Serial.println("Step changed 1 -> 2.");
        return false;
    } else if(step == 2 && leds == 1) {
        step = 3;
        Serial.println("Step changed 2 -> 3.");
        return false;
    } else if(step == 3 && leds == 3) {
        // DONE!!!
        step = -1;
        Serial.println("Step done! Step changed 3 -> -1.");
        return true;
    }
}
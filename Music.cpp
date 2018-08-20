#include "Arduino.h"
#include "Music.h"

Music::Music(int beepPin,int g, int y, int b, unsigned long  pressMs,unsigned long hzMs){
    _beepPin = beepPin;
    _g=g;
    _y=y;
    _b=b;
    _pressMs = pressMs;
    _hzMs = hzMs;
    pinMode(g, INPUT_PULLUP);
    pinMode(y, INPUT_PULLUP);
    pinMode(b, INPUT_PULLUP);
}
void Music::tick() {
    int all =  digitalRead(_g) * digitalRead(_y) * digitalRead(_b);
    if (all == HIGH){
        if(startTime == 0){
            startTime = millis();

            
        } else if(millis() - startTime   >= _pressMs) {
            playMusic();
            startTime = 0;
        }
    } else {
        startTime = 0;
    }
}

void Music::playMusic(){
    Serial.println("Play music");
    noTone(_beepPin);
    for(int n=0;n<3;n++) {    
        for (int i = 0; i < 12; i++){
            Serial.println(notes[i]);
            tone(_beepPin,notes[i]);
            delay(_hzMs);
        }
    }
}
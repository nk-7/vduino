#ifndef BeepController_h
#define BeepController_h

#include "MyLed.h"
#include "Arduino.h"
#include "LiquidCrystal.h"
#include "StateMachine.h"

  class BeepController {
  public:
    BeepController(int beepPin,MyLed led400,MyLed led1500,MyLed led3700,LiquidCrystal lcd)
    :_beepPin(beepPin),_led400(led400),_led1500(led1500),_led3700(led3700),_lcd(lcd){}

    void clicked400();
    void clicked1500();
    void clicked3700();
  private:
    int _beepPin;
    MyLed _led400;
    MyLed _led1500;
    MyLed _led3700;
    LiquidCrystal _lcd;
    byte _stateIndex = 0;
    int _states[8] = {0, 400, 1500, 1900, 3700, 4100, 5200, 5600};
    void update(byte state);
    StateMachine machine;
  };

#endif

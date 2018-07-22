#ifndef BeepController_h
#define BeepController_h

#include "MyLed.h"
#include "Arduino.h"

  class BeepController {
  public:
    BeepController(int beepPin,MyLed led400,MyLed led1500,MyLed led3700)
    :_beepPin(beepPin),_led400(led400),_led1500(led1500),_led3700(led3700){}

    void clicked400();
    void clicked1500();
    void clicked3700();
  private:
    int _beepPin;
    MyLed _led400;
    MyLed _led1500;
    MyLed _led3700;
    byte _stateIndex = 0;
    int _states[8] = {0, 400, 1500, 1900, 3700, 4100, 5200, 5600};
    void update(byte state);
  };

#endif

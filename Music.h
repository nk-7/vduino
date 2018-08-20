#ifndef MUSIC_H
#define MUSIC_H

class Music {
  public:
    Music(int beepPin,int g, int y, int b, unsigned long  pressMs,unsigned long hzMs);
    void tick();
  private:
    int _g;
    int _y;
    int _b;
    int _beepPin;
    unsigned long _pressMs;
    unsigned long _hzMs;
    unsigned long startTime = 0;
    void playMusic();

    unsigned long notes[12]={
      784,
      1047,
      1245,
      1175,
      1046,
      1245,
      1047,
      1175,
      1047,
      831,
      932,
      784
    };

};

#endif
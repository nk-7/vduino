#include "Arduino.h"
#include "Button.h"
#include "LiquidCrystal.h"
#include "MyLed.h"
#include "BeepController.h"
#include "Music.h"

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

Button gButton = Button(A0);
Button yButton = Button(A1);
Button bButton = Button(A2);
BeepController beepController = BeepController(3,  MyLed(A3),  MyLed(A4),  MyLed(A5),lcd);
Music music = Music(3,A0,A1,A2,3000,500);

void clk400() {
 beepController.clicked400();
}

void clk1500() {
   beepController.clicked1500();

}
void clk3700() {
   beepController.clicked3700();
}

void setup() {

    Serial.begin(115200);
    gButton.on_press(clk400);
    yButton.on_press(clk1500);
    bButton.on_press(clk3700);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.clear();
}

void loop() {
    gButton.init();
    yButton.init();
    bButton.init();
    music.tick();
}

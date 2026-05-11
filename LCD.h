#ifndef LCD_H
#define LCD_H
#include <LiquidCrystal_I2C.h>
#include <math.h>
#include <Arduino.h>

class DisplayManager {

    private:

        LiquidCrystal_I2C* _lcd;

    public:
    
        DisplayManager(LiquidCrystal_I2C* lcd) : _lcd(lcd) {}


        void begin() {
          _lcd->init();
          _lcd->backlight();
        }

        void showDistance(float distance) {

          int numBars = 0;
          float roundDist = round(distance);
          

          if (roundDist <= 5) {
            _lcd->setCursor(0, 0);
            _lcd->print("!!!  DANGER !!!  ");
            _lcd->setCursor(0, 1);
            _lcd->print("     STOP!!!    ");
          }
          else if (roundDist > 100) {
            _lcd->setCursor(0, 0);
            _lcd->print("Object far away ");
            _lcd->setCursor(0, 1);
            _lcd->print("Park safely...  ");
          }
          else {
          _lcd->setCursor(0, 0);
          _lcd->print("Distance: ");
          _lcd->print((int)roundDist);
          _lcd->print(" cm   ");

          numBars = map(roundDist, 5, 100, 16, 0);
          numBars = constrain(numBars, 0, 16);
          
          _lcd->setCursor(0, 1);
          for(int i = 0; i < 16; i++) {
           if (i < numBars) {
            _lcd->print((char)255);
           }
           else {
            _lcd->print(" ");
           }
          }
          }
        }

        

        


};

#endif
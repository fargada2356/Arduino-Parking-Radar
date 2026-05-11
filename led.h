#ifndef LED_H
#define LED_H
#include <Arduino.h>

class Led {

  private:

      uint8_t _pin;

  public:
  
      Led(uint8_t pin) : _pin(pin) {}

      void begin() {
        pinMode(_pin, OUTPUT);
      }

      // metod za qrkost (0-255)
      void setBrightness(int value) {
        analogWrite(_pin, value);
      }

};

#endif
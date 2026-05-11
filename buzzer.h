#ifndef BUZZER_H
#define BUZZER_H
#include <Arduino.h>

class Buzzer {

  private:

      uint8_t _buzzerPin;
      unsigned long _lastBeepTime = 0;
      float _previousDistance = 0;
      unsigned long _lastMoveTime = 0;
      bool _isSilent = false;


  public:
  
      Buzzer(uint8_t buzzer) : _buzzerPin(buzzer) {}

      void begin() {
        pinMode(_buzzerPin, OUTPUT);
        tone(_buzzerPin, 1000, 100);
      }

      void update(float distance) {

        unsigned long currentMillis = millis();
      
        if(abs(distance - _previousDistance) > 2) {
          _isSilent = false;
          _lastMoveTime = currentMillis;
          _previousDistance = distance;
        }

        if(currentMillis - _lastMoveTime > 3000) {
          _isSilent = true;
        }

        if (distance > 50 || _isSilent) {
          noTone(_buzzerPin);
          return;
        }

        if (distance < 5) {
          tone(_buzzerPin, 1000);
          return;
        }

        size_t interval = map(distance, 5, 50, 100, 1000);
    

         // izchislqvane na intervala spored razstoqnieto
        if (currentMillis - _lastBeepTime >= interval) {
          tone(_buzzerPin, 1000, 50);
          _lastBeepTime = currentMillis;
        }        

      }

};

#endif
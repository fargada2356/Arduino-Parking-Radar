#ifndef ULTRASENSOR_H
#define ULTRASENSOR_H

#include <Arduino.h>

class Sensor {

  private:

      uint8_t _trigPin;
      uint8_t _echoPin;

  
  public:
  
      Sensor(uint8_t trig, uint8_t echo) : _trigPin(trig), _echoPin(echo)  {}

      
   void begin() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
   }   

   float readDistance() {

    float totalDistance = 0;
    int samples = 5;

    for(int i = 0; i < samples; i++) {

    // pinut e izkluchen (LOW) za moment za po chist signal
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // vkluchva se pina (HIGH) za 10 mikrosekundi
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);

    // izkluchvame pina(LOW)
    digitalWrite(_trigPin, LOW);
    
    long duration = pulseIn(_echoPin, HIGH);
    float result = duration * 0.034 / 2;

    totalDistance += result;

    delay(5);
    }

    return totalDistance / samples;

   }


};

#endif
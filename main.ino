#include <Arduino.h>
#include "LCD.h"
#include "UltraSensor.h"
#include "led.h"
#include "buzzer.h"


LiquidCrystal_I2C myLcd(0x27, 16, 2);
DisplayManager myDisplay(&myLcd);
Sensor mySensor(4, 5); // trig / echo pins
Led myLed(9);
Buzzer myBuzzer(12);

void setup() {
 myDisplay.begin();
 mySensor.begin();
 myLed.begin();
 myBuzzer.begin();
}

void loop() {

  float dist = mySensor.readDistance();

  myDisplay.showDistance(dist);

  myBuzzer.update(dist);

  int brightness = map(dist, 5, 50, 255, 0);

  brightness = constrain(brightness, 0, 255);

  myLed.setBrightness(brightness);

  delay(50);



}
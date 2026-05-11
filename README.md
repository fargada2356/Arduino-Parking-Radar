#  Arduino-Parking-Radar

An advanced Arduino parking assistant featuring an object-oriented design, adaptive buzzer frequencies, noise-filtered ultrasonic readings, and a dynamic LCD progress bar.

##  Key Features
- **Intelligent Filtering:** The `Sensor` class takes 5 samples and averages them to eliminate signal noise and ensure stable distance readings.
- **Dynamic Progress Bar:** Provides real-time visual feedback on a 16x2 LCD display using a custom-scaled graphical bar.
- **Adaptive Buzzer:** Beep frequency changes dynamically based on proximity. Includes a **"Comfort Mode"** that silences the buzzer if no movement is detected for 3 seconds.
- **Visual Alert:** Integrated LED with PWM brightness control—the closer the object, the brighter the light.
- **Non-blocking Logic:** Completely built using `millis()` for multitasking, ensuring the system remains highly responsive without using `delay()`.

##  Demonstration

### Project Preview
![Parking Radar Preview](https://cdn.discordapp.com/attachments/1204887824982347827/1503348720371241040/IMG_20260511_133629.jpg?ex=6a030619&is=6a01b499&hm=a8f7a86a79293ae08c4f06594be9e2e0300cabf795dc92df2732059882e154de&)

### Watch the system in action
[![Watch the video](https://img.youtube.com/vi/QTfNDYeLN_8/maxresdefault.jpg)](https://youtu.be/QTfNDYeLN_8)


##  Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Sensor:** HC-SR04 Ultrasonic Sensor
* **Display:** 16x2 LCD with I2C Module
* **Indication:** Active Buzzer, LED, and 220Ω Resistor

##  Connection Map (Pinout)

| Component | Arduino Pin | Signal Type |
| :--- | :---: | :--- |
| **Ultrasonic Trig** | 4 | Output |
| **Ultrasonic Echo** | 5 | Input |
| **LED (PWM)** | 9 | PWM Output |
| **Buzzer** | 12 | Digital Output |
| **LCD SDA** | A4 | I2C Data |
| **LCD SCL** | A5 | I2C Clock |

##  Software Architecture
The project is organized into modular C++ classes to ensure clean, maintainable, and reusable code:

* **`DisplayManager`**: Handles the LCD I2C interface and the logic for the graphical progress bar.
* **`Sensor`**: Responsible for high-precision distance measurement using multi-sample filtering.
* **`Buzzer`**: Controls the adaptive audio logic, beep intervals, and the auto-silence feature.
* **`Led`**: Manages the distance-based light intensity using PWM.

---
*Developed as a comprehensive study in embedded systems and OOP.*

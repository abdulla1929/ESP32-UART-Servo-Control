# ESP32-UART-Servo-Control
This is a simple project where an ESP32 controls a servo motor through an Arduino Nano using UART communication.

The initial goal was to control a servo motor directly using an ESP32. However, during development, difficulties were encountered while interfacing the servo with the ESP32. To continue the project and explore microcontroller communication, a UART-based solution was implemented using an Arduino Nano.

In this system, the ESP32 reads an analog input from a potentiometer, converts the value into a servo angle, and transmits the angle to the Arduino Nano through UART communication. The Arduino Nano then receives the data and controls the servo motor accordingly.

Hardware Used
ESP32 Development Board
Arduino Nano
Servo Motor
Potentiometer
Jumper Wires
System Operation
The ESP32 reads the potentiometer value using its ADC.
The ADC value is mapped to an angle between 0° and 180°.
The calculated angle is transmitted to the Arduino Nano via UART.
The Arduino Nano receives the angle and updates the servo position.
Learning Objectives

The project was completed to practice and improve understanding of:

ESP-IDF development
ADC operation on the ESP32
UART communication between microcontrollers
Servo motor control
Basic embedded system integration
Notes

The primary focus of this project was educational rather than optimization. Implementing UART communication between the ESP32 and Arduino Nano provided an opportunity to explore communication protocols while completing the servo control task.

Future Improvements
Direct servo control using the ESP32
Support for multiple servos
Joystick-based control
Wireless control through Wi-Fi or Bluetooth

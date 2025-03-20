# Arduino Servo Motor and LED Control Project

This project demonstrates how to control a servo motor and two LEDs using an Arduino board.

## Version
v1.0.0

## Hardware Requirements
- Arduino board (e.g., Arduino Uno)
- 1x Servo Motor
- 2x LEDs
- 2x 220Ω resistors (for LEDs)
- Jumper wires
- Breadboard

## Pin Connections
- Servo Motor: Digital Pin 9
- LED 1: Digital Pin 7
- LED 2: Digital Pin 8

## Features
- Servo motor control with angle adjustment
- Two independent LED control
- Serial communication for debugging

## Usage
1. Connect the hardware according to the pin connections
2. Upload the code to your Arduino board
3. Open the Serial Monitor to see the debug messages
4. Use the Serial Monitor to control the servo motor and LEDs

## Control Commands
- Send '1' to turn on LED 1
- Send '0' to turn off LED 1
- Send '3' to turn on LED 2
- Send '2' to turn off LED 2
- Send a number between 0-180 to control the servo motor angle 
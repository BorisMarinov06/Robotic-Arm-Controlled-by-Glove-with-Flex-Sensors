🤖 Robotic Hand Controlled by Flex Sensor Glove

A wireless 3D-printed robotic arm controlled using a glove with flex sensors and Arduino Nano microcontrollers.

📌 Project Overview

This project is a real-time robotic arm control system that mimics human hand movements.

The system uses:

- a glove equipped with flex sensors
- wireless RF communication
- multiple servo motors
- a tendon-driven mechanical structure

When the user bends their fingers, the robotic arm reproduces the movement almost instantly.

The project was created as a diploma project focused on:

- embedded systems
- wireless communication
- sensor processing
- servo motor control
- mechanical design

⚙️ Main Features

Real-time hand motion control
Wireless communication via 433MHz RF modules
Flex sensor glove input
5 servo motor driven joints
Tendon-based finger movement system
Fully 3D-printed construction
Portable battery-powered controller
Modular electronics design
System Architecture

The project is divided into two separate systems:

1️⃣ Controller Glove

The glove detects finger movement using flex sensors.

Components
Arduino Nano
5x Flex Sensors (2.2" Spectra Symbol)
STX882 RF Transmitter
Li-Ion Battery
TP4056 Charging Module
CKCS BS01 Step-Up Converter
Function

The Arduino reads analog values from the flex sensors and transmits them wirelessly to the robotic arm.

2️⃣ Robotic Hand

The robotic arm receives wireless data and moves the servos.

Components
Arduino Nano
SRX882 RF Receiver
5x MG90S Servo Motors
External Power Supply
Function

The receiver Arduino processes incoming sensor data and converts it into servo motor movement.

🔌 Electronics
Wireless Communication

The system uses:

STX882 transmitter
SRX882 receiver

Communication is handled using the RH_ASK library.

Power System:
Glove Side is powered by:

rechargeable Li-Ion battery
TP4056 charging/protection module
boost converter for stable 5V output

Robotic Arm Side is powered using an external supply to ensure stable servo operation.

🦾 Mechanical Design

The robotic arm is fully 3D printed.

Movement Mechanism

The fingers use:

nylon cords as tendons
elastic bands for return movement

This creates a lightweight and efficient motion system similar to a human hand.

💻 Software
Development Environment
Arduino IDE
  Libraries Used:
    RH_ASK
    SPI.h
    Servo.h

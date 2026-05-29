# esp32-http-led-control
IoT project for controlling LEDs remotely using an ESP32.

## Overview

This project uses an ESP32 as an HTTP server to control 3 LEDs through a browser-based interface.

The system allows real-time GPIO control using HTTP requests over a local Wi-Fi network.

## Features

- Remote LED control
- ESP32 HTTP server
- Browser-based interface
- Real-time GPIO interaction
- Wi-Fi communication

## Hardware Used

- ESP32 Development Board
- 3 LEDs
- Resistors
- Breadboard
- Jumper wires

## Technologies

- C++
- PlatformIO
- Arduino Framework
- HTTP Protocol

## How It Works

1. The ESP32 connects to a Wi-Fi network
2. The web server starts running
3. The user accesses the ESP32 IP address
4. HTTP requests are sent through the browser
5. LEDs are turned on or off in real time
## Author

GabOli (Gabriel Oliveira)
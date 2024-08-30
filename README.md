# ESP32Communication

This project aims to enable communication between multiple ESP32 devices.

## Original Wish

The goal of this project is to synchronize several ESP32 microcontrollers. The idea is to establish a head/master ESP32 that can be communicated with initially (via a web app or mobile app). This master will then relay messages to all other ESP32 devices. The microcontrollers will be organized into a graph structure and will communicate via WebSockets, with a maximum of 2 or 3 connections per device.

To visualize the communication status, a 10-LED strip will be used to display the following information:

- **ESP Number**: Represented using 1 or 2 RGB LEDs to show the device number in binary. (Minimum 1 LED, Maximum 2 LEDs)
- **Connections**: Indicated by 2 or 3 LEDs, each displaying different colors based on connections. (Minimum 3 LEDs, Maximum 6 LEDs)
- **Role Status**: Displayed by a single LED showing if the ESP is a master (receives commands), a child (listens to master, no direct web app access), or independent (not yet connected). (Maximum 1 LED)
- **Information Pixel**: A single LED for displaying additional information. (Maximum 1 LED)
- **Future Feature**: Indication if connected to a router/WiFi (to be implemented later).

A push button will also be used to change the LED strip's display, helping to visualize different states and connections.

## Use Cases and Desired Configurations

1. **All ESPs Connected to One Router at Home**: Each ESP has a web app. If synchronization is enabled, any action on one web app will affect all connected ESP devices.
2. **At Least One ESP Connected to a Router, Others Not**: Each ESP has a web app. The first step is to connect to the router. The closest panel to the router acts as an intermediary, scanning and connecting to all other devices to form a network.
3. **At Least One ESP Connected to a Router, Others Not, No Initial Router Connection**: Each ESP has a web app. The closest panel to the phone or computer becomes the intermediary, forming a network that allows information flow among all devices, even if some are connected to the router.
4. **No Router, ESPs Are Close to Each Other (Outdoor Scenario)**: Each ESP has a web app, and they autonomously form a network.

## The Results

This project is the beginning phase of creating a network that enables multiple ESP32 devices to communicate without needing a central router.

After researching, I decided to use `painlessMesh`, which meets the requirements for lesklights.com and is relatively simple to implement. Although ESP WiFi Mesh was considered, it was not compatible with the Arduino framework and seemed too complex.

As of August 29, 2024, three ESP32 devices can communicate and change each other's colors.

Further development on this project is on hold as I need to focus on Lesk. Potential future applications could include using multiple push buttons for a sports app to track performance in activities like football or boxing.

To be continued...

## Links

Here is a functioning scan of the networks using ESP WiFi: [ESP-IDF Issue #3252](https://github.com/espressif/esp-idf/issues/3252)

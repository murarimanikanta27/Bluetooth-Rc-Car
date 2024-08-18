

# Bluetooth-Controlled Car with ESP32 and L298 Motor Driver

## Overview

This project involves building a Bluetooth-controlled car using an ESP32 microcontroller, a 5V battery, 4 DC gear motors, and an L298 motor driver. The car is controlled via a Bluetooth connection, allowing you to drive it using a smartphone or other Bluetooth-enabled device. The ESP32 handles the communication and control logic, while the L298 motor driver powers the motors.

## Features

- **Bluetooth Control**: Control the car wirelessly via a Bluetooth connection using a smartphone app or another Bluetooth-enabled device.
- **ESP32 Microcontroller**: The ESP32 provides powerful processing and integrated Bluetooth functionality.
- **DC Gear Motors**: Four DC gear motors provide reliable movement and control.
- **L298 Motor Driver**: The L298 motor driver handles motor control, providing direction and speed control for the DC motors.
- **Portable Power**: Powered by a 5V battery, making the car fully portable.

## Components

- **ESP32**: The microcontroller responsible for Bluetooth communication and motor control.
- **L298 Motor Driver**: Controls the speed and direction of the four DC gear motors.
- **4 DC Gear Motors**: Drive the car's wheels.
- **5V Battery**: Powers the entire circuit.
- **Chassis**: The structure of the car that holds all the components.
- **Wheels**: Attached to the motors for movement.

## Wiring Diagram

1. **ESP32 to L298 Motor Driver**:
   - **IN1** to ESP32 digital pin 
   - **IN2** to ESP32 digital pin 
   - **IN3** to ESP32 digital pin
   - **IN4** to ESP32 digital pin 
   - **ENA** and **ENB** (enable pins) to PWM-capable pins on the ESP32 (e.g., D32 and D33).
   - **VCC** to the 5V output from the ESP32 or the 5V battery (depending on your power setup).
   - **GND** to the common ground with the ESP32.
   - **Motor Outputs**: Connect the output pins to the four DC motors.

2. **Motors**:
   - Connect the motors to the output terminals of the L298 motor driver.
   - Two motors for the left side of the car (connected in parallel).
   - Two motors for the right side of the car (connected in parallel).

3. **Power Supply**:
   - Connect the 5V battery to the VCC and GND pins on the ESP32 and the L298 motor driver.
   - Ensure that the ground is shared between the ESP32 and the motor driver for proper operation.

## Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/bluetooth-car-esp32.git
   cd bluetooth-car-esp32
   ```

2. **Upload the Code**:
   - Open the Arduino IDE or another suitable IDE for ESP32 development.
   - Install the necessary libraries for Bluetooth and motor control if they are not already installed.
   - Open the `bluetooth_car.ino` file from the repository.
   - Connect your ESP32 to your computer using a USB cable.
   - Select the correct board (ESP32 Dev Module) and port from the IDE.
   - Click on the Upload button to upload the code to the ESP32.

3. **Assemble the Car**:
   - Attach the ESP32, L298 motor driver, and battery to the car chassis.
   - Connect the wheels to the motors.
   - Double-check all wiring according to the diagram above.

4. **Bluetooth Pairing**:
   - Turn on the car and open the Bluetooth settings on your smartphone.
   - Pair your device with the ESP32 (it should appear as a Bluetooth device).
   - Use a Bluetooth control app (e.g., a custom app or a general-purpose Bluetooth controller app) to control the car.

## How It Works

1. **Bluetooth Communication**: The ESP32 listens for commands sent via Bluetooth from a smartphone or other device.
2. **Motor Control**: Based on the received commands, the ESP32 sends signals to the L298 motor driver to control the speed and direction of the motors.
3. **Movement**: The car moves forward, backward, left, or right based on the input from the Bluetooth controller.

## Troubleshooting

- **Car Not Moving**: Check the connections between the ESP32 and the L298 motor driver. Ensure that the motor driver is receiving power.
- **Bluetooth Not Pairing**: Make sure the ESP32 is in pairing mode, and the correct board configuration is selected in the code.
- **Motors Not Responding Correctly**: Verify that the IN pins are correctly connected and that the enable pins (ENA and ENB) are receiving a PWM signal.


## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## Acknowledgments

- Thanks to the open-source community for providing resources and libraries that made this project possible.


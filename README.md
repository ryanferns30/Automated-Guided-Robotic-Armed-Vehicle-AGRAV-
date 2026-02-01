# AGRAV – Automated Guided Robotic Armed Vehicle

## Overview

AGRAV (Automated Guided Robotic Armed Vehicle) is a mobile robotic system that integrates a 6-DOF serial robotic arm with an Automated Guided Vehicle (AGV) to automate material handling and pick-and-place operations.

This prototype was developed to explore how **mobility and manipulation** can be combined into a single system to improve productivity and reduce manual labor in industrial environments such as warehouses and manufacturing plants.

AGRAV was built as a **first-year capstone (mini) project at NMIMS MPSTME**, inspired by industrial engineering studies that highlighted how repetitive material handling tasks are still largely manual, time-consuming, error-prone, and limited by human working hours. By mounting a robotic arm on an AGV, AGRAV offers a compact, modular, and scalable solution capable of both transport and manipulation—tasks traditionally handled by separate systems.

## Current Capabilities

- Line-following navigation
- Manual control via a custom Android app
- Servo motor–based arm articulation
- Designed in Fusion 360 and structurally analyzed using ANSYS

## Future Scalability

For industrial-scale deployment, AGRAV can be enhanced with:
- RFID-based item identification
- Warehouse Management System (WMS) integration
- Multi-robot task coordination
- Advanced navigation and automation logic

### What is a Warehouse Management System (WMS)?
A WMS is software that manages inventory, tracks item locations, and assigns tasks to robots or workers. Integrated with AGRAV, a WMS can enable optimized routing, automated pick assignments, inventory logging, and 24/7 warehouse operation with minimal human intervention.

## Features

- 6-DOF robotic arm with aluminum links
- AGV with mecanum wheels for omnidirectional movement
- Arduino-based control architecture
- Bluetooth communication
- Line following and obstacle avoidance

## Project Images

### AGRAV Prototype
![AGRAV Prototype](https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/780958a511f33ec9a4d110b38585226d66f30f79/AGRAV%20MODEL.jpg)

### CAD Model
![CAD Model](https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/6202ff4b28d680c40763abf8fb3c205e8188d024/CAD%20MODEL.png)

### Robotic Arm DOF
![Robotic Arm DOF](https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/5443c8b610e9b472dd152e8d80bdf4b893df2ad8/Robotic%20Arm%20DOF.png)

### Equivalent Stress Analysis (ANSYS)
![Equivalent Stress Analysis](https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/251402bf10bf421488a8178499ab7ea2e7255baf/Equivalent%20Stress%20Analysis.png)

### Total Deformation Analysis (ANSYS)
![Total Deformation Analysis](https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/869564cec5a0b97184eb77ae6dffd51c1fbec3de/Total%20Deformation%20Analysis.png)

### Android App Interface
![Android App Interface](https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/1d2d52493acb7f46f889830025c187b239f0133f/APP%20UI%201.png)(https://github.com/ryanferns30/Automated-Guided-Robotic-Armed-Vehicle-AGRAV-/blob/7dd47a3b7c4bbeccde1131fd85ea1e34ebb09ac4/APP%20UI%202.png)

## Project Structure

AGRAV/
├── cad/ # CAD models (Fusion 360)
├── code/ # Arduino and Android app code
├── analysis/ # ANSYS analysis files
├── images/ # Project images
├── report/ # Full project report
└── README.md

## Android App

A custom Android app was developed using **MIT App Inventor** to manually control AGRAV:
- Directional movement controls
- Speed control slider
- Individual arm joint control
- Line-following mode toggle

## Components Used

- Arduino Uno Rev3
- Arduino Motor Shield
- PCA9685 Servo Driver
- MG996R High Torque Servo Motors (×6)
- SG90 Continuous Rotation Servo
- BO Dual Shaft DC Motors (×4)
- 80mm Mecanum Wheels (×4)
- HC-SR04 Ultrasonic Sensor
- IR Obstacle Avoidance Sensors
- 18650 Li-ion Batteries (×2)
- Li-ion Charger with Type-C Booster
- Aluminum brackets and 3D printed PLA parts
- Robotic gripper
- Miscellaneous wiring, switches, LEDs, and relays

## Advantages

- 24/7 operation capability
- Reduced human effort
- Improved accuracy and efficiency
- Safer and scalable for real-world warehouses

## Limitations

- High initial setup cost
- Requires a controlled environment
- Limited payload capacity in the prototype version

## Documentation

- Full project report available in `/report`
- Arduino and Android app code in `/code`
- CAD models in `/cad`
- ANSYS results in `/analysis`

## Team

- Sahil Bhuta 
- Paurash Deboo 
- Ryan Fernandes 

**Guide:** Prof. Giridhar Chavan

## How to Build AGRAV

### 1. Download the Files
Clone or download this repository to access CAD models, circuit diagrams, Arduino code, and Android app files.

### 2. Fabricate Parts
- 3D print AGV body and brackets using PLA or PETG
- Fabricate robotic arm links using aluminum or 3D printing

### 3. Procure Components
Refer to the **Components Used** section and source all electronics and mechanical parts.

### 4. Assemble Hardware
- Mount motors, wheels, and chassis
- Assemble the robotic arm on the AGV
- Wire electronics according to the schematic

### 5. Upload Code
- Upload arm control code to Arduino Uno
- Upload AGV control code to Arduino Mega
- Verify pin mappings before flashing

### 6. Install Android App
- Install the provided APK or build using MIT App Inventor
- Connect to HC-05 Bluetooth module

### 7. Test & Calibrate
- Test arm joints and AGV movement
- Calibrate servo angles and motor speeds
- Enable line-following or develop custom autonomy

## Open Source & Future Work

Although AGRAV is a small-scale prototype, it is designed with **industrial scalability** in mind. Future versions may include stronger materials, higher payload actuators, PLC-based control, advanced navigation, and full WMS + RFID integration.

This project is open source to support **students, hobbyists, and engineers** exploring robotics, automation, and warehouse logistics.

---

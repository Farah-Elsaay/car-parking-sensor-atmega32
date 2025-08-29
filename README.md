# 🚗 Car Parking Sensor Using ATmega32  

<p align="center">
  <img src="https://img.shields.io/badge/Microcontroller-ATmega32-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Language-C-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Platform-Embedded-green?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Sensor-Ultrasonic-yellow?style=for-the-badge"/>
</p>  

A **Car Parking Assistance System** built with an **ATmega32 microcontroller** that measures the distance to obstacles using an **ultrasonic sensor**, displays the distance on an **LCD**, and provides **LED and buzzer alerts** for safe parking.  

---

## ✨ Features  

- 📏 **Ultrasonic Distance Measurement**  
  - Continuously measures distance to obstacles in centimeters.  

- 📟 **LCD Display**  
  - Shows real-time distance in cm.  
  - Displays **"Stop"** when distance ≤ 5 cm.  

- 💡 **LED Indicators**  
  - Distance ≤ 5 cm → All LEDs flashing + Stop alert.  
  - 6–10 cm → Red + Green + Blue ON.  
  - 11–15 cm → Red + Green ON.  
  - 16–20 cm → Red ON.  
  - >20 cm → All LEDs OFF.  

- 🔔 **Buzzer Alerts**  
  - Buzzer ON when distance ≤ 5 cm.  

---

## 🖥️ Hardware Components  

- **Microcontroller:** ATmega32 @ 16 MHz  
- **Ultrasonic Sensor:** HC-SR04  
- **LCD:** 16x2 in 4-bit mode  
- **LEDs:** Red, Green, Blue  
- **Buzzer:** PC5 output  

---

## 🚀 Demo  

🎥 [Project Video](https://youtu.be/bhtyP1ZBiJg)  

---

## ⚙️ System Architecture  

```mermaid
flowchart TD
    Ultra[Ultrasonic Sensor HC-SR04] --> MCU[ATmega32]
    MCU --> LCD[LCD 16x2]
    MCU --> LEDS[RGB LEDs]
    MCU --> Buzzer[Buzzer]



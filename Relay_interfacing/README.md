# 🔁 Relay Interfacing

This project shows how to interface a relay using a PIC16F887 microcontroller.

---

## 📁 Files

- **Relay_Interfacing.X/** – MPLAB X project folder (with source code)  
- **Relay_Interfacing.pdsprj** *(optional)* – Proteus simulation file

---

## 🧰 Requirements

- MPLAB X IDE  
- XC8 Compiler  
- PIC16F887 Microcontroller  
- Push Button  
- Relay 
- Resistors (1kΩ)  
- Bulb
- Power Supply (5V)  
- *(Optional)* Proteus 8

---

## 💡 Features

- When button is pressed , rely turns on and bulb turns on  
- When button is released , rely turns off and bulb turns off.  

---

## 🔌 Connections

| Component    | PIC16F887 Pin |
|--------------|----------------|
| Push Button  | RB0            |
| Relay        | RB1            |
| VSS, VDD     | GND, +5V       |

---

## 🚀 How to Use

1. Connect the circuit as shown above  
2. Open the project in MPLAB X IDE  
3. Build the project with XC8 Compiler  
4. Upload the HEX file to the PIC16F887  
5. Press the button — relay will turn ON




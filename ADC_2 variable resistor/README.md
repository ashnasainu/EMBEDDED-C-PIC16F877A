# 2 Variable Resistor interfacing 

This project demonstrates how to interface 2 variable resistor with the PIC16F887 microcontroller using its ADC module. The digitized analog value is displayed on a 16x2 character LCD in real time.

---

## 📁 Files

- **ADC_LCD.X/** - MPLAB X project folder (source code)
- **ADC_LCD.pdsprj** *(optional)* - Proteus simulation file for virtual testing

---

## 🧰 Requirements

- MPLAB X IDE  
- XC8 Compiler  
- PIC16F887 Microcontroller  
- 16x2 Character LCD  
- 10kΩ Potentiometer  (2 No) 
- Power Supply (5V)  
- Optional: Proteus 8 for simulation

---

## 💡 Features

- Reads analog voltage from a potentiometer using the ADC module  
- Displays the digitized value (0–1023) on the LCD  
- Updates the reading continuously in real time

---

## 🔌 Connections

| Component       | PIC16F887 Pin  |
|----------------|----------------|
| Potentiometer   | AN0 & AN1      |
| LCD (RS)        | RB0            |
| LCD (EN)        | RB1            |
| LCD (D4–D7)     | RB2–RB5        |
| VSS, VDD, VEE   | GND, +5V, Pot Mid |
| RW (LCD)        | GND            |

> ADC uses **channel AN0 & AN1** by default.

---

## 🚀 How to Use

1. Connect the components as per the table above.  
2. Open the project in **MPLAB X IDE**.  
3. Build the project using the **XC8 Compiler**.  
4. Upload the HEX file to the **PIC16F887** microcontroller.  
5. Power on the circuit — the LCD will show the text:
  
---

## 🔁 Functions Used

- `ADC_initialise()` – Initializes the ADC module  
- `lcd_initialise()` – Initializes the LCD in 4-bit mode  
- `ADC_read()` – Reads analog input from channel AN0 & AN1
- `lcd_set_cursor()` – Setting positions of LCD 
- `lcd_string()` – Displays string on LCD
- `integer_int()` – Converts integer to string & displays on LCD

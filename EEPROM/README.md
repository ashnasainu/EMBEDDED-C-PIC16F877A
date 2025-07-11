# EEPROM String Display with PIC16F887A

This project writes a string to the internal EEPROM of a **PIC16F887A** and then reads and displays it on a **16x2 LCD**.

---

## 🔧 Requirements

- MPLAB X IDE  
- XC8 Compiler  
- PIC16F887A  
- 16x2 LCD  
- 5V Power Supply  
- Potentiometer (for LCD contrast)

---

## 📦 Files

- `main.c` – Main program  
- `LCD.h / LCD.c` – LCD functions  
- `EEPROM.h / EEPROM.c` – EEPROM read/write functions  
- `confi.h` – Configuration bits  

---

## 🔌 Connections

| Component | PIC16F887A Pins |
|----------|------------------|
| LCD RS   | RD0              |
| LCD EN   | RD1              |
| LCD D4–D7| RD2 – RD5        |
| LCD RW   | GND              |
| VSS/VDD  | GND / +5V        |
| VEE      | Pot Center       |

---

## ▶️ How It Works

1. The string **"ashna"** is written to EEPROM at address `0x90`.
2. It is then read back into a buffer.
3. The LCD displays:
   - Line 1: `EEPROM`
   - Line 2: `ashna`

---

## 🧠 Main Code Idea

```c
EEPROM_write_string(0x90, "ashna");
EEPROM_read_string(0x90, buffer);
lcd_string(buffer);

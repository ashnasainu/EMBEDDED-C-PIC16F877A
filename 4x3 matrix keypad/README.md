# 4x3 Keypad Interfacing with PIC16F887A

This project shows how to connect a **4x3 matrix keypad** to the **PIC16F887A** microcontroller and display the pressed key on a **16x2 LCD**.

---

## 📁 Files

- **Keypad_LCD.X/** – MPLAB X project folder  
- **Keypad_LCD.pdsprj** – (optional) Proteus simulation file

---

## 🧰 Requirements

- MPLAB X IDE  
- XC8 Compiler  
- PIC16F887A  
- 4x3 Matrix Keypad  
- 16x2 LCD  
- 5V Power Supply  

---

## 🔌 Connections

| Component     | PIC16F887A Pins     |
|--------------|--------------------|
| Keypad Rows  | RB4 – RB7 (Input)  |
| Keypad Cols  | RB0 – RB2 (Output) |
| LCD RS       | RD0                |
| LCD EN       | RD1                |
| LCD D4–D7    | RD2 – RD5          |
| LCD RW       | GND                |
| VSS, VDD     | GND, +5V           |
| VEE          | Pot Center (for contrast) |

---

## 🚀 How to Use

1. Connect the circuit as shown above.  
2. Open the project in MPLAB X.  
3. Build the code with the XC8 compiler.  
4. Upload the HEX file to PIC16F887A.  
5. Power the circuit & Observe the reults.

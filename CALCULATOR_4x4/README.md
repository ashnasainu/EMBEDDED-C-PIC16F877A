**CALCULATOR** - Implementation of a basic calculator using a 4x4 keypad and 16x2 LCD with a PIC16F887A microcontroller.It allows to enter two numbers and an operator (`+`, `-`, `*`, `/`) to display the result on the LCD.
---

## 🔧 What You Need

- PIC16F887A  
- 4x4 Keypad  
- 16x2 LCD   
- MPLAB X IDE with XC8 Compiler  

---

## 🔌 Connections

| Part       | PIC Pin        |
|------------|----------------|
| Keypad     | RB0 – RB7      |
| LCD RS     | RD0            |
| LCD EN     | RD1            |
| LCD D4–D7  | RD2 – RD5      |

---

## ▶️ How It Works

1. LCD shows **“CALCULATOR”** at startup.  
2. Enter the **first number** using the keypad.  
3. Press an operator (`+`, `-`, `*`, `/`).  
4. Enter the **second number**.  
5. Press `=` or another operator to see the result.  
6. The result appears on the second line of the LCD.

---

## 🔄 Supported Operations

- Addition `+`  
- Subtraction `-`  
- Multiplication `*`  
- Division `/`

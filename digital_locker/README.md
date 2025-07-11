**DIGITAL_LOCKER SYSTEM**

This project lets you enter a 4-digit password using a **keypad**, and shows if it's correct on a **16x2 LCD**.

---

## 🧰 What You Need

- PIC16F887A  
- 4x3 Keypad  
- 16x2 LCD  
- 5V Power  
- MPLAB X IDE + XC8 Compiler  

---

## 🔌 Connections

| Part       | PIC Pin        |
|------------|----------------|
| Keypad     | RB0–RB7        |
| LCD RS     | RD0            |
| LCD EN     | RD1            |
| LCD D4–D7  | RD2 – RD5      |
| Output Pin | RC0 (for LED)  |

---

## ▶️ What It Does

1. Asks to **"ENTER PASSWORD"**  
2. You type 4 digits using the keypad  
3. If correct (default: `1234`)  
   - LCD shows: **CORRECT PASSWORD**  
   - RC0 pin goes HIGH (can turn on LED or buzzer)  
4. If wrong  
   - LCD shows: **WRONG PASSWORD**


#  DIGITAL LOCKER SYSTEM

This project lets you enter a 4-digit password using a **keypad**, and shows if it's correct on a **16x2 LCD**.

---

## 🧰 What You Need

- PIC16F887A  
- 4x3 Keypad  
- 16x2 LCD  
- 5V Power Supply  
- MPLAB X IDE + XC8 Compiler  
- LED or Buzzer (optional for output)

---

## 🔌 Connections

| Part       | PIC Pin        |
|------------|----------------|
| Keypad     | RB0 – RB7      |
| LCD RS     | RD0            |
| LCD EN     | RD1            |
| LCD D4–D7  | RD2 – RD5      |
| Output Pin | RC0 (LED/Relay)|

---

## ▶️ What It Does

1. LCD shows: **"ENTER PASSWORD"**  
2. You enter 4 digits using the keypad  
3. If password is correct (default: `1234`):  
   - LCD shows: **"UNLOCKED"**  
   - RC0 pin goes HIGH (turns ON LED or relay)  
   - You can press:
     - `*` to lock again  
     - `#` to set a new password  
4. If password is wrong:  
   - LCD shows: **"WRONG PASSWORD"**  
   - After 4 wrong tries, system locks for 10 seconds
# INTERNAL EEPROM of PIC16F877A 

This project shows how to **write and read data** from INTERNAL EEPROM of PIC16F877A and display it on a **16x2 LCD**.

---

## 🧰 Components

- PIC16F877A  
- EEPROM (I2C)  
- 16x2 LCD  
- 5V Power Supply  
- MPLAB X IDE + XC8 Compiler  

---

## 🔌 Connections

| Part       | PIC Pin        |
|------------|----------------|
| LCD RS     | RD0            |
| LCD EN     | RD1            |
| LCD D4–D7  | RD2 – RD5      |
| EEPROM SDA | RC4 (SDA)      |
| EEPROM SCL | RC3 (SCL)      |
| Power      | +5V / GND      |

---

## ▶️ Working

1. LCD starts with message **"EEPROM"**  
2. String **"ashna"** is stored in EEPROM (address `0x90`)  
3. The same string is **read back** from EEPROM  
4. LCD shows the stored string on the second line  
5. Repeats every 5 seconds  


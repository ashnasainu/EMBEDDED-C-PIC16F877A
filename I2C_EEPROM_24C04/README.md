# EEPROM (24C04) using I2C with PIC16F877A

This project writes and reads data from 24C04 EEPROM using I2C with PIC16F877A, shows it on a 16x2 LCD, and sends messages to UART.

---

## Components
- PIC16F877A  
- 24C04 EEPROM  
- 16x2 LCD  
- UART (for debugging)  
- 5V Power Supply  

---

## Working
1. LCD shows "EEPROM_I2C" on start.  
2. String "ASHNA" is written to EEPROM.  
3. The string is read back and displayed on LCD.  
4. Data is also printed on UART terminal.  

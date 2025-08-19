# RTC (DS1307) using I2C with PIC16F877A

This project shows how to write , read and set time from an RTC(DS1307) using I2C with PIC16F877A and display it on a 16x2 LCD, and send messages through UART.

---

## Components
- PIC16F887A  
- DS1307 RTC (I2C)  
- 16x2 LCD  
- 2 Push Buttons  
- 5V Power Supply  

---

## Connections
- LCD RS → RD0  
- LCD EN → RD1  
- LCD D4–D7 → RD2–RD5  
- RTC SDA → RC4  
- RTC SCL → RC3  
- Button1 (Position) → RB0  
- Button2 (Increment) → RB1  
- UART TX → RC6  
- UART RX → RC7  

---

## Working
1. LCD shows **TIME** on startup.  
2. RTC time is displayed as **HH:MM:SS AM/PM**.  
3. RB0 button → move between hour, minute, second.  
4. RB1 button → increment selected value.  
5. Updated time is written back to RTC.  
6. UART shows debug messages.  
# ⏰ RTC time Display with PIC16F887A

This project sets the time on a DS1307 RTC using I2C, reads it back, and displays it on a 16x2 LCD. Time can be adjusted using push buttons, and debug messages are sent over UART.

---

## 🛠️ Requirements

- PIC16F887A
- DS1307 RTC Module
- 16x2 LCD
- 20 MHz Crystal Oscillator
- 2 Push Buttons (Time Position & Increment)
- MPLAB X IDE + XC8 Compiler

---

## ⚙️ How It Works

1. LCD, I2C, and UART are initialized.
2. RB0 button → Selects time field (Hour → Minute → Second → Save).
3. RB1 button → Increments the selected field.
4. When saved, time is written to the DS1307 RTC.
5. Main loop reads time from RTC every second and shows it on LCD in 12-hour format with AM/PM.
6. UART logs all button presses, time changes, and RTC reads/writes.

---

## 📌 Pin Connections

| PIC Pin  | Function      | Connected To  |
|----------|--------------|--------------|
| RD0–RD7  | LCD Data     | LCD D0–D7    |
| RC0–RC2  | LCD Control  | RS, RW, EN   |
| RC3      | I2C SCL      | DS1307 SCL   |
| RC4      | I2C SDA      | DS1307 SDA   |
| RB0      | Position Btn | Push Button 1|
| RB1      | Increment Btn| Push Button 2|
| RC6      | UART TX      | PC/USB-TTL RX|
| RC7      | UART RX      | PC/USB-TTL TX|



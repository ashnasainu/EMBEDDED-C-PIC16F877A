# UART LED Control with LCD (PIC16F887)

This project shows how to control an LED using UART commands and display the status on a 16x2 LCD using a PIC16F887.

## Files
- UART_LED.X - MPLAB X project
- confi.h, LCD.h, UART.h - Header files
- UART_LED.pdsprj - (Optional) Proteus simulation file

## Requirements
- MPLAB X IDE + XC8 Compiler
- PIC16F887
- 16x2 LCD
- USB-to-Serial module (or UART terminal)

## What It Does
- On power-up, shows "LED UART TEST" on LCD.
- If UART receives:
  - 'a' → Turns LED ON, shows "LED ON" on LCD.
  - 'b' → Turns LED OFF, shows "LED OFF" on LCD.

## How to Use
1. Connect LCD to PORTB and LED to RC1.
2. Connect RC7 (RX) to TX of UART device.
3. Open and build the project in MPLAB X.
4. Flash the code to PIC16F887.
5. Open serial terminal (9600 baud, 8N1).
6. Send 'a' or 'b' to control the LED.

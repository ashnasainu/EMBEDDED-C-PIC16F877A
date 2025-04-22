# LCD 4-Bit Scrolling Text (PIC16F887)

This project demonstrates how to interface a 16x2 LCD in **4-bit mode** with a PIC16F887 and scroll a message to the left.

## Files
- **LCD_4bit.X/** - MPLAB X project
- **LCD_4bit.pdsprj** - Proteus simulation file (optional)

## Requirements
- MPLAB X IDE, XC8 Compiler
- PIC16F887
- 16x2 LCD

## What It Does
- Displays the message **"EMBEDDED SYSTEMS"** on the LCD in **4-bit mode**
- Scrolls the message to the left using custom function `lcd_leftscroll()`

## How to Use
1. Connect the LCD to PORTB as defined in the code.
2. Open the project in MPLAB X.
3. Compile and upload to the PIC16F887.
4. Power the circuit - the LCD will show and scroll the message.


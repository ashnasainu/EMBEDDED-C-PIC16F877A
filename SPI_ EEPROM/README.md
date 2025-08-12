# EEPROM with PIC16F887A through SPI

This project uses a PIC16F887A to communicate with a 25AA160A EEPROM through SPI.  
It writes a byte to the EEPROM, then reads it back and sends messages over UART.

## Requirements
- PIC16F887A
- 25AA160A SPI EEPROM
- UART terminal (Tera Term / PuTTY)
- 20 MHz crystal
- MPLAB X IDE + XC8
- 5V power supply
- Jumper wires

## Pin Connections
| PIC Pin | Function   | EEPROM Pin |
|---------|-----------|------------|
| RC3     | SCK       | SCK        |
| RC4     | MISO      | SO         |
| RC5     | MOSI      | SI         |
| RB0     | SS        | CS         |
| VCC     | +5V       | VCC        |
| GND     | GND       | GND        |

## How It Works
1. Initialize UART for debug messages  
2. Configure SPI pins and initialize SPI  
3. Enable EEPROM write (`0x06`)  
4. Write data to a 16-bit address  
5. Disable EEPROM write (`0x04`)  
6. Continuously read the stored byte and display it via UART


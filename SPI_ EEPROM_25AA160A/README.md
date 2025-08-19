# EEPROM (25AA160A) using SPI with PIC16F877A

This project shows how to writes and reads data from a 25AA160A EEPROM using SPI, displays it on a 16x2 LCD, and sends messages through UART.

## Components
- PIC16F877A  
- 25AA160A SPI EEPROM  
- 16x2 LCD  
- UART (for debugging)  
- 5V Power Supply  


## Working
1. LCD shows "SPI EEPROM" at start.  
2. String "ashna" is written to EEPROM.  
3. The string is read back and shown on LCD and UART.  

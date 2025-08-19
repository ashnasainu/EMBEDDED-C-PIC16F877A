# EMBEDDED C PROGRAMMING 

This repository contains fundamental Embedded C programs focused on microcontroller-based applications, including handling external interrupts and other embedded system concepts. It is intended for beginners and enthusiasts to understand and practice core Embedded C programming concepts.

## 📂 REPOSITORY STRUCTURE : 

- **EXTERNAL INTERRUPT SWITCH** - Implementation of external interrupt switch using embedded C in MPLAB.

- **TIMER 0_LED BLINKING** - Implementation of LED blinking with timer 0 using embedded C in MPLAB.

- **LED MULTIPLEXING_TIMER INTERRUPT** - Implementation of  LED multiplexing with timer interrupt using embedded C in MPLAB.

- **UART (Universal Asynchronous Receiver-Transmitter)** - Implementation of UART communication with LED blinking using  embedded C in MPLAB.

- **LCD 8-Bit Display** - lmplementation of LCD (16x2) in 8-bit mode with a PIC16F887A microcontroller.

- **LCD 4-Bit Display** - lmplementation of LCD (16x2) in 4-bit mode with a PIC16F887A and scroll a message to the left.

- **LCD 4-Bit Display with UART** - lmplementation of LCD (16x2) in 4-bit mode & UART with a PIC16F887A microcontroller.

- **VARIABLE RESISTOR INTERFACING** - Implementation of a variable resistor interfacing with the PIC16F887A microcontroller
using its ADC& the digitized analog value is displayed on a 16x2 character LCD.     

- **2 VARIABLE RESISTOR INTERFACING** - Implementation of 2 variable resistor interfacing with the PIC16F887A microcontroller
using its ADC& the digitized analog value is displayed on a 16x2 character LCD. 

- **UART COMMUNICATION TRANSMIT & RECEIVE** - Implementation of UART communication_ Transmit & Receive using a PIC16F887A microcontroller. It receives a string over UART and responds with a predefined reply.

- **RELAY INTERFACING** - Implementation of relay interfacing using a PIC16F887A microcontroller.

- **4x3_KEYPAD INTERFACING** - Implementation of 4x3 matrix keypad to the PIC16F887A microcontroller and display the pressed key on a 16x2 LCD.

- **DIGITAL_LOCKER SYSTEM** - Implementation of how to enter a 4-digit password using a keypad, and shows if it's correct on a 16x2 LCD.

- **CALCULATOR _4x4** - Implementation of a basic calculator using a 4x4 keypad and 16x2 LCD with a PIC16F887A microcontroller.It allows to enter two numbers and an operator (`+`, `-`, `*`, `/`) to display the result on the LCD.

_**INTERNAL EEPROM_PIC16F877A** - This project shows how to write and read data from INTERNAL EEPROM of PIC16F877A and display it on a 16x2 LCD.

_**RTC (DS1307) using I2C with PIC16F877A** - This project shows how to write , read and set time from an RTC using I2C with PIC16F877A and display it on a 16x2 LCD, and send messages through UART.

_**EEPROM (25AA160A) using SPI with PIC16F877A**- This project shows how to writes and reads data from a 25AA160A EEPROM using SPI, displays it on a 16x2 LCD, and sends messages through UART.

_**EEPROM (24C04) using I2C with PIC16F877A** - This project writes and reads data from 24C04 EEPROM using I2C with PIC16F877A, shows it on a 16x2 LCD, and sends messages to UART.


                                                                           
## 🔧 Getting Started  

### PREREQUISITES  

- Microcontroller (PIC16F887A)  
- MPLAB X IDE installed.  
- MPLAB XC8 Compiler.  
- PIC development board and necessary hardware components.  

### COMPILATION & EXECUTION

1. **Open MPLAB X IDE**  
   - Create a new project and select your target PIC microcontroller.  
   - Choose the **MPLAB XC8 Compiler**.  

2. **Add the Source Code**  
   - Copy and paste the C code into main.c.  
   - Configure the necessary registers for your external interrupt.  

3. **Build the Project**  
   - Click on **Build Project (F11)** to compile the code.  

4. **Flash the Code to the Microcontroller**  
   - Connect your programmer (e.g., PICkit 3/4).  
   - Click on **Make and Program Device (F5)** to upload the code.  

5. **Run & Test**  
   - Power on your microcontroller and verify the interrupt functionality. 
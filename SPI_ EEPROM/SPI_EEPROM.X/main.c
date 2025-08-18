#include <xc.h>
#include "SPI.h"
#include "LCD.h"
#include "UART.h"
#define _XTAL_FREQ 20000000

void main(void)
{
    unsigned char data=' ';
    TRISD = 0x00;    // port d as output
    lcd_initialise();
    lcd_set_cursor(1,2);
    lcd_string("SPI EEPROM");
    __delay_ms(5);
    
    UART_init();     // Initialize UART
    UART_write_string("UART Initialized\r\n");
 
    SPI_init();
    UART_write_string("SPI initialised\r\n");
    __delay_ms(500);
    
    //write_to_25AA106A(0x00 ,0x08,'a');                  // write function  for single character
    write_string_25AA106A(0x00,0x08, "ashna");            // write function  for string
    UART_write_string("Write function performed\r\n");
    __delay_ms(500);
    
    unsigned char DATA[10]=" "; 
    
    while(1)
    {
        //data=read_from_25AA160A(0x00,0x08);                   // read function  for single character
        read_string_25AA160A(0x00,0x08,DATA);                   // read function  for string
        //UART_write(data);                                     // to see the data received (for single character)
        UART_write_string(DATA);                                // to see the data received (for string)
        UART_write_string("\r\n");
        UART_write_string("Read function performed\r\n");
        __delay_ms(1000);
        lcd_set_cursor(2,4);
        UART_write_string("lcd cursor setting\r\n");
        //lcd_data(data);                                        // for single character
        lcd_string(DATA);                                        // for string
        __delay_ms(500);
        UART_write_string("DATA prints on LCD\r\n");
        __delay_ms(1000);
    }

    return;
}

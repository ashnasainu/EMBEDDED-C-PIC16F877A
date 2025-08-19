#include <xc.h>
#include "config.h"
#include "EEPROM.h"
#include "LCD.h"
#include "I2C.h"
#include "UART.h"
#include <string.h>

#define _XTAL_FREQ 20000000


void main(void)
{
    TRISC = 0xFF;    // port c as input  (SDA & SCL)
    TRISD = 0x00;    // port d as output
  
    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1, 0);
    lcd_string("EEPROM_I2C");
    lcd_set_cursor(2, 0);

    I2C_init();

    UART_init();     // Initialize UART
    UART_write_string("UART Initialized\r\n");
    __delay_ms(500);

    //EEPROM_24C04_write(0x18,'b');                         // for single character
    EEPROM_24C04_write_string(0x30, "ASHNA");                   //  for string
    UART_write_string("EEPROM write performed\r\n");
    __delay_ms(500);
    //UART_write('a'); 
    __delay_ms(500);
    UART_write_string("\r\n");
    
    //unsigned char data=' ';
    unsigned char DATA[10]=" ";

    while (1)
    {
        
        //data=EEPROM_24C04_read(0x18);                            // for single character
        //UART_write(data);                                        // to see the data received (for single character)
        EEPROM_24C04_read_string(0x30,DATA);
        UART_write_string(DATA);                                   // for string
        UART_write_string("\r\n");
        UART_write_string("Read function performed\r\n");
        __delay_ms(1000);
        lcd_set_cursor(2,4);
        UART_write_string("lcd cursor setting\r\n");
        //lcd_data(data);                                           // for single character
        lcd_string(DATA);                                           // for string
        __delay_ms(500);
        UART_write_string("DATA prints on LCD\r\n");
        __delay_ms(1000);
    }
    
    return;
}
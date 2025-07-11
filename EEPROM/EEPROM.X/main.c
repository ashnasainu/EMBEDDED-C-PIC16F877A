#include <xc.h>
#include "confi.h"
#include "EEPROM.h"
#include "LCD.h"
#define _XTAL_FREQ 20000000


void main(void)
{
   
    TRISB=0x00;                                      
    lcd_initialise();
    lcd_set_cursor(1,2);
    lcd_string("EEPROM");
     __delay_ms(5);
    
    while(1)
    {
        /*char x=0;                       // for single character
        EEPROM_write(0x90,'c');
        x=EEPROM_read(0x90);
        lcd_data(x);*/
        
       
        char x=0;
        unsigned char DATA[10]="";                    // for string
        EEPROM_write_string(0x90,"ashna");
      
        EEPROM_read_string(0x90,DATA);
        lcd_set_cursor(2,2);
        lcd_string(DATA);  
        __delay_ms(5000);
        
    }
   
}
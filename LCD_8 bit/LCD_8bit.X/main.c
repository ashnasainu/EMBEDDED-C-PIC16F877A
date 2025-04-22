#include <xc.h>
#include "config.h"
#include "LCD_8bit.h"
#define _XTAL_FREQ 20000000


void main(void) 
{
    TRISC=0x00;
    TRISD=0x00;
    lcd_initialise();
    
    while(1)
    {
      lcd_command(0x83);  
      lcd_string("EMBEDDED",8);
      lcd_command(0xc4);  
      lcd_string("SYSTEMS",7);
      
    }
    
    return;
}





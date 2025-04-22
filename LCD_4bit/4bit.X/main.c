#include <xc.h>
#include "config.h"
#include "4bit.h"
#define _XTAL_FREQ 20000000


void main(void) 
{
    TRISB=0x00;
    lcd_initialise();
    lcd_command(0x80);  
    lcd_string((const unsigned char *)"EMBEDDED SYSTEMS",16);  
    __delay_ms(500);
    lcd_leftscroll(16);
    
    while(1)
    {
      
    }
    
    return;
}


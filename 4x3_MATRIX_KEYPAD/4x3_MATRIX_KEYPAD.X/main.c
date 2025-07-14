#include <xc.h>
#include "config.h"
#include "LCD.h"
#include "keypad.h"
#define _XTAL_FREQ 20000000


void main(void) 
{
    TRISD=0x00;    // setting port D as output
    TRISB=0xF0; // setting rows as input & coloumns as output
    OPTION_REGbits.nRBPU = 0;  //enabling pullup resistor
    lcd_initialise();
    lcd_set_cursor(1,0);
    lcd_string("keypad:"); 
    __delay_ms(2000);
    lcd_set_cursor(2,0);
   
    while(1)
    {      
        keypad();     
    __delay_ms(250);
    }
    
    return;
}



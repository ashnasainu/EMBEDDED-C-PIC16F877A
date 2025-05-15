#include <stdio.h>
#include <xc.h>
#include "config.h"
#include "LCD.h"
#include "ADC.h"


int ADC_data=0 ;
unsigned char ADC_string[15]="";

void main(void) 
{
    TRISB=0x00;
    lcd_initialise();
    ADC_initialise();
   
    while(1)
    {      
        lcd_set_cursor(1,0);
        lcd_string("Pot value:");  
        ADC_data =ADC_read();
        integer_string(ADC_data,ADC_string);
        lcd_string(ADC_string); 
     }
    
    return;
}



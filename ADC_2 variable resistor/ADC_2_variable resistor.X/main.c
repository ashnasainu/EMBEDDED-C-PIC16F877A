#include <stdio.h>
#include <xc.h>
#include "config.h"
#include "LCD.h"
#include "ADC.h"


int ADC_data=0;
unsigned char ADC_string[15]="";

void main(void) 
{
    TRISB=0x00;
    lcd_initialise();
    ADC_initialise();
   
    while(1)
    {      
        ADC_data =ADC_read(0);
        lcd_set_cursor(1,0);
        lcd_string("Pot value:");  
        lcd_int(ADC_data);
        
        ADC_data =ADC_read(1);
        lcd_set_cursor(2,0);
        lcd_string("Pot value:");  
        lcd_int(ADC_data);   
     }
    
    return;
}



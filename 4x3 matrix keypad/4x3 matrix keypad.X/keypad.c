#include <xc.h>
#include "keypad.h"
#include "LCD.h"

#define C1  PORTBbits.RB0   
#define C2  PORTBbits.RB1  
#define C3  PORTBbits.RB2 
#define R1  PORTBbits.RB4   
#define R2  PORTBbits.RB5  
#define R3  PORTBbits.RB6 
#define R4  PORTBbits.RB7 


void keypad()
{
    C1=1;C2=0;C3=0;
    if(R1==1)
    {
        lcd_data('1');
        while(R1==1);
    }
    if(R2==1)
    {
        lcd_data('4');
        while(R2==1);
    }
    if(R3==1)
    {
        lcd_data('7');
        while(R3==1);
    }
    if(R4==1)
    {
        lcd_data('*');
        while(R4==1);
    }
    
    C1=0;C2=1;C3=0;
    if(R1==1)
    {
        lcd_data('2');
        while(R1==1);
    }
    if(R2==1)
    {
        lcd_data('5');
        while(R2==1);
    }
    if(R3==1)
    {
        lcd_data('8');
        while(R3==1);
    }
    if(R4==1)
    {
        lcd_data('0');
        while(R4==1);
    }
    
    C1=0;C2=0;C3=1;
    if(R1==1)
    {
        lcd_data('3');
        while(R1==1);
    }
    if(R2==1)
    {
        lcd_data('6');
        while(R2==1);
    }
    if(R3==1)
    {
        lcd_data('9');
        while(R3==1);
    }
    if(R4==1)
    {
        lcd_data('#');
        while(R4==1);
    }
    
}

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


char keypad()              // logic done using pull up resistor ; because the pic doesnit has pull down resistor . pull up or pull down resisitor is needed to avoid floating.
{
    char pressed_data = 0;
    
    while(pressed_data==0)
    {
        C1=0;C2=1;C3=1;
        if(R1==0)
        {
            pressed_data='1';
            while(R1==0);  // keep the number displayed as long as the corresponding switch is pressed ( also to avoid repeated same values)
        }
        if(R2==0)
        {
            pressed_data='4';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='7';
            while(R3==0);
        }
        if(R4==0)
        {
            pressed_data='*';
            while(R4==0);
        }

        C1=1;C2=0;C3=1;
        if(R1==0)
        {
            pressed_data='2';
            while(R1==0);
        }
        if(R2==0)
        {
            pressed_data='5';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='8';
            while(R3==0);
        }
        if(R4==0)
        {
            pressed_data='0';
            while(R4==0);
        }

        C1=1;C2=1;C3=0;
        if(R1==0)
        {
            pressed_data='3';
            while(R1==0);
        }
        if(R2==0)
        {
            pressed_data='6';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='9';
            while(R3==0);
        }
        if(R4==0)
        {
           pressed_data = '#';
            while(R4==0);
        }
    } 
    
    
    return pressed_data;
}

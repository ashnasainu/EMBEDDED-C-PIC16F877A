#include <xc.h>
#include "keypad.h"
#include "LCD.h"

char keypad()              // logic done using pull up resistor ; because the pic doesnit has pull down resistor . pull up or pull down resisitor is needed to avoid floating.
{
    char pressed_data=' ';
    while(pressed_data==' ')
    {
        C1=0;C2=1;C3=1;C4=1;
        if(R1==0)
        {
            pressed_data='7';
            while(R1==0);  // keep the number displayed as long as the corresponding switch is pressed ( also to avoid repeated same values)
        }
        if(R2==0)
        {
            pressed_data='4';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='1';
            while(R3==0);
        }
        if(R4==0)
        {
            pressed_data='c';
            while(R4==0);
        }

        C1=1;C2=0;C3=1;C4=1;
        if(R1==0)
        {
            pressed_data='8';
            while(R1==0);
        }
        if(R2==0)
        {
            pressed_data='5';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='2';
            while(R3==0);
        }
        if(R4==0)
        {
            pressed_data='0';
            while(R4==0);
        }

        C1=1;C2=1;C3=0;C4=1;
        if(R1==0)
        {
            pressed_data='9';
            while(R1==0);
        }
        if(R2==0)
        {
            pressed_data='6';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='3';
            while(R3==0);
        }
        if(R4==0)
        {
            pressed_data='=';
            while(R4==0);
        }

        C1=1;C2=1;C3=1;C4=0;
        if(R1==0)
        {
            pressed_data='/';
            while(R1==0);
        }
        if(R2==0)
        {
            pressed_data='*';
            while(R2==0);
        }
        if(R3==0)
        {
            pressed_data='-';
            while(R3==0);
        }
        if(R4==0)
        {
            pressed_data='+';
            while(R4==0);
        }
    }
    
    return pressed_data;  
    
}

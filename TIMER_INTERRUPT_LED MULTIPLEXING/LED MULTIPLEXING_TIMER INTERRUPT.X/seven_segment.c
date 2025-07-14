#include "seven_segment.h"
#include <xc.h>
#define _XTAL_FREQ 20000000

void seven_segment_init()
{
//ANSEL = 0; // Configure Analog pins as digital I/O
//ANSELH = 0;

    TRISD=0x00;
    TRISB=0X00;
    PORTD=0X00;
    digit1 = 0;
    digit2 = 0; 
    digit3 = 0;
    digit4 = 0;
}

void seven_segment_show(int i)
{
    unsigned char seven_segment[] ={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    PORTD=seven_segment[i];
    
}

#include "config.h"    
#define _XTAL_FREQ 20000000  // Define the system clock as 20MHz
#include <xc.h>

unsigned char timer_count = 0;  // Volatile to ensure updates in ISR

void __interrupt() timer_0()
{   
    INTCONbits.GIE=0; // for turn off all other interrupts

    if(INTCONbits.TMR0IF==1)
    {
        timer_count++;
        INTCONbits.TMR0IF=0;
        TMR0 = 59; // for 10mS delay
    }
    INTCONbits.GIE=1;

}
void main(void) 
{
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    INTCONbits.TMR0IE=1;
    
    OPTION_REG= 0x07;
    TMR0 = 59; // for 10mS delay
    
    TRISB0=0; 
    while(1) 
    {
        if(timer_count==0)
        {
            PORTBbits.RB0=1;
        }
        if(timer_count==100)
        {
           PORTBbits.RB0=0; 
        }
        if(timer_count==200)
        {
            timer_count=0;
        }
            
    }
            
    return;
}
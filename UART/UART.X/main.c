#include "config.h"
#include <xc.h>

unsigned char y = 0;  // Volatile to ensure updates in ISR

void __interrupt() receive()
{   
    INTCONbits.GIE=0; // for turn off all other interrupts

    if(PIR1bits.RCIF==1)
    {
        y=RCREG;
        
        PIR1bits.RCIF=0;
    }
    INTCONbits.GIE=1;

}
void main(void) 
{
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIE1bits.RCIE=1;
    
    TXSTA=0X24;
    RCSTA=0X90;
    
    SPBRG=129;
    
    TRISC=0X80;
    TRISB=0;
    PORTBbits.RB0=0;
    
   
    while(1) 
    {
        if(y=='a')
        {
            PORTBbits.RB0=1;
        }
        else if(y=='b')
        {
           PORTBbits.RB0=0;
        }
        
    }
            
    return;
}

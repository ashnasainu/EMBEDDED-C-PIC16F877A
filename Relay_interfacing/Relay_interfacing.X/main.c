#include <xc.h>
#include "config.h"

void main(void)
{
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB1=0;
    
    while(1)
    {
        if(PORTBbits.RB0==1)
        {
            PORTBbits.RB1=1;
        }
        else
        {
            PORTBbits.RB1=0;
        }     
    }
    
   return;
}

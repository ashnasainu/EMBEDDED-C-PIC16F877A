#include <xc.h>
#include "config.h"
#include "relay.h"

void main(void)
{
    relay_init();
    
    while(1)
    {
        int button_status=button_pressed();
        if(button_status==1)
        {
          relay_on();  
        }
        else
        {
          relay_off();  
        }       
    }
    
   return;
}


/*void main(void)
{
    TRISBbits.TRISB0=1;   // set as input
    TRISBbits.TRISB1=0;   // set as output
    
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
}*/

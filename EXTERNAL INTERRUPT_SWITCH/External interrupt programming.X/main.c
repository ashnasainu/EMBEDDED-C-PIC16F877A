#include "config.h"
#include <xc.h>

void __interrupt() external()
{
    if(INTCONbits.INTF==1)
    {
        PORTDbits.RD0=~PORTDbits.RD0;
        INTCONbits.INTF=0;
    }
     
}

void main(void) 
{
    ANSELH=0; //To change pin from analog to digital
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    INTCONbits.INTE=1;
    
    OPTION_REGbits.INTEDG=1;
    
    TRISD0=0;
    PORTDbits.RD0 = 0; 
    while(1)
    {
        
    }
            
    return;
}


/*
void main()
{
 TRISD0=0;//SET AS OUTPUT LED
 TRISB0=1;//SET AS INPUT  BUTTON
 PORTDbits.RD0=0;
 ANSELH=0;
 while(1)
 {
  if(PORTBbits.RB0==1)    // CHECKING IF THE SWITCH IS PRESSED OR NOT
  {
   PORTDbits.RD0=1;    //TURN ON LED , IF THE LED IS IN OFF STATE
  }
  else
  {
   PORTDbits.RD0=0;   // TURN OFF LED , IF THE LED IS IN ON STATE
  }
 }
}
*/
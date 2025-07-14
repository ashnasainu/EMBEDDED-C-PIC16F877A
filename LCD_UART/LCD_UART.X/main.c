#include <xc.h>
#include "confi.h"
#include "LCD.h"
#include "UART.h"
#define _XTAL_FREQ 20000000


void main(void) 
{
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIE1bits.RCIE=1;
    
    TXSTA=0X24; // setting register for UART
    RCSTA=0X90; // setting register for UART
    SPBRG=129; //  setting baud rate for UART
    
    TRISB=0x00; // setting Register B  as output
    TRISC=0X80; // setting  RC7 as input and the rest of PORTC (RC0 to RC6) as output
    PORTCbits.RC1=0; // setting RC1 to low initially
    
    lcd_initialise();
    
           lcd_clear();                   // This set of code is for just print some initial data while turning on LCD
           lcd_set_cursor(1,2);  
           lcd_string("LED UART",8); //
           lcd_set_cursor(2,5);
           lcd_string("TEST",4);
           __delay_ms(2000);
           
           
    
    while(1) 
    {
        if(data=='a')
        {
            PORTCbits.RC1=1;
            lcd_clear();
            lcd_set_cursor(1,5); 
            lcd_string("LED ON",6);
            lcd_set_cursor(2,4);  
            lcd_data(data);
            data=0;
            
        }
        else if(data=='b')
        {
           PORTCbits.RC1=0;
           lcd_clear();
           lcd_set_cursor(1,5);  
           lcd_string("LED OFF",7);
           lcd_set_cursor(2,4);  
           lcd_data(data);
           data=0;
          
        }   
        
         
           
        
        
    }
            
    return;
}
     
    
    
    
    
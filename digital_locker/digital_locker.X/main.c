#include <xc.h>
#include <string.h>
#include "confi.h"
#include "LCD.h"
#include "keypad.h"
#define _XTAL_FREQ 20000000

void main(void) 
{
    TRISD=0x00;                         // setting port D as output
    TRISB=0xF0;                         // setting rows as input & coloumns as output
    TRISC0=0x00;
    PORTCbits.RC0=0;  
    
    OPTION_REGbits.nRBPU = 0;           //enabling pull-up resistor
    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1,0);
    lcd_string("ENTER PASSWORD"); 
    __delay_ms(1000);
    lcd_set_cursor(2,5);
    char correct_password[5]="1234";
    char read_password[5]=" "; 
    int i=0;
   
    while(1)
    {   
        for(i=0;i<4;i++)
        {
           read_password[i]=keypad(); 
           lcd_data(read_password[i]);
        }
        
        read_password[4]='\0';
                 
        __delay_ms(1000);
      
        char data=strcmp(read_password, correct_password);
         
        if(data==0)
        {
            lcd_clear();
            lcd_set_cursor(1,0);
            lcd_string("CORRECT PASSWORD"); 
             PORTCbits.RC0=1;
            
        }
        else
        {
            lcd_clear();
            lcd_set_cursor(1,0);
            lcd_string("WRONG PASSWORD"); 
        }
        
        
        
        
        /*read_password=keypad(); 
        lcd_data(read_password);
        __delay_ms(1000);
      
        
        if(read_password==correct_password)
        {
            lcd_clear();
            lcd_set_cursor(1,0);
            lcd_string("CORRECT PASSWORD"); 
        }
        else
        {
            lcd_clear();
            lcd_set_cursor(1,0);
            lcd_string("WRONG PASSWORD"); 
        }*/
        
    }
    
    return;
}

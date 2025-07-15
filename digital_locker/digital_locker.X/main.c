#include <xc.h>
#include <string.h>
#include "confi.h"
#include "LCD.h"
#include "keypad.h"
#include "EEPROM.h"
#define _XTAL_FREQ 20000000

void main(void) 
{
    TRISD=0x00;                         // setting port D as output
    TRISB=0xF0;                         // setting rows as input & coloumns as output
    TRISC0=0x00;
    PORTCbits.RC0=0;  
    
    OPTION_REGbits.nRBPU = 0;           //enabling pull-up resistor
    lcd_initialise();
    unsigned char read_password[5]=" "; 
    unsigned char correct_password[5]=" ";
    int i=0;
    char data_enter=' ';
    int wrong_psw=0;
   //EEPROM_write_string(0x90,"2580");
    while(1)
    {
        
        lcd_clear();
        lcd_set_cursor(1,0);
        lcd_string("ENTER PASSWORD"); 
        
        
        EEPROM_read_string(0x90,correct_password);
        lcd_set_cursor(2,5);    
        
        for(i=0;i<4;i++)
        {
           read_password[i]=keypad(); 
           lcd_data(read_password[i]);
        }
        
        read_password[4]='\0';
      
        char data=strcmp(read_password, correct_password);
         
        if(data==0)
        {
            lcd_clear();
            lcd_set_cursor(1,4);
            lcd_string("UNLOCKED"); 
            PORTCbits.RC0=1;
            __delay_ms(1000);
            lcd_clear();
            lcd_set_cursor(1,4);
            lcd_string("LOCK:*"); 
            lcd_set_cursor(2,4);
            lcd_string("NEW PSW:#"); 
            PORTCbits.RC0=1;
            __delay_ms(1000);
            
            char data_enter=' ';
            while(data_enter!='*'&& data_enter!='#')
            {
                data_enter=keypad();  
               
                if(data_enter=='*')
                {
                    
                    lcd_clear();
                    lcd_set_cursor(1,6);
                    lcd_data(data_enter);
                    __delay_ms(1000);

                    lcd_set_cursor(2,4);
                    lcd_string("LOCKED"); 
                    __delay_ms(1000);
                    PORTCbits.RC0=0;
                     

                }
                
                else if(data_enter=='#')
                {
                    lcd_clear();
                    lcd_set_cursor(1,6);
                    lcd_data(data_enter);
                    __delay_ms(1000); 
                    lcd_clear();

                    lcd_set_cursor(1,0);
                    lcd_string("ENTER NEW PSW"); 
                    PORTCbits.RC0=0;
                    
                    
                    lcd_set_cursor(2,4);
                    for(i=0;i<4;i++)
                    {
                       read_password[i]=keypad(); 
                       lcd_data(read_password[i]);
                    }

                    read_password[4]='\0';
              
                    EEPROM_write_string(0x90,read_password);
                    lcd_clear();
                    lcd_set_cursor(1,3);
                    lcd_string("PSW CHANGED"); 
                    __delay_ms(1000); 
                }
                
            }   
        }
        
        else
        {
            lcd_clear();
            lcd_set_cursor(1,0);
            lcd_string("WRONG PASSWORD"); 
            __delay_ms(1000);
            wrong_psw++;  
                    
        }
        if(wrong_psw==4)
        {
           lcd_clear();
           lcd_set_cursor(1,3);
           lcd_string("LOCKED"); 
           __delay_ms(10000);
        }
        
    }
    
    return;
}

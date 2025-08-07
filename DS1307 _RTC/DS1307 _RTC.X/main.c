#include <xc.h>
#include "rtc.h"
#include "LCD.h"
#include <string.h>
#define _XTAL_FREQ 20000000


void main(void)
{
    TRISC=0XFF;     // port c as input
    TRISD = 0x00;   // Set all pins of PORTD as output (0 = output, 1 = input)
    TRISB = 0XFF;   // Set RB0 as input
    PORTBbits.RB0 = 0;  // position button set as low
    PORTBbits.RB1 = 0;  // increment button set as low
   
    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1,0);
    lcd_string("TIME");
    lcd_set_cursor(2,0);
   
    SSPCON=40;     // CONTROL REGISTER 2 (I2C MODE)  
    SSPADD=0x3f;   // I2C speed ,setting I2C clock(slave = RTC)  to be 100 KHz , getting from data sheet of DS1307
    int sec = 0;int min=0;int hr=0;int position_button_count=0;
    
   
    while(1)
    {  
       while(1)
        {
           if(PORTBbits.RB0==1)
           {
    
              position_button_count++;
               
               while(PORTBbits.RB0==1);
           }
           else if(position_button_count==0)
           {
               break;
           }
            
            if(position_button_count==1)
            {
                if(PORTBbits.RB1==1)
                {
                    lcd_set_cursor(2,0);
                    hr++;
                    if(hr>23)
                    {
                        hr=0;
                    }
                    
                    if(hr<10)
                    {
                        lcd_data('0');
                    }
                    
                    lcd_int(hr); 
                    lcd_data(':');
                    while(PORTBbits.RB1==1);
                    
                }
            }
            
            if(position_button_count==2)
            {
                if(PORTBbits.RB1==1)
                {
    
                    lcd_set_cursor(2,3);
                    min++;
                    if(min>59)
                    {
                        min=0;
                    }
                    
                    if(min<10)
                    {
                        lcd_data('0');
                    }
                    lcd_int(min);
                    lcd_data(':');
                    while(PORTBbits.RB1==1);
                }
            }
            
            if(position_button_count==3)
            {
                if(PORTBbits.RB1==1)
                {
    
                    lcd_set_cursor(2,6);
                    sec++;
                    if(sec>59)
                    {
                        sec=0;
                        
                    }
                    
                    if(sec<10)
                    {
                        lcd_data('0');
                    }
                    lcd_int(sec);
                    while(PORTBbits.RB1==1);
                }
            }
            
            if(position_button_count==4)
            {
                rtc_write(sec,min,hr);
                break;
            }
        }
        position_button_count=0;
        
        rtc_read(0xD0, 0x00, &sec, &min, &hr); 
        lcd_set_cursor(2,10);
        
        if(hr>12)
        {
          lcd_string("PM");  
        }
        else
        {
           lcd_string("AM");  
        }
        lcd_set_cursor(2,0);
        
        if(hr>12)
         
        {    
            hr=hr-12;   
        }
        
        if(hr<10)
        {
           lcd_data('0');
        }
      
        lcd_int(hr);       // int to string & displays on LCD
        lcd_data(':');
        
        lcd_int(min);      
        lcd_data(':');
        
                    
        if(sec<10)
        {
           lcd_data('0');
        }
        lcd_int(sec);
       
        __delay_ms(1000);       
     
    //return;
  }
    return;
}
#include <xc.h>
#include "rtc.h"
#include "LCD.h"
#include <string.h>
#define _XTAL_FREQ 20000000


void main(void)
{
    TRISC=0XFF;     // port c as input
    TRISD = 0x00;   // Set all pins of PORTD as output (0 = output, 1 = input)
    
    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1,0);
    lcd_string("TIME:");
   
    SSPCON=40;     // CONTROL REGISTER 2 (I2C MODE)  
    SSPADD=0x3f;   // I2C speed ,setting I2C clock(slave = RTC)  to be 100 KHz , getting from data sheet of DS1307
    int sec = 0;int min=0;int hr=0;
   
    rtc_write(20,50,10);         // sec;min;hr   
   
    while(1)
    {   
        rtc_read(0xD0, 0x00, &sec, &min, &hr); 
        lcd_set_cursor(1,6);
        //rtc_dispaly_time(sec,min,hr);
        lcd_int(hr);       // int to string & displays on LCD
        lcd_data(':');
        lcd_int(min);       // int to string & displays on LCD
        lcd_data(':');
        lcd_int(sec);
        
        __delay_ms(1000);               
    }  
     
    return;
}
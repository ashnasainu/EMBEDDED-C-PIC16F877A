#include <xc.h>
#include "rtc.h"
#include "LCD.h"
#include <string.h>
#define _XTAL_FREQ 20000000

void main(void)
{
    TRISC=0XFF;         // port c as input   , I2C pins setting as input (SDL , SDA))
    TRISD = 0x00;       // Set all pins of PORTD as output (0 = output, 1 = input)
    PORTD=0X00;
    SSPADD=49;          // I2C speed ,setting I2C clock(slave = RTC)  to be 100 KHz , getting from data sheet of DS1307
    SSPCON=0x28;        // CONTROL REGISTER 2 (I2C MODE)  
    
    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1,0);
    lcd_string("CLOCK:");
    lcd_set_cursor(2,0);
    lcd_string("CLOCK:");
    DS1307_write(3,2,1,1,5,4,20);
    __delay_ms(500);
        
    while(1)
    {
        DS1307_read(DS1307_address,0);           // Reading from the RTC
        __delay_ms(20);                           // Delay (optional) 
    }  
    return;
}

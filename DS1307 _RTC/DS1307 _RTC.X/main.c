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
    lcd_string("CLOCK:");
    __delay_ms(2000);
    
    SSPCON=40;     // CONTROL REGISTER 2 (I2C MODE)  
    SSPADD=0x3f;   // I2C speed ,setting I2C clock(slave = RTC)  to be 100 KHz , getting from data sheet of DS1307
    unsigned char hour=' ';
    char DATA[10]=" ";
   
    while(1)
    {
        rtc_write(1);            // Write 1 to the RTC
        __delay_ms(200);           // Delay (optional)
        
        hour=rtc_read();  
        bcd_to_ascii(0x45,DATA); // Read back the hour
        lcd_set_cursor(2,6);
        lcd_string("  ");        // Clear old data
         lcd_set_cursor(2,6);
        lcd_string(DATA);
        __delay_ms(200); 
       
    }  
    return;
}

#include "LCD_8bit.h"
#include <xc.h>
#define _XTAL_FREQ 20000000

#define RS  PORTCbits.RC0   // Register Select Pin (instruction or data register))
#define RW  PORTCbits.RC1   // Read/Write Pin 
#define EN  PORTCbits.RC2   // Enable Pin

void lcd_initialise()
{
    lcd_command(0x38);
    lcd_command(0x06);
    lcd_command(0x0c);
    lcd_command(0x01);
    
}


void lcd_data(unsigned char data)
{
    PORTD=data;
    RS=1;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
}

void lcd_command(unsigned char cmnd)
{
    PORTD=cmnd;
    RS=0;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
}

void lcd_string(const unsigned char *str,unsigned char num)
{
    unsigned char i;
    for(i=0;i<num;i++)
    {
        lcd_data(str[i]);
    }
}

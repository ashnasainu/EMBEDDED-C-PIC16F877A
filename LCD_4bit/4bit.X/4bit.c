#include "4bit.h"
#include <xc.h>
#define _XTAL_FREQ 20000000

#define RS  PORTBbits.RB0   // Register Select Pin (instruction or data register))
#define RW  PORTBbits.RB1   // Read/Write Pin 
#define EN  PORTBbits.RB2   // Enable Pin

void lcd_initialise()
{
    
    lcd_command(0x28); // Set LCD to 4-bit mode 
    
    lcd_command(0x0C); // Turn on display, hide cursor
    
    lcd_command(0x01); // Clear the screen
    

}


void lcd_data(unsigned char data)
{
    PORTB=(data&0xf0);
    RS=1;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
    PORTB=((data<<4)&0xf0);
    RS=1;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
    
}

void lcd_command(unsigned char cmnd)
{
    PORTB=cmnd&0xf0;
    RS=0;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
    PORTB=((cmnd<<4)&0xf0);
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

void lcd_leftscroll(unsigned char i)
{
    unsigned char count;
    for(count=0;count<i;count++)
    {
        lcd_command(0x18);
        __delay_ms(300);
    }
    
}


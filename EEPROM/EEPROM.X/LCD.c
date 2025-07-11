#include "LCD.h"
#include <xc.h>
#define _XTAL_FREQ 20000000

#define RS  PORTBbits.RB0   // Register Select Pin (instruction or data register))
#define RW  PORTBbits.RB1   // Read/Write Pin 
#define EN  PORTBbits.RB2   // Enable Pin


void lcd_initialise()
{ 
    lcd_command(0x28); // Set LCD to 4-bit mode 
    
    lcd_command(0x0C); // Turn on display, hide cursor
   
}

void lcd_clear()
{
    lcd_command(0x01); // Clear the screen 
}

void lcd_set_cursor(int a, int b)
{
    int cmnd=0x00;
    if(a==1)
    {
        cmnd=0x80;
    }
    else if(a==2)
    {
        cmnd=0xC0;
    }
    cmnd=cmnd+b;
    lcd_command(cmnd);
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

void lcd_string(const unsigned char *str)
{
    unsigned char i;
    for(i=0;str[i]!='\0';i++)
    {
        lcd_data(str[i]);
              
    }
    
}




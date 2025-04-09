#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000


#define RS  PORTDbits.RD0   // Register Select Pin (instruction or data register))
#define RW  PORTDbits.RD1   // Read/Write Pin 
#define EN  PORTDbits.RD2   // Enable Pin

void lcd_data(unsigned char data)
{
    PORTC=data;
    RS=1;
    RW=0;
    EN=1;
    __delay_ms(5);
    EN=0;
}

void lcd_command(unsigned char cmnd)
{
    PORTC=cmnd;
    RS=0;
    RW=0;
    EN=1;
    __delay_ms(5);
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

void lcd_initialise()
{
    lcd_command(0x38);
    lcd_command(0x06);
    lcd_command(0x0c);
    lcd_command(0x01);
    
}


void main(void) 
{
    TRISC=0x00;
    TRISD=0x00;
    lcd_initialise();
    
    while(1)
    {
      lcd_command(0x83);  
      lcd_string("EMBEDDED",8);
      lcd_command(0xc4);  
      lcd_string("SYSTEMS",7);
      
    }
    
    return;
}


// Program for showing special character too (here love symbol)

/*#define _XTAL_FREQ 8000000  // or whatever your oscillator frequency is

#define RS RD0
#define RW RD1
#define EN RD2

// Heart symbol (custom character)
unsigned char heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
};

void lcd_data(unsigned char data)
{
    PORTC = data;
    RS = 1;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
}

void lcd_command(unsigned char cmnd)
{
    PORTC = cmnd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
}

void lcd_string(const unsigned char *str, unsigned char num)
{
    unsigned char i;
    for(i = 0; i < num; i++)
    {
        lcd_data(str[i]);
    }
}

void lcd_initialise()
{
    lcd_command(0x38);  // 8-bit, 2-line, 5x7 font
    lcd_command(0x06);  // Auto-increment cursor
    lcd_command(0x0C);  // Display ON, cursor OFF
    lcd_command(0x01);  // Clear display
    __delay_ms(5);
}

void lcd_custom_char(unsigned char loc, unsigned char *symbol)
{
    int i;
    if(loc < 8)
    {
        lcd_command(0x40 + (loc * 8));  // Set CGRAM address
        for(i = 0; i < 8; i++)
        {
            lcd_data(symbol[i]);
        }
    }
}

void main(void) 
{
    TRISC = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
    
    lcd_initialise();
    
    lcd_custom_char(0, heart);  // Store heart symbol in CGRAM location 0
    
    while(1)
    {
        lcd_command(0x83);  
        lcd_string("ANEECHU", 7);

        lcd_command(0x8A);  // move cursor after ANEECHU
        lcd_data(0);        // show heart
        
        lcd_command(0xC4);  
        lcd_string("ATHUS", 5);
        
    }
}
*/




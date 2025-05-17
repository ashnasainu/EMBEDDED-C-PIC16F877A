#include "UART.h"
#include <xc.h>
#define _XTAL_FREQ 20000000

unsigned char y; // Volatile to ensure updates in ISRISR

void UART_init()
{
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIE1bits.RCIE=1;
    
    TXSTA=0X24;
    RCSTA=0X90;
    
    SPBRG=129;
    TRISC=0XC0 ;
}

void __interrupt() receive()
{   
    //INTCONbits.GIE=0; // for turn off all other interrupts

    if(PIR1bits.RCIF==1)
    {
     y = RCREG;
    }
    //INTCONbits.GIE=1;

}


char UART_receive()
{
    char temp =y;
    y=0;
    return temp;
}

void receive_string(unsigned char *string)
{
    //char string[]="\0";
    int i=0;
    char data=0;
    while(data!='\r')
    {
        data=UART_receive();
        if(data!=0)
        {
           if(data=='\r')
            {
                string[i++]='\0';
                //return string;
            }
            else
            {
               string[i]=data;
               i++; 
            }
                  
        }   
    }
}

void UART_write(char data)
{
    INTCONbits.GIE=0; // for turn off all other interrupts

    if(PIR1bits.TXIF==1)
    {
        TXREG=data;
        
        while(TRMT==0); //means data transmission is in process and TXREG still holds data
     
        PIR1bits.TXIF=0;
    }   
    INTCONbits.GIE=1;
}


void write_string(const unsigned char *str)
{
    unsigned char i;
    for(i=0;str[i]!='\0';i++)
    {
        UART_write(str[i]);        
    }
        UART_write('\r');       // Return to the beginning of the line
        __delay_ms(250);        // Optional delay
        
    
}




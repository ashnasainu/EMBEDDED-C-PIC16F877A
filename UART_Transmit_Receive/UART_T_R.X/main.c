#include <xc.h>
#include "config.h"
#include "UART.h"
#include <string.h>
#define _XTAL_FREQ 20000000

unsigned char data; // Volatile to ensure updates in ISRISR

void main(void) 
{
    UART_init();
    
    unsigned char string[10];

    while(1) 
        
    {
        
        receive_string(string);
        //write_string(string);
        
        if(strcmp("ashna",string)==0)
        {
            write_string("anees");
        }
        else if (strcmp("anees",string)==0)
        {
            write_string("ashna");
        }
        UART_write('\n');
    }
            
    return;
}
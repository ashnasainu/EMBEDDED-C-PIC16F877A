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
        /*
        data=UART_receive();
        
        if (data != 0)
        {
            UART_write(data);
            if (data == '\r')
            {
                string[i++] = '\0';
                if(strcmp("ashna",string)==0)
                {
                    write_string("anees");
                }
                else if (strcmp("anees",string)==0)
                {
                    write_string("ashna");
                }
                
                i = 0;  // Reset for next input
            }
            else if (data == '\b')
            {
                i=i--;
            }
            else if (i < 10)
            {
                //UART_write(y);
                string[i++] = data;
            }
            data = 0;  // Reset y after processing
        }*/
    }
            
    return;
}


     
    
    
    
    
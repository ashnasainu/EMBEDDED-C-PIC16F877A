#include <xc.h>
#include"config.h"
#include "rtc.h"
#include "LCD.h"
#include "I2C.h"
#include "UART.h"
#include <string.h>

#define _XTAL_FREQ 20000000


void main(void)
{
    TRISC = 0xFF;    // port c as input  (SDA & SCL)
    TRISD = 0x00;    // port d as output
    TRISB = 0xFF;    // port b input
    PORTBbits.RB0 = 0;
    PORTBbits.RB1 = 0;

    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1, 0);
    lcd_string("TIME");
    lcd_set_cursor(2, 0);

    I2C_init();

    UART_init();     // Initialize UART
    UART_write_string("UART Initialized\r\n");

    int sec = 0, min = 0, hr = 0, position_button_count = 0 , count=0;
    rtc_write(40,30,10);
    UART_write_string("set time write\r\n");
    UART_write_string("Starting main loop\r\n");

    while (1)
    {
        while (1)
        {
            if (PORTBbits.RB0 == 1)
            {
                position_button_count++;
                UART_write_string("Position button pressed. Count: ");
                UART_write('0' + position_button_count);
                UART_write_string("\r\n");

                while (PORTBbits.RB0 == 1);  // debounce
            }
            else if (position_button_count == 0)
            {
                UART_write_string("Position button count 0, exiting set mode\r\n");
                break;
            }

            if (position_button_count == 1)
            {
                if(count<5)                     // for blinking the position
                {
                    lcd_set_cursor(2, 0);
                    lcd_string("  ");           // 2 space need for string
                }
                else
                {
                    lcd_set_cursor(2, 0);
                    lcd_int(hr);   
                }
                   
                if(PORTBbits.RB1 == 1)
                {
                    lcd_set_cursor(2, 0);
                    hr++;
                    if (hr > 23) hr = 0;

                    UART_write_string("Hour set to: ");
                    UART_write_int(hr);                 // convert int to string and displays on UART terminal to see the data
                    //UART_write('0' + (hr / 10));
                    //UART_write('0' + (hr % 10));
                    UART_write_string("\r\n");

                    if (hr < 10) lcd_data('0');
                    lcd_int(hr);
                    lcd_data(':');
                    while (PORTBbits.RB1 == 1);  
                }
                
            }

            if (position_button_count == 2)
            {
                if(count<5)
                {
                    lcd_set_cursor(2, 3);
                    lcd_string("  ");
                }
                else
                {
                    lcd_set_cursor(2, 3);
                    lcd_int(min);   
                }
                if(PORTBbits.RB1 == 1)
                {
                    lcd_set_cursor(2, 3);
                    min++;
                    if (min > 59) min = 0;

                    UART_write_string("Minute set to: ");
                    UART_write_int(min);
                    //UART_write('0' + (min / 10));                // int to char to display on terminal
                    //UART_write('0' + (min % 10));
                    UART_write_string("\r\n");

                    if (min < 10) lcd_data('0');
                    lcd_int(min);
                    lcd_data(':');
                    while (PORTBbits.RB1 == 1);
                }
                
            }

            if (position_button_count == 3)
            {
                if(count<5)
                {
                    lcd_set_cursor(2, 6);
                    lcd_string("  ");
                }
                else
                {
                    lcd_set_cursor(2, 6);
                    lcd_int(sec);   
                }
                if(PORTBbits.RB1 == 1)
                {
                    lcd_set_cursor(2, 6);
                    sec++;
                    if (sec > 59) sec = 0;

                    UART_write_string("Second set to: ");
                    UART_write_int(sec);

                    UART_write_string("\r\n");

                    if (sec < 10) lcd_data('0');
                    lcd_int(sec);
                    while (PORTBbits.RB1 == 1); 
                }
                
            }

            if (position_button_count == 4)
            {
                rtc_write(sec, min, hr);
                UART_write_string("RTC time written.\r\n");
                break;
            }
            
             __delay_ms(50);
             count++;
             if(count>10)
             {
                count=0;
             }
            
        }

        position_button_count = 0;

        rtc_read(&sec, &min, &hr);

        UART_write_string("RTC time read: ");
        UART_write_int(hr);
     
        UART_write(':');
        UART_write_int(min);
   
        UART_write(':');
        UART_write_int(sec);
      
        UART_write_string("\r\n");

        lcd_set_cursor(2, 10);
        if (hr > 12)
            lcd_string("PM");
        else
            lcd_string("AM");

        lcd_set_cursor(2, 0);
        if (hr > 12) hr -= 12;

        if (hr < 10) lcd_data('0');
        lcd_int(hr);
        lcd_data(':');

        if (min < 10) lcd_data('0');
        lcd_int(min);
        lcd_data(':');

        if (sec < 10) lcd_data('0');
        lcd_int(sec);

        __delay_ms(100);
    }
}
#include <xc.h>
#include "rtc.h"
#include "LCD.h"
#include "I2C.h"
#include <string.h>

#define _XTAL_FREQ 20000000

// Declare UART functions from your header
void UART_write(char data);
void write_string(const unsigned char *str);
void UART_init();
char UART_receive();
void receive_string(unsigned char *string);

void main(void)
{
    TRISC = 0xFF;    // port c as input
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
    write_string("UART Initialized\r\n");

    int sec = 0, min = 0, hr = 0, position_button_count = 0;
    write_string("Starting main loop\r\n");

    while (1)
    {
        while (1)
        {
            if (PORTBbits.RB0 == 1)
            {
                position_button_count++;
                write_string("Position button pressed. Count: ");
                UART_write('0' + position_button_count);
                write_string("\r\n");

                while (PORTBbits.RB0 == 1);  // debounce
            }
            else if (position_button_count == 0)
            {
                write_string("Position button count 0, exiting set mode\r\n");
                break;
            }

            if (position_button_count == 1 && PORTBbits.RB1 == 1)
            {
                lcd_set_cursor(2, 0);
                hr++;
                if (hr > 23) hr = 0;

                write_string("Hour set to: ");
                UART_write('0' + (hr / 10));
                UART_write('0' + (hr % 10));
                write_string("\r\n");

                if (hr < 10) lcd_data('0');
                lcd_int(hr);
                lcd_data(':');
                while (PORTBbits.RB1 == 1);
            }

            if (position_button_count == 2 && PORTBbits.RB1 == 1)
            {
                lcd_set_cursor(2, 3);
                min++;
                if (min > 59) min = 0;

                write_string("Minute set to: ");
                UART_write('0' + (min / 10));
                UART_write('0' + (min % 10));
                write_string("\r\n");

                if (min < 10) lcd_data('0');
                lcd_int(min);
                lcd_data(':');
                while (PORTBbits.RB1 == 1);
            }

            if (position_button_count == 3 && PORTBbits.RB1 == 1)
            {
                lcd_set_cursor(2, 6);
                sec++;
                if (sec > 59) sec = 0;

                write_string("Second set to: ");
                UART_write('0' + (sec / 10));
                UART_write('0' + (sec % 10));
                write_string("\r\n");

                if (sec < 10) lcd_data('0');
                lcd_int(sec);
                while (PORTBbits.RB1 == 1);
            }

            if (position_button_count == 4)
            {
                rtc_write(sec, min, hr);
                write_string("RTC time written.\r\n");
                break;
            }
        }

        position_button_count = 0;

        rtc_read(0xD0, 0x00, &sec, &min, &hr);

        write_string("RTC time read: ");
        UART_write('0' + (hr / 10));
        UART_write('0' + (hr % 10));
        UART_write(':');
        UART_write('0' + (min / 10));
        UART_write('0' + (min % 10));
        UART_write(':');
        UART_write('0' + (sec / 10));
        UART_write('0' + (sec % 10));
        write_string("\r\n");

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

        __delay_ms(1000);
    }
}

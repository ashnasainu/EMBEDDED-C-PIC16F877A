#include <xc.h>
#include "UART.h"
#include <string.h>
#include <stdio.h>

#define _XTAL_FREQ 20000000

// Initialize UART for 9600 baud @ 20MHz, enable TX and RX
void UART_init()
{
    TXSTA = 0x24;    // TXEN=1 (enable TX), BRGH=1 (high speed)
    RCSTA = 0x90;    // SPEN=1 (serial port enabled), CREN=1 (enable continuous receive)
    SPBRG = 129;     // Baud rate setting for 9600 baud at 20MHz
    TRISCbits.TRISC6 = 0;  // TX pin output
    TRISCbits.TRISC7 = 1;  // RX pin input
}

// Receive one character via UART (polling)
char UART_receive()
{
    // Wait until data received
    while (PIR1bits.RCIF == 0);

    // Handle overrun error if any
    if (RCSTAbits.OERR)
    {
        CREN = 0;  // Reset receiver
        NOP();
        CREN = 1;
    }

    return RCREG;  // Return received byte
}

// Receive a string via UART, terminated by carriage return '\r'
void receive_string(unsigned char *string)
{
    int i = 0;
    char data = 0;

    while (1)
    {
        data = UART_receive();

        if (data == '\r') // carriage return = end of string
        {
            string[i] = '\0';  // null-terminate string
            break;
        }
        else if (data != 0)
        {
            string[i++] = data;
        }
    }
}

// Transmit a single character via UART
void UART_write(char data)
{
    // Wait until transmit buffer is empty
    while (!PIR1bits.TXIF);

    TXREG = data;  // Load data into transmit register

    // Wait until transmit shift register is empty (transmission complete)
    while (!TRMT);
}

// Transmit a null-terminated string via UART
void write_string(const unsigned char *str)
{
    unsigned char i = 0;

    while (str[i] != '\0')
    {
        UART_write(str[i++]);
    }

    UART_write('\n');  // Newline (LF)
    UART_write('\r');  // Carriage return (CR)

    __delay_ms(250);   // Optional delay to allow transmission to finish
}
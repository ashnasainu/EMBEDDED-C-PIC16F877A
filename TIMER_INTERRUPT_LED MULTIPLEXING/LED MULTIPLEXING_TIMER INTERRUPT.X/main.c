#include <xc.h>  // Include XC8 library for PIC microcontroller
#include "config.h"  // Include configuration settings
#include "seven_segment.h"  // Include the seven-segment display driver

#define _XTAL_FREQ 20000000  // Define crystal frequency for delay calculations

// Define digit control pins for the seven-segment display
#define digit1 PORTBbits.RB3  
#define digit2 PORTBbits.RB2  
#define digit3 PORTBbits.RB1  
#define digit4 PORTBbits.RB0  

// Timer0 initial value for generating a 10ms delay
int Timer_start_value = 59;  

// Variables to hold individual digits of the displayed number
int a, b, c, d;  
unsigned char timer_count = 0;  // Counter for multiplexing display digits

// Interrupt Service Routine (ISR) for Timer0
void __interrupt() timer_0()
{
    INTCONbits.GIE = 0; // Disable global interrupts to avoid conflicts

    if (INTCONbits.TMR0IF == 1)  // Check if Timer0 overflow flag is set
    {
        if (timer_count == 4)  
        {
            timer_count = 0;  // Reset counter after displaying all four digits
        }
        
        // Display logic: Turn off the previous digit and update the next one
        if (timer_count == 0)
        {
            digit4 = 0;  // Turn off the last(fourth) digit
            seven_segment_show(a);  // Show thousands place value
            digit1 = 1;  // Turn on the first digit
        }
        if (timer_count == 1)
        {
            digit1 = 0;  // Turn off previous (first) digit )
            seven_segment_show(b);  // Show hundreds place value
            digit2 = 1;  // Turn on the second digit
        }
        if (timer_count == 2)
        {
            digit2 = 0;  // Turn off previous (second )digit
            seven_segment_show(c);  // Show tens place value
            digit3 = 1;  // Turn on the third digit 
        }
        if (timer_count == 3)
        {
            digit3 = 0;  // Turn off previous(third) digit
            seven_segment_show(d);  // Show ones place value
            digit4 = 1;  // Turn on the fourth digit
        }
        
        timer_count++;  // Move to the next digit for multiplexing
        TMR0 = Timer_start_value;  // Reload Timer0 for the next 10ms interval
        INTCONbits.TMR0IF = 0;  // Clear Timer0 interrupt flag
    }

    INTCONbits.GIE = 1; // Re-enable global interrupts
}

void main() 
{ 
    // Enable interrupts
    INTCONbits.GIE = 1;  // Global Interrupt Enable
    INTCONbits.PEIE = 1; // Peripheral Interrupt Enable
    INTCONbits.TMR0IE = 1; // Enable Timer0 interrupt
    
    OPTION_REG = 0x07;  // Configure Timer0 prescaler (1:256)
    TMR0 = Timer_start_value;  // Load initial value for Timer0 (10ms delay)

    seven_segment_init();  // Initialize the seven-segment display

    unsigned int counter = 0;  // Variable to store the number to be displayed
   
    while(1)  // Infinite loop for continuously updating the display
    {
        // Extract individual digits from the counter
        a = counter / 1000;   // Thousands place
        b = (counter / 100) % 10; // Hundreds place
        c = (counter / 10) % 10;  // Tens place
        d = counter % 10;  // Units place
        
        counter++;  // Increment the counter
        
        if (counter > 9999)  // Reset the counter after reaching 9999
        {
            counter = 0;
        }

        __delay_ms(1000);  // Delay 1 second before updating the counter
    }
}

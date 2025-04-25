unsigned char y = 0;  // Volatile to ensure updates in ISR

void __interrupt() receive()
{
    INTCONbits.GIE=0; // for turn off all other interrupts

    if(PIR1bits.RCIF==1)
    {
        y=RCREG;
        
        PIR1bits.RCIF=0;
    }
    INTCONbits.GIE=1;
}
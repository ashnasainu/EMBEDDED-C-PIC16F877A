#include "ADC.h"
#include <xc.h>
#include <stdio.h>

unsigned int ADC_value,a,b,c,d,e,e,f =0;

void ADC_initialise(void)
{
    ADCON0 = 0x41;
    ADCON1 = 0x8e;
    
    // setting configurations for ADC peripheral
    
    /*ADCON0bits.ADCS0=1; ADCON0bits.ADCS1=0; ADCON1bits.ADCS2=0;  // setting ADC fr (main fr /8)
    ADCON0bits.ADON=1;    // Power up ADC module
    ADCON1bits.PCFG0=0; ADCON1bits.PCFG1=1; ADCON1bits.PCFG2=1; ADCON1bits.PCFG3=1;   // Port configuration (setting A0 only as analog pin)
    ADCON1bits.ADFM=1;    //  A/D result format select bit (here select right justified format method)*/
}


int ADC_read()
{
    ADCON0bits.CHS0=0;                                       // Reading portion of ADC
    ADCON0bits.CHS1=0;                                       // selecting channel 0 (AN0)
    ADCON0bits.CHS2=0;   
   
    ADCON0bits.GO_DONE = 1; // Start conversion
    while(PIR1bits.ADIF == 0); // Wait for conversion to complete

    ADC_value = ADRESH << 8;
    ADC_value = ADC_value + ADRESL;
    PIR1bits.ADIF = 0; // Clear ADC interrupt flag
    return ADC_value; 
}


/*// Let ADC_value = 1023
void ADC_data(int ADC_DATA)
{      
        a = ADC_DATA / 10;               // a=102                 // print ADC value
        b= ADC_DATA % 10;                // b=3
        c=a/10 ;                          // c=10
        d = a%10;                         // d=2
        e = c/10 ;                        //e =1
        f=c%10;                           //f=0
}*/

void integer_string(int ADC_data,unsigned char *buffer)
{
    sprintf (buffer, "%d",ADC_data);  // Now buffer holds the string "1024"
}


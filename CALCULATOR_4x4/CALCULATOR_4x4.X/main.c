#include <xc.h>
#include <string.h>
#include <stdio.h>
#include "confi.h"
#include "LCD.h"
#include "keypad.h"
#define _XTAL_FREQ 20000000


void main(void) 
{
    TRISD=0x00;                // setting port D as output
    TRISB=0xF0;                // setting rows as input & coloumns as output
    OPTION_REGbits.nRBPU = 0;  //enabling pullup resistor
    lcd_initialise();
    lcd_clear();
    lcd_set_cursor(1,3);
    lcd_string("CALCULATOR");
    __delay_ms(500);
    lcd_clear();
    lcd_set_cursor(1,0);
    char result[5] =" ";
    int value=0;
    char operant=' ';
    char operator=' ';
    int num1=0;
    int num2=0;
    unsigned char A[10]=" "; 
    unsigned char B[10]=" "; 
    int i=0;
    
     
    while(1)
    {
        i=0;
        while(1)
        {
           A[i]=keypad(); 
           
           if(A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/')
           {
               operant=A[i];
               break;
           }
           lcd_data(A[i]);
           i++;
        }
        
        A[i]='\0';
        sscanf(A, "%d", &num1);  // num1 will hold int value of str
       
        lcd_data(operant);
       
        i=0;
        while(1)
        {
           B[i]=keypad(); 
           
           if(B[i]=='+'||B[i]=='-'||B[i]=='*'||B[i]=='/'||B[i]=='=')
           {
               operator=B[i];
               break;
           }
           lcd_data(B[i]);
           i++;
        }
        
        B[4]='\0';
        sscanf(B, "%d", &num2);  // num2 will hold int value of str
     
        lcd_data(operator);
        
        
        if(operant=='+')
        {
            value=num1+num2; 
        }
        
        else if(operant=='-')
        {
            value=num1-num2;  
        }
        
        else if(operant=='*')
        {
            value=num1*num2;  
        }
        else if(operant=='/')
        {
            value=num1/num2;   
        }
        
        lcd_set_cursor(2,0);
        lcd_int(value);

        __delay_ms(1000);
          
    }   
       
    return;
}

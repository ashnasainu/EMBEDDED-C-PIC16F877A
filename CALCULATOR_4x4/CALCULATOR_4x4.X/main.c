#include <xc.h>
#include <string.h>
#include <stdio.h>
#include "confi.h"
#include "LCD.h"
#include "keypad.h"
#define _XTAL_FREQ 20000000

int operations(int num1,int num2,char operant)    
{                                                 
   int value=0;
   switch(operant)
    {
      case '+':
       value=num1+num2;
       break;
      case '-':
       value=num1-num2;
       break;
      case '*':
       value=num1*num2;
       break;
      case '/':
       value=num1/num2;
       break;
    }
    return value;
}


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
    int value=0;
    char operant=' ';
    int num1=0;
    int num2=0;
    char A[10]=" "; 
    char data=' ';
    int i=0;
    
    while(1)
    {
        lcd_clear();
        i=0;
        operant='+';
        value=0;
        
        while(1)
        {
           data=keypad(); 
           
           if(data=='c')
           {
               break;
           }
           else if(data=='+'||data=='-'||data=='*'||data=='/'||data=='=')
           { 
               A[i]='\0';
               sscanf(A, "%d", &num1);  
               value=operations(value,num1,operant);
               operant=data;
               lcd_data(operant);
                
               if(data=='=')
               {
                   break;
               }
               
               i=-1;
           }
           else
           {
               A[i]=data;
               lcd_data(A[i]);
           }
           i++;   
        }
   
        lcd_set_cursor(2,0);
        lcd_int(value);

        while(data!='c')
            {
                data=keypad();  
            }   
    }  
    return;

}

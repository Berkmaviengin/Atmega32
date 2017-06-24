/*
 * GccApplication1.c
 *
 * Created: 13.4.2016 18:50:56
 *  Author: User
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRC=0x00; //configuring PortC pin 0 as input
   PORTC=0x00; 
   DDRB=0x01; // configuring PortB as output
   PORTB=0x00; // buzzer/LED off
  
    while(1)
    {
         
         if((PINC&(1<<0)))
         {
         PORTB=0x01;
         _delay_ms(500);
         PORTB=0x00;
         }
         else
         PORTB=0x00;    
    }
    return 0;
}

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
   DDRB =0x03;
  
    while(1)
    {
         
         PORTB=0x02;
         _delay_ms(10);
         PORTB=0x00;
         _delay_ms(10);
         PORTB=0x01;
         _delay_ms(10);
         PORTB=0x00;
         _delay_ms(10);
         
         
         
         
    }
}

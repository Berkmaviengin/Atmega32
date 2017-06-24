/*
 * ADC_ALICI.c
 *
 * Created: 21.6.2016 17:02:51
 *  Author: User
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRD |= (1 << PIND0);//PORTD pin0 as INPUT
	int UBRR_Value = 25; // 2400 baud rate
	UBRRH = (unsigned char) (UBRR_Value >> 8);
	UBRRL = (unsigned char) UBRR_Value;
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << USBS) | (3 << UCSZ0);
	DDRB |=(1<<PINB0)|(1<<PINB1)|(1<<PINB2);
	DDRC |=(1<<PINC0);
	DDRC |=(1<<PINC1);
	unsigned char rb;
	
    while(1)
    {
		rb=UDR;
        while (! (UCSRA & (1 << RXC)) );
        
       
        
        if (rb == 0b11110000)
        {
	        PORTB |=(1<<PINB0) | (1<<PINB2); /////1=>PB2///2=>PB1///3=>PB0
	        PORTB &= ~(1 << PINB1);
        }
		else if (rb==0b11111000)
		{
			PORTB |=(1<<PINB1) | (1<<PINB2);
			PORTB &= ~(1 << PINB0);
		}
		else if (rb==0b00001111)
		{
			PORTC |=(1<<PINC0);	
		}
		else if (rb==0b00011111)
		{
			PORTC &= ~(1 << PINC0);
		}
		 
    }
}
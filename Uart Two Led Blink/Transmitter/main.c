/*
 * GccApplication1.c
 *
 * Created: 13.4.2016 18:50:56
 *  Author: User
 */ 

#include <avr/io.h>
//header to enable data flow control over pins
#define F_CPU 1000000UL
//telling controller crystal frequency attached
#include <util/delay.h>
//header to enable delay function in program
 
int main(void)
{
                DDRD |= 1 << PIND1;//pin1 of portD as OUTPUT
                DDRD &= ~(1 << PIND0);//pin0 of portD as INPUT
                PORTD |= 1 << PIND0;
                DDRC=(0<<PINC0);
                PORTC=1<<PINC0;
 
                int UBBRValue = 25;//AS described before setting baud rate
 
                //Put the upper part of the baud number here (bits 8 to 11)
                UBRRH = (unsigned char) (UBBRValue >> 8);
 
                //Put the remaining part of the baud number here
                UBRRL = (unsigned char) UBBRValue;
 
                //Enable the receiver and transmitter
                UCSRB = (1 << RXEN) | (1 << TXEN);
 
                //Set 2 stop bits and data bit length is 8-bit
                UCSRC = (1 << USBS) | (3 << UCSZ0);
 
                while (1)
                {
                                if (bit_is_clear(PINC,0))//once button is pressed
                                {
                                               
                                                while (! (UCSRA & (1 << UDRE)) );
                                                {
                                                                UDR = 0b11110000;//once transmitter is ready sent eight bit data
                                                }
 
                                                // Get that data outa here!
                                               
                                                _delay_ms(220);
                                }         
                }
        
       
}        
         
         
  

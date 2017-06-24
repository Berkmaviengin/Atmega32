#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
                DDRD |= (1 << PIND0);//PORTD pin0 as INPUT
                DDRC=0xFF;//PORTC as OUTPUT
 
                int UBRR_Value = 25; // 2400 baud rate
                UBRRH = (unsigned char) (UBRR_Value >> 8);
                UBRRL = (unsigned char) UBRR_Value;
                UCSRB = (1 << RXEN) | (1 << TXEN);
                UCSRC = (1 << USBS) | (3 << UCSZ0);
 
                unsigned char receiveData;
                while (1)
                {
                                while (! (UCSRA & (1 << RXC)) );
 
                                receiveData = UDR;
 
                                if (receiveData == 0b11110000)
                                {
                                          PORTC ^= (1 << PINC0);
                                           _delay_ms(220);
                                }
                }
}

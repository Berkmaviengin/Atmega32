/*
 * GccApplication2.c
 *
 * Created: 29.4.2016 12:27:56
 *  Author: User
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{

  
   DDRB |=(1<<PINB0)|(1<<PINB1)|(1<<PINB2);
   DDRD |=(1<<PIND0);
   DDRC |=(1<<PINC7);
  
   ADCSRA |= 1<<ADPS2;
   ADMUX |= 1<<REFS0 | 1<<REFS1;
   ADCSRA |= 1<<ADIE;
   ADCSRA |= 1<<ADEN;

   sei();

   ADCSRA |= 1<<ADSC;

   while (1)
   {
   }
}
ISR(ADC_vect)
{
   uint8_t theLow = ADCL;
   uint16_t OnBitlikSonuc = ADCH<<8 | theLow;

   switch (ADMUX)
   {  
      case 0xC0:
         

         if (OnBitlikSonuc<500) ///soil measure ==>A0
         {
            PORTB |=(1<<PINB0) | (1<<PINB2); /////1=>PB2///2=>PB1///3=>PB0
            PORTB &= ~(1 << PINB1);
            
         }
         else
         {
            PORTB |=(1<<PINB1) | (1<<PINB2);
            PORTB &= ~(1 << PINB0);
            
         }
         ADMUX = 0xC1;
         
         break;
      case 0xC1:
         if (OnBitlikSonuc<170)  ///// fire sensor =>A1
         {
            PORTD |=(1<<PIND0); ////Buzzer=> D0
            
            
         }
         else
         {
            PORTD &= ~(1 << PIND0);
         }
         ADMUX = 0xC2;
         
         break;
      case 0xC2:   ////PIR=>A3
         if (OnBitlikSonuc>400)
         {
            PORTC |=(1<<PINC7);
            
            
         }
         else
         {
            PORTC&= ~(1 << PINC7);
            
         }
         ADMUX = 0xC0;
         
         break;   
      default:
//Default code
         break;
   } ADCSRA |= 1<<ADSC;
}




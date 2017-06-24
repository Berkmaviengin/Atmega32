/*
 * Main.c
 *
 * Created: 4.5.2016 13:35:28
 *  Author: User
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 4000000UL
#include <util/delay.h>

#define DataPort   PORTC   
#define DataDDR      DDRC

//Interrupt Service Routine for INT0
ISR(INT0_vect)
{
   unsigned char i, temp;
   
   _delay_ms(500); // Software debouncing control
   
   temp = DataPort;   // Save current value on DataPort
   
   /* This for loop blink LEDs on Dataport 5 times*/
   for(i = 0; i<5; i++)
   {
      DataPort = 0x00;
      _delay_ms(500);   
      DataPort = 0xFF;
      _delay_ms(500);   
   }
   
   DataPort = temp;   //Restore old value to DataPort
}
ISR(INT1_vect){
   unsigned char b, temp1;
   _delay_ms(500);
   temp1 = DataPort;
   
   for(b = 0; b<5; b++)
   {
      PORTC=0x05 ;
      _delay_ms(500);
   }
   
   DataPort =temp1;
   
}

int main(void)
{
   DDRD = 1<<PD2;      // Set PD2 as input (Using for interupt INT0)
   PORTD = 1<<PD2;      // Enable PD2 pull-up resistor
   DDRD = 1<<PD3;
   PORTD = 1<< PD3;
   DataDDR = 0xFF;      
   DataPort = 0x01;   
   
   GICR = 1<<INT0 | 1<<INT1;// Enable INT0
   
   MCUCR = 1<<ISC01 | 1<<ISC00;   //int0 ve int1 aktif
   MCUCR = 1<<ISC11 | 1<<ISC10;
   
   sei();            //Enable Global Interrupt
   
   while(1)
   {
      if(DataPort >= 0x80)
      DataPort = 1;
      else
      DataPort = DataPort << 1;   
      
      _delay_ms(500);   
   }
}

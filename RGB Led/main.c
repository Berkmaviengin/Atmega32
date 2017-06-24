/*
 * RGB-Led.c
 *
 * Created: 13.4.2016 18:50:56
 *  Author: Berk
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

   DDRB =0xFF;
   PORTB = 11111011; 
   DDRA=0x00;
   PORTA = 0x07;

    while(1)
    {
      if(!(PINA&0x01)){       //1. Button Push
         PORTB = 11111101;    // Green
         _delay_ms(25);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(25);
         PORTB = 11111011;    //Blue
         _delay_ms(25);
         PORTB = 11111101;    // Green
         _delay_ms(25);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(25);
         PORTB = 11111011;    //Blue
         _delay_ms(25);
         PORTB = 11111101;    // Green
         _delay_ms(25);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(25);
         PORTB = 11111011;    //Blue
         _delay_ms(25);
         PORTB = 11111101;    // Green
         _delay_ms(25);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(25);
         PORTB = 11111011;    //Blue
         _delay_ms(25);
         PORTB = 11111101;    // Green
         _delay_ms(25);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(25);
         PORTB = 11111011;    //Blue
         _delay_ms(25);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         PORTB = 11111101;    // Green
         _delay_ms(10);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(10);
         PORTB = 11111011;    //Blue
         _delay_ms(10);
         
         
         
      }            
      if(!(PINA&0x02)){                   //2. button Push
         PORTB = 11111101;    // Green
         _delay_ms(100);      // 1 second delay
         PORTB = 11111110;    //red
         _delay_ms(100);
         PORTB = 11111011;    //Blue
         _delay_ms(100); 
      }
      if(!(PINA&0x04)){                   //3. button Push
         PORTB = 11111101;    // Green
         _delay_ms(50);// 1 second delay
         PORTB = 11111111;
         _delay_ms(50);
         PORTB = 11111101;    // Green
         _delay_ms(50);// 1 second delay
         PORTB = 11111111;
         _delay_ms(50);
         PORTB = 11111110;    //red
         _delay_ms(50);
         PORTB = 11111111;
         _delay_ms(50);
         PORTB = 11111110;    //red
         _delay_ms(50);
         PORTB = 11111111;
         _delay_ms(50);
         PORTB = 11111011;    //Blue
         _delay_ms(50);
         PORTB = 11111111;
         _delay_ms(50);
         PORTB = 11111011;    //Blue
         _delay_ms(50);
         PORTB = 11111111;
         _delay_ms(50);
         
      }            
    }
}

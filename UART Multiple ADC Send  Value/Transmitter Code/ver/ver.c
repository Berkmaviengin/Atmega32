#define F_CPU 16000000UL
#define BAUD 9600
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)

#define TRUE 1
#define FALSE 0

#define CHAR_NEWLINE '\n'
#define CHAR_RETURN '\r'
#define RETURN_NEWLINE "\r\n"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <string.h>

// The inputted commands are never going to be
// more than 8 chars long. Volatile for the ISR.
volatile unsigned char data_in[8];
volatile unsigned char command_in[8];

volatile unsigned char data_count;
volatile unsigned char command_ready;

// Variables to hold current settings
unsigned int sensitivity = 223;

void usart_putc (char send)
{
	// Do nothing for a bit if there is already
	// data waiting in the hardware to be sent
	while ((UCSRA & (1 << UDRE)) == 0) {};
	UDR = send;
}

void usart_puts (const char *send)
{
	// Cycle through each character individually
	while (*send) {
		usart_putc(*send++);
	}
}

void usart_ok()
{
	usart_puts("OK\r\n");
}

void print_value (char *id, int *value)
{
	char buffer[8];
	itoa(value, buffer, 10);
	usart_putc(id);
	usart_putc(':');
	usart_puts(buffer);
	usart_puts(RETURN_NEWLINE);
}

void copy_command ()
{
	// The USART might interrupt this - don't let that happen!
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		// Copy the contents of data_in into command_in
		memcpy(command_in, data_in, 8);

		// Now clear data_in, the USART can reuse it now
		memset(data_in[0], 0, 8);
	}
}

unsigned long parse_assignment ()
{
	char *pch;
	char cmdValue[16];
	// Find the position the equals sign is
	// in the string, keep a pointer to it
	pch = strchr(command_in, '=');
	// Copy everything after that point into
	// the buffer variable
	strcpy(cmdValue, pch+1);
	// Now turn this value into an integer and
	// return it to the caller.
	return atoi(cmdValue);
}


void process_command()
{
	switch (command_in[0]) {
		case 'S':
		if (command_in[1] == '?') {
			// Do the query action for S
			print_value('S', sensitivity);
			} else if (command_in[1] == '=') {
			sensitivity = parse_assignment();
		}
		break;
		case 'M':
		if (command_in[1] == '?') {
			// Do the query action for M
			} else if (command_in[1] == '=') {
			// Do the set action for M
		}
		break;
		default:
		usart_puts("NOT RECOGNISED\r\n");
		break;
	}
}

int main(void)
{
	// Turn on USART hardware (RX, TX)
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	// 8 bit char sizes
	UCSRC |= (1 << UCSZ0) | (1 << UCSZ1);
	// Set baud rate
	UBRRH = (BAUD_PRESCALE >> 8);
	UBRRL = BAUD_PRESCALE;
	// Enable the USART Receive interrupt
	UCSRB |= (1 << RXCIE );

	// Globally enable interrupts
	sei();

	while(1) {

		if (command_ready == TRUE) {
			copy_command();
			process_command();

			command_ready = FALSE;
			usart_ok();
		}

	}
}

ISR (USART_RX_vect)
{
	// Get data from the USART in register
	data_in[data_count] = UDR;

	// End of line!
	if (data_in[data_count] == '\n') {
		command_ready = TRUE;
		// Reset to 0, ready to go again
		data_count = 0;
		} else {
		data_count++;
	}
}
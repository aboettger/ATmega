#include <avr/io.h>
#include <util/delay.h>

#define BIT_0 0

int main(void) {
	// Set LED pin for output
    DDRD |= (1 << PD0);
    DDRD |= (1 << PD1);
    DDRD |= (1 << PD2);
    DDRD |= (1 << PD3);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);
    DDRD |= (1 << PD6);
    DDRD |= (1 << PD7);
    while (1) {

	// 00000001
	//PORTB ^= (1 << 0);

	// 00000011
	//PORTD ^= (1 << 0) | (1 << 1);
	// alternativ
	// PORTB |= (1 << 0);
	PORTD ^= (1 << 0);
	PORTD ^= (1 << 1);
	_delay_ms(1000);
    }
    return (0);
}

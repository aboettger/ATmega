/* Blinker Demo II */

#include <avr/io.h>
#include <util/delay.h>

// Anzahl der LEDS
#define MAX_LEDS 6

#define LED_1      PC0
#define LED_2      PC1
#define LED_3      PC2
#define LED_4      PC3
#define LED_5      PC4
#define LED_6      PC5

#define LED_DDR  DDRC
#define LED_PORT PORTC

#define INPUT PINB

// 16MHz external clock source
#define DELAYTIME 16000

#define setBit(sfr, bit) (_SFR_BYTE(sfr) |= (1 << bit))
#define clearBit(sfr, bit) (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggleBit(sfr, bit) (_SFR_BYTE(sfr) ^= (1 << bit))

int main(void) {



// Set LED pin for output
setBit(LED_DDR, LED_1);
setBit(LED_DDR, LED_2);
setBit(LED_DDR, LED_3);
setBit(LED_DDR, LED_4);
setBit(LED_DDR, LED_5);
setBit(LED_DDR, LED_6);

while (1) {
	for(int i = 0; i < MAX_LEDS; i++) {
	_SFR_BYTE(LED_PORT) |= (1 << i);
	_delay_ms(DELAYTIME);
	_SFR_BYTE(LED_PORT) &= ~(1 << i);
	_delay_ms(DELAYTIME);
	}
}

return (0);
}

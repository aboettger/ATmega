/* Blinker Demo II */

#include <avr/io.h>
#include <util/delay.h>

#define LED_1 PC0
#define LED_2 PC1
#define LED_3 PC2
#define LED_4 PC3

#define LED_5 PD0
#define LED_6 PD1
#define LED_7 PD2

#define LED_DDR_COL_1  DDRC
#define LED_PORT_COL_1 PORTC
#define LED_DDR_COL_2  DDRD
#define LED_PORT_COL_2 PORTD

#define INPUT PINB

// 16MHz external clock source
#define DELAYTIME 16000

// Größte auszugebende Dezimalzahl
#define MAX_DEC 59

#define setBit(sfr, bit) (_SFR_BYTE(sfr) |= (1 << bit))
#define clearBit(sfr, bit) (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggleBit(sfr, bit) (_SFR_BYTE(sfr) ^= (1 << bit))

#define set_1_c_1() ( _SFR_BYTE(LED_PORT_COL_1) |= (1 << LED_1); _SFR_BYTE(LED_PORT_COL_1) &= ~(1 << LED_2); _SFR_BYTE(LED_PORT_COL_1) &= ~(1 << LED_3); _SFR_BYTE(LED_PORT_COL_1) &= ~(1 << LED_4))

/*
#define set_1_col_2() ( \
	_SFR_BYTE(LED_PORT_COL_2) |= (1 << LED_5); \
	_SFR_BYTE(LED_PORT_COL_2) &= ~(1 << LED_6); \
	_SFR_BYTE(LED_PORT_COL_2) &= ~(1 << LED_7) \
)
*/

int main(void) {

	// Set LED pin for output
	setBit(LED_DDR_COL_1, LED_1);
	setBit(LED_DDR_COL_1, LED_2);
	setBit(LED_DDR_COL_1, LED_3);
	setBit(LED_DDR_COL_1, LED_4);

	setBit(LED_DDR_COL_2, LED_5);
	setBit(LED_DDR_COL_2, LED_6);
	setBit(LED_DDR_COL_2, LED_7);

	for(int j = 0; j < 6; j++) {
		_SFR_BYTE(LED_PORT_COL_1) ^= (1 << LED_1);
		_SFR_BYTE(LED_PORT_COL_2) ^= (1 << LED_5);
		_delay_ms(1000);
		_SFR_BYTE(LED_PORT_COL_1) ^= (1 << LED_2);
		_SFR_BYTE(LED_PORT_COL_2) ^= (1 << LED_6);
		_delay_ms(1000);
		_SFR_BYTE(LED_PORT_COL_1) ^= (1 << LED_3);
		_SFR_BYTE(LED_PORT_COL_2) ^= (1 << LED_7);
		_delay_ms(1000);
		_SFR_BYTE(LED_PORT_COL_1) ^= (1 << LED_4);
		_delay_ms(1000);
	}

//	set_1_c_1();
//	set_1_col_2();

	return (0);
}

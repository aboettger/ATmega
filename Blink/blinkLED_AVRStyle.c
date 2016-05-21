                                                    /* Blinker Demo II */

#include <avr/io.h>
#include <util/delay.h>

#define LED_1      PC0
#define LED_2      PC1
#define LED_3      PC2
#define LED_4      PC3

#define LED_DDR  DDRC
#define LED_PORT PORTC

#define INPUT PINB

#define DELAYTIME 5000

// Anzahl der LEDS
#define MAX_LEDS 4
// Größte auszugebende Dezimalzahl
#define MAX_DEC 15

#define setBit(sfr, bit)     (_SFR_BYTE(sfr) |= (1 << bit))
#define clearBit(sfr, bit)   (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggleBit(sfr, bit)  (_SFR_BYTE(sfr) ^= (1 << bit))

int main(void) {



  // Set LED pin for output
  setBit(LED_DDR, LED_1);
  setBit(LED_DDR, LED_2);
  setBit(LED_DDR, LED_3);
  setBit(LED_DDR, LED_4);

  for(int j = 0; j < 6; j++) {
    for(int i = 0; i < MAX_LEDS; i++) {
      _SFR_BYTE(LED_PORT) ^= (1 << i);
      _delay_ms(1000);
    }
  }

  // Mainloop
  while (1) {
    _SFR_BYTE(LED_PORT) &= ~(1 << 0);
    _SFR_BYTE(LED_PORT) &= ~(1 << 1);
    _SFR_BYTE(LED_PORT) &= ~(1 << 2);
    _SFR_BYTE(LED_PORT) &= ~(1 << 3);
    if (INPUT & (1<<PINC0)) {
      for (int a = 0; a <= MAX_DEC; a++) {
          int b[MAX_LEDS];

          for (int i = 0, c = a; i <= MAX_LEDS; i++)
          {
              b[i] = c % 2;
              c >>= 1;
          }

          for(int i = MAX_LEDS; i >= 0; --i) {
              if(b[i]<0)
              {
                  b[i] = b[i] * -1;
              }
          }
          for(int i = 0; i < MAX_LEDS; i++) {
            if (b[i] == 0) {
              // clearBit
              _SFR_BYTE(LED_PORT) &= ~(1 << i);
            } else {
              // setBit
              _SFR_BYTE(LED_PORT) |= (1 << i);
            }
          }
          _delay_ms(DELAYTIME);
      }
    }
  }
  return (0);
}

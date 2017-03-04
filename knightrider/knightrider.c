#include <avr/io.h>
#include <util/delay.h>

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
    for (int i = 0; i < 8; i++ ) {
      _delay_ms(60);
      PORTD = (1 << i);
    }

    for (int i = 6; i > 0; i-- ) {
      _delay_ms(60);
      PORTD = (1 << i);
    }
  }
  return (0);
}

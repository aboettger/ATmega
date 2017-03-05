#include <avr/io.h>
#include <util/delay.h>

int main(void) {

  // Set LED pin for output
  // we need 7 bits
  DDRD = 127; // minutes
  // we need 5 bits
  DDRC = 63; // hours

  int minutes_high = 0;
  int minutes_low = 0;

  int hours_high = 0;
  int hours_low = 0;

  while (1) {
    for (int i = 0; i < 24; i++ ) {
      hours_high = i / 10;
      hours_low = i % 10;

      PORTC = (hours_high << 4) | hours_low;

      for (int i = 0; i < 60; i++ ) {
        minutes_high = i / 10;
        minutes_low = i % 10;

        PORTD = (minutes_high << 4) | minutes_low;

        // 60000
        _delay_ms(60000); // 600 - hundred times faster

      }
    }
  }
  return (0);
}

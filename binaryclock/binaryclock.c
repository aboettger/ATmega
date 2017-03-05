#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Set LED pin for output
  // we need 7 bits
  DDRD = 127; // seconds
  DDRC = 127; // minutes
  DDRB = 63; // hours

  int seconds_high = 0;
  int seconds_low = 0;

  int minutes_high = 0;
  int minutes_low = 0;

  int hours_high = 0;
  int hours_low = 0;

  while (1) {
    for (int i = 0; i < 24; i++ ) {
      hours_high = i / 10;
      hours_low = i % 10;

      PORTB = (hours_high << 4) | hours_low;

      for (int i = 0; i < 60; i++ ) {
        minutes_high = i / 10;
        minutes_low = i % 10;

        PORTC = (minutes_high << 4) | minutes_low;

        for (int i = 0; i < 60; i++ ) {
          seconds_high = i / 10;
          seconds_low = i % 10;

          PORTD = (seconds_high << 4) | seconds_low;

          _delay_ms(1000);
        }
      }
    }
  }
  return (0);
}

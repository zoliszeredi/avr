#include <avr/io.h>
#include <util/delay.h>


void blink_pin5() {
  while (1) {
    DDRB |= _BV(PB5);
    PORTB ^= _BV(PB5);
    _delay_ms(500);
  }
}

int main() {
  blink_pin5();
  return 0;
}

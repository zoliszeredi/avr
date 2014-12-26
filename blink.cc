#include <avr/io.h>
#include <util/delay.h>


void pwm() {
  DDRB |= _BV(PB1);
  TCCR1A |= _BV(COM1A1) | _BV(WGM10);
  TCCR1B |= _BV(CS10) | _BV(WGM12);

  uint8_t top = 0xff;
  uint8_t bottom = 0x00;
  uint8_t counter = bottom;
  uint8_t step = 1;

  for(;;) {
    OCR1A = counter;
    counter += step;
    if (counter == top || counter == bottom) {
      step *= -1;
    }
    _delay_ms(5);
  }
}


void blink_pin5() {
  while (1) {
    DDRB |= _BV(PB5);
    PORTB ^= _BV(PB5);
    _delay_ms(500);
  }
}


int main() {
  /* blink_pin5(); */
  pwm();
  return 0;
}

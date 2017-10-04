#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc.h"

void adc_init() {
  cli();

  ADMUX |= _BV(REFS0);
  ADCSRA |= _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2) | _BV(ADEN);
  ADCSRA |= _BV(ADSC);

  sei();
}

uint16_t adc_read(uint8_t channel) {
  ADMUX &= 0xf0;
  ADMUX |= channel;
  ADCSRA |= _BV(ADSC);
  while ( ADCSRA & _BV(ADIF) );
  ADCSRA |= _BV(ADIF);
  return (ADC);
}

Converter::Converter() {
  adc_init();
}

uint16_t Converter::read(uint8_t channel) {
  return adc_read(channel);
}

uint8_t Converter::read_ratio(uint8_t channel) {
  return (this->read(channel) * this->scale) >> this->resolution;
}

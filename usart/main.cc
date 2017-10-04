#include <avr/io.h>
#include <stdio.h>

#include "uart.h"
#include "adc.h"

int main(void) {
  uint16_t counter = 0;
  Converter c;
  Serial s;

  while(1) {
    s.write("[%5u] %d\n", counter++, c.read_ratio(PC5));
  }

  return 0;
}

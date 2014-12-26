#include <avr/io.h>
#include <stdio.h>

#include "uart.h"
#include "adc.h"

int main(void) {
  uart_init();
  stdout = stdin = fdevopen(uart_putchar, uart_getchar);
  uint16_t counter = 0, value = 0;

  adc_init();

  while(1) {
    value = adc_read(PC5) * 100 / 1024;
    printf("[%5u] %d\n", counter++, value);
  }

  return 0;
}

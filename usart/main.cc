#include <stdio.h>

#include "uart.h"

int main(void) {
  uart_init();
  stdout = stdin = fdevopen(uart_putchar, uart_getchar);
  char input;

  while(1) {
    puts("Hello, en vagyok a mikrokontroller!!");
    // input = getchar();
    // printf("You wrote %c\n", input);
  }

  return 0;
}

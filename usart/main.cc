/*
 * Demonstration on how to redirect stdio to UART.
 *
 * http://appelsiini.net/2011/simple-usart-with-avr-libc
 *
 * To compile and upload run: make clean; make; make program;
 * Connect to serial with: screen /dev/tty.usbserial-*
 *
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

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

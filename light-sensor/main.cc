#include <avr/io.h>
#include <stdint.h>

#include "sensor.h"


int main() {
  LightSensor sensor;
  uint16_t value;

  sensor.init();

  while (1) {
    value = sensor.read();
  }

  return 0;
}

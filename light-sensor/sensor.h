#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

class LightSensor {
 public:
  void init();
  uint16_t read();
};

#endif

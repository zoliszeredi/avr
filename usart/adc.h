#ifndef ADC_H
#define ADC_H

void adc_init();
uint16_t adc_read(uint8_t channel);

class Converter {
 private:
  static const uint8_t resolution = 10;
  static const uint8_t scale = 100;

 public:
  Converter();
  uint16_t read(uint8_t channel);
  uint8_t read_ratio(uint8_t channel);
};

#endif

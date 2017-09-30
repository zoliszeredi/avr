PRG = lightsensor
OBJ = main.o sensor.o
DEFS = "-DF_CPU=1600000UL"
MCU_TARGET = atmega328p
PART_NUMBER = m328p
ISP = avrisp2
LIBS =
CXX = avr-g++
OPTIMIZE = -Os
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
EXTRA_CLEAN_FILES = *.hex *.bin *.srec


override CXXFLAGS = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override LDFLAGS = -Wl,-Map,$(PRG).map

all: $(PRG).elf lst text
$(PRG).elf: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
main.o: main.cc
sensor.o: sensor.cc
clean:
	rm -rf *.o $(PRG).elf *.eps *.png *.pdf *.bak
	rm -rf *.lst *.map $(EXTRA_CLEAN_FILES)
lst: $(PRG).lst
%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@
text: hex bin #srec
hex: $(PRG).hex
bin: $(PRG).bin
# srec: $(PRG).srec
%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@
%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@
flash: $(PRG).hex
	avrdude -c $(ISP) -p $(PART_NUMBER) -U flash:w:$<

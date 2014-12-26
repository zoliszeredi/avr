PRG = uart
OBJ = uart.o main.o
DEFS = -D F_CPU=16000000UL -D BAUD=9600
MCU_TARGET = atmega328
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
uart.o: uart.cc
main.o: main.cc
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
	avrdude -cavrisp2 -pm328p -U flash:w:$<

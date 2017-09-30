PRG = uart
OBJ = uart.o main.o adc.o
DEFS = -D F_CPU=16000000UL -D BAUD=9600
ISP = avrisp2
LIBS =
CXX = avr-g++
OPTIMIZE = -Os
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
EXTRA_CLEAN_FILES = *.hex *.bin *.srec
MCU_TARGET = atmega328p
PART_NUMBER = m328p

# avr target codes
# https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html

# avrdude codes
# http://www.nongnu.org/avrdude/user-manual/avrdude_4.html


override CXXFLAGS = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override LDFLAGS = -Wl,-Map,$(PRG).map

all: $(PRG).elf lst text
$(PRG).elf: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
uart.o: uart.cc
adc.o: adc.cc
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
	avrdude -c $(ISP) -p $(PART_NUMBER) -U flash:w:$<

PRG = blink
OBJ = blink.o
DEFS = "-DF_CPU=16000000UL"
MCU_TARGET = atmega328
LIBS =
CC = avr-gcc
OPTIMIZE = -Os
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump


override CFLAGS = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override LDFLAGS = -Wl,-Map,$(PRG).map

all: $(PRG).elf lst text
$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

blink.o: blink.c
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

EXTRA_CLEAN_FILES = *.hex *.bin *.srec

flash: $(PRG).hex
	avrdude -cavrisp2 -pm328p -U flash:w:$<

CC = arm-none-eabi-gcc
CPU = cortex-m4
CFLAGS = -c -mcpu=$(CPU) -mthumb -std=gnu11 -Wall -O0
LDFLAGS = -nostdlib -T linker.ld -Wl,-Map=out.map

all:main.o stm32_startup.o out.elf
main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@
out.elf: main.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	del *.o, *.elf


CC = arm-none-eabi-gcc
CPU = cortex-m4
CFLAGS = -c -mcpu=$(CPU) -mthumb -std=gnu11 -O0


all:main.o stm32_startup.o
main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

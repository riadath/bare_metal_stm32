CC = arm-none-eabi-gcc
CPU = cortex-m4
CFLAGS = -c -mcpu=$(CPU) -mthumb -std=gnu11 -Wall -O0
LDFLAGS = -nostdlib -T linker.ld -Wl,-Map=target/out.map
OBJECT = object_files
TARGET = target
all:main.o stm32_startup.o gpio.o out.elf
	
	
main.o:main.c
	$(CC) $(CFLAGS) $^ -o $(OBJECT)/$@
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $(OBJECT)/$@
gpio.o:gpio.c
	$(CC) $(CFLAGS) $^ -o $(OBJECT)/$@


out.elf: $(OBJECT)/main.o $(OBJECT)/stm32_startup.o $(OBJECT)/gpio.o
	$(CC) $(LDFLAGS) $^ -o $(TARGET)/$@

clean:
	rm -rf $(OBJECT)/*.o $(TARGET)/*.elf $(TARGET)/*.map


load:
	openocd -f board/st_nucleo_f4.cfg

# automating the build and load process
clean_build: clean all
gdb:
	arm-none-eabi-gdb -x init.gdb

build_load:clean_build gdb
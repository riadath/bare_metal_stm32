target extended-remote localhost:3333
monitor reset init
monitor flash write_image erase out.elf
monitor reset
q
y
SOURCES=main.c ../../firmware/src/dynamixel.c ../../firmware/src/dxl_hal.c ../../firmware/src/adc.c ../../firmware/src/legs.c ../../firmware/src/serial.c ../../firmware/src/zig.c
local:
	gcc -std=gnu99 -Wall -I../include -I../../firmware/include $(SOURCES) -O1 -D F_CPU=16000000UL -lm -o app.exe
clean:
	rm -f *.o *.out *.gch *.a *.hex *.elf *.exe
all:
	rm -f *.o *.out *.gch *.a *.hex *.elf *.exe
	avr-gcc -mmcu=atmega2561 -std=gnu99 -Wall -I../include -I../../firmware/include $(SOURCES) -O1 -D F_CPU=16000000UL -o main.elf
	avr-objcopy -O ihex main.elf main.hex
	avr-size -C --mcu=atmega2561 main.elf
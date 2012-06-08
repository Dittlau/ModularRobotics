SOURCES=main.c ../firmware/src/serial.c ../firmware/src/adc.c ../firmware/src/dynamixel.c ../firmware/src/dxl_hal.c ../firmware/src/init.c

local:
	gcc -std=gnu99 -Wall -I /include -I ../firmware/include $(SOURCES) -lm -o app.exe
clean:
	rm -f *.o *.out *.gch *.a *.hex *.elf *.exe
all:
	avr-gcc -mmcu=atmega2561 -std=gnu99 -Wall -I ../include -I ../firmware/include $(SOURCES) -D F_CPU=16000000 -o main.elf
	avr-objcopy -O ihex main.elf main.hex
	avr-size -C --mcu=atmega2561 main.elf
SOURCES=main.c ../../firmware/src/serial.c ../../firmware/src/adc.c ../../firmware/src/dxl_hal.c ../../firmware/src/dynamixel.c ../../firmware/src/wheel.c
local:
	gcc -std=gnu99 -Wall -I../include -I../../firmware/include $(SOURCES) -lm -o app.exe
clean:
	rm -f *.o *.out *.gch *.a *.hex *.elf *.exe
cross:
	avr-gcc -mmcu=atmega2561 -std=gnu99 -Wall -I../include -I../../firmware/include $(SOURCES) -o main.elf
	avr-objcopy -O ihex main.elf main.hex
	avr-size -C --mcu=atmega2561 main.elf
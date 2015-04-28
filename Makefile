SOURCES=micro.c mr32.c motors.c robot.c sensors.c moviment.c directions.c intersections.c node.c path.c

compile: micro.hex
	

micro.hex: $(SOURCES)
	pcompile $(SOURCES)

upload: micro.hex
	ldpic32 -w micro.hex

clean:
	rm *.o *.hex *.elf *.map
## Makefile

C_FLAGS := -g -Wall
VPATH= ./include ./src ./obj
OBJ:= debug.o

exe:	$(OBJ)
	gcc -o $@ $^

%.o:	%.c
	gcc -c $(C_FLAGS) -I ./include $^

clean:
	rm -rfv exe ./obj/*

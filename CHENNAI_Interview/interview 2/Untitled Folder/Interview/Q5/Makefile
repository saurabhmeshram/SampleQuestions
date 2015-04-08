#makefile for ps command with (-a, -e, T, l) options
VPATH = ./source/
.PHONY : clean move
OBJ = main.o my_ps.o digit.o
CFLAGS = -Wall -c -I ./header/

myps : $(OBJ)
	cc -o $@ $(OBJ)
%.o : %.c 
	cc $(CFLAGS) $^
clean :
	rm myps
move :
	mv *.o ./object/

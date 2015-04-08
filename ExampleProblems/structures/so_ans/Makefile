# Some Variables #
CC := gcc
RM := rm
MV := mv

# Phony Targets #
.PHONY: clean

# Path for Source, Object and Include #
SRC_PATH := ./src/
OBJ_PATH := ./obj/
INCLUDE_PATH := ./include/

# Source and Object File Names #
SRC := $(SRC_PATH)main.c
OBJ := $(SRC:c=o) 		# Substitutes all SRC but with .c as .o (main.c becomes main.o) #

# Executable Name #
TARGET := exe

# Building Binary - use 'make' #
binary: 	$(TARGET) move

$(TARGET):	$(OBJ)
		$(CC) -o $(TARGET) $^

# Building only Object Files - use 'make object_only' #
object_only : 	$(OBJ) move

$(OBJ):		$(SRC)
		$(CC) -c -o $@ $< -I $(INCLUDE_PATH)

# This rule is for moving .o files to ./obj directory (More Organised) #
move:		
		$(MV) $(SRC_PATH)*.o  $(OBJ_PATH)

# For Cleaning - use 'make clean' #
clean:	
	echo "Cleaning Up!"
	$(RM) -rfv $(TARGET) $(OBJ_PATH)*.o $(SRC_PATH)*.o	# Delete .o and executables #

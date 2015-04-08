#Compiling Code

#This is a sample makefile that uses all the advanced features that can be used in a Shell Script	\
Reference : http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

C_FLAGS := -g -Wall		# Compiler Flags
CC := gcc
MOVE :=	mv
RM := rm

.PHONY: $(TARGET)
.PHONY: clean

# Path for .c and .o Files
SRC_PATH := ./src/
OBJ_PATH := ./obj/

# Executable Name
TARGET := exe

# Source and Object File Names
SRC := $(SRC_PATH)debug.c
OBJ := $(SRC:c=o)			# Substitutes all SRC but with .c as .o

# Include Files
INCLUDE := -I ./include

# Make Rules
$(TARGET):	$(OBJ)
		@echo [INFO] Creating Binary Executable $(TARGET)
		@$(CC) -o $(TARGET) $^
		@$(MOVE) $(OBJ) $(OBJ_PATH)

# Below step is optional in case we want to retain the object files
.c.o:
		@echo [CC] $< 
		@$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@


# Clean all the object files and the binary
clean:		
		@echo "[Cleaning]"
		@$(RM) -rfv $(OBJ_PATH)*
		@$(RM) -rfv $(TARGET)


# Some Variables # 
CC = gcc
CFLAGS = -Wall
MV = mv
RM = rm

# Target Name #
EXECUTABLE = netsim

# Variables for Path #
SOURCE_PATH = src/
OBJECT_PATH = obj/
INCLUDE_PATH = include/

# File Names #
SOURCEFILES = $(SOURCE_PATH)1.c
OBJECTFILES = $(SOURCEFILES:.c=.o)

.PHONY: all move clean

all: $(EXECUTABLE) move

$(EXECUTABLE):	$(OBJECTFILES)
		$(CC) -o $@ $<

$(OBJECTFILES):	$(SOURCEFILES)
		$(CC) $(CFLAGS) -c -o $@ -I $(INCLUDE_PATH) $<

move:		
		$(MV) $(OBJECTFILES) $(OBJECT_PATH)

clean:
		$(RM) -rf $(EXECUTABLE) $(OBJECT_PATH)*

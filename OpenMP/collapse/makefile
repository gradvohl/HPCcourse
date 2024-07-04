# Makefile 
#
# Created by Prof. Andre Leon S. Gradvohl, Dr.
# e-mail: gradvohl@ft.unicamp.br
#
# Standard compiler
CC=gcc
#
# Additional keys
# KEYS=-Wall
OPENMPLIB=-fopenmp
#
# Additional libraries 
#LIB=-lm
# 
# Source files
SOURCES=collapse.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

collapse.o: collapse.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

clean:
	rm -f $(OBJECTS) 

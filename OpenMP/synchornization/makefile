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
OPENMPLIB=-fopenmp -lm
#
# Additional libraries 
#LIB=-lm
# 
# Source files
SOURCES=computePi.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

computePi.o: computePi.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

clean:
	rm -f $(OBJECTS) 

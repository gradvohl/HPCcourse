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
SOURCES=basic1.c basic2.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

basic1.o: basic1.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

basic2.o: basic2.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

clean:
	rm -f $(OBJECTS) 

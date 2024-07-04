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
SOURCES=varAtributes.c varAtributes2.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

varAtributes.o: varAtributes.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

varAtributes2.o: varAtributes2.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

clean:
	rm -f $(OBJECTS) 

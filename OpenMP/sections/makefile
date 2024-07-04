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
LIB=-lm
# 
# Source files
SOURCES=master.c  ordered.c  sections.c  single.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

master.o: master.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $(LIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

ordered.o: ordered.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $(LIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

sections.o: sections.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $(LIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

single.o: single.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $(LIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

clean:
	rm -f $(OBJECTS) 

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
SOURCES=initialProblem.c solution1.c  solution2.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

initialProblem.o: initialProblem.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

solution1.o: solution1.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

solution2.o: solution2.c
	@echo "Compiling $< and creating $@"
	$(CC) $(OPENMPLIB) $< -o $(PROGRAMDIR)/$@
	@echo " "

clean:
	rm -f $(OBJECTS) 

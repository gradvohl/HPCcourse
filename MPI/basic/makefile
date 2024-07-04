# Makefile 
#
# Created by Prof. Andre Leon S. Gradvohl, Dr.
# e-mail: gradvohl@ft.unicamp.br
#
# Standard compiler
CC=mpicc
#
# Additional keys
# KEYS=-Wall
#
# Additional libraries 
#LIB=-lm
# 
# Source files
SOURCES=basicMPI.c
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

basicMPI.o: basicMPI.c
	@echo "Compiling $< and creating $@"
	$(CC) $< -o $(PROGRAMDIR)/$@
	@echo "To run this program, use the following command:"
	@echo "mpirun -np <num of processes> -hostfile ../hostfile ./$@"

clean:
	rm -f $(OBJECTS) 

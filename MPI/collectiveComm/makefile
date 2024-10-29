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
SOURCES=gatherExample.c scatterExample.c reduceExample.c 
#
# Object files
OBJECTS=$(SOURCES:.c=.o)
#
# Directory to save the program 
PROGRAMDIR=.
#

all: $(OBJECTS)

gatherExample.o: gatherExample.c
	@echo "Compiling $< and creating $@"
	$(CC) $< -o $(PROGRAMDIR)/$@
	@echo "To run this program, use the following command:"
	@echo "mpirun -np <num of processes> -hostfile ../hostfile ./$@"
	@echo " "

scatterExample.o: scatterExample.c
	@echo "Compiling $< and creating $@"
	$(CC) $< -o $(PROGRAMDIR)/$@
	@echo "To run this program, use the following command:"
	@echo "mpirun -np <num of processes> -hostfile ../hostfile ./$@"
	@echo " "

reduceExample.o: reduceExample.c
	@echo "Compiling $< and creating $@"
	$(CC) $< -o $(PROGRAMDIR)/$@
	@echo "To run this program, use the following command:"
	@echo "mpirun -np <num of processes> -hostfile ../hostfile ./$@"
	@echo " "

clean:
	rm -f $(OBJECTS) 

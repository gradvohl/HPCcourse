/**
 * Example to illustrate non-blocking routines
 * Adapted from https://computing.llnl.gov/tutorials/mpi
 */
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int numtasks, rank, next, prev, buf[2], tag1=1, tag2=2;
  MPI_Request reqs[4]; // Array to handle non-blocking calls
  MPI_Status stats[4]; // Array to handle Waitall function

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  srand(time(NULL)); 
   
  // Determines the left and right neighbors
  prev = rank-1;
  next = rank+1;
  if (rank == 0)
    prev = numtasks - 1;

  if (rank == (numtasks - 1))  
    next = 0;

  buf[0] = buf[1] = rank;

  // Receives and sends non-blocking messages to the neighbors.
  MPI_Irecv(&buf[0], 1, MPI_INT, prev, tag1, MPI_COMM_WORLD, &reqs[0]);
  MPI_Irecv(&buf[1], 1, MPI_INT, next, tag2, MPI_COMM_WORLD, &reqs[1]);

  MPI_Isend(&rank, 1, MPI_INT, prev, tag2, MPI_COMM_WORLD, &reqs[2]);
  MPI_Isend(&rank, 1, MPI_INT, next, tag1, MPI_COMM_WORLD, &reqs[3]);
  
  // Executes some job while the messages don't arrive 
  sleep(rand()%3);

  // Waits until the non-blocking operations finish 
  MPI_Waitall(4, reqs, stats);
  
  printf("I am the process: %d. From left, I receive %d. From right, I receive %d.\n",
	  rank, buf[0], buf[1]);

  MPI_Finalize();
  return 0;
}

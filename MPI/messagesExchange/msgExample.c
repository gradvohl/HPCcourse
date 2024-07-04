/**
 * MPI Program to exemplify messages exchange 
 * between MPI processes.
 */  
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Function to invert the values in an array.
 * @param originalArray Array with original data.
 * @param size Array size.
 * @return Inverted array.
 */ 
int *invert(int *originalArray, unsigned int size)
{
  int *invertedArray = NULL;
  register int i=0, j=size-1;

  if (size == 0) 
    return NULL;
 
  invertedArray = (int *) malloc(sizeof(int) * size);

  if (invertedArray == NULL)
  {
    perror("Problems in array allocation.");
    exit(EXIT_FAILURE);
  }

  for (i=0; i<size; i++, j--)
    invertedArray[i] = originalArray[j];

  return invertedArray;
}

/**
 * Function to print the values from an array. 
 * @param array Array with the data.
 * @param size Array size.
 */  
void print(int *array, unsigned int size)
{
  register int i;

  if (size<1)
    return;
  else if (size == 1)
  {
    printf("{ %d }\n", array[0]);
    return;
  }
  else if (size == 2)
  {
    printf("{ %d, %d }\n", array[0], array[1]);
    return;
  }

  printf("{ %d", array[0]);

  for (i=1; i<size-1; i++)
     printf(", %d", array[i]);

  printf(", %d }\n", array[i]);

  return;
}

int main (int argc, char *argv[])
{
 int quantProcs, rank, destiny, source, rc, quantidade, tag=1;

 int masterArray[] = {0, 1, 2, 3, 4}; 
 unsigned int size = 5;
 int *workerArray;
 int *invertedArray;

 MPI_Status Stat;

 // Initializes the MPI
 MPI_Init(&argc,&argv);

 // Get the number of processes
 MPI_Comm_size(MPI_COMM_WORLD, &quantProcs);

 // Get the rank (process id)
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
 // If I'm the master  
 if (rank == 0)
 {
   destiny = 1;
   source = 1;

   // Send the array to the worker
   rc = MPI_Send(masterArray, size, MPI_INT, destiny, tag, MPI_COMM_WORLD);

   // Alocates memory to receive data
   if ((workerArray=(int *) malloc(sizeof(int) * size)) == NULL)
   {
     perror("Problems in workerArray allocation in master");
     exit(EXIT_FAILURE);
   }

   // Wait to receive the array from the worker
   rc = MPI_Recv(workerArray, size, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);

   printf("Print the inverted array: ");
   print(workerArray, size);
   free(workerArray);
 }
 // If I'm the worker 
 else if (rank == 1) 
 {
   destiny = 0;
   source = 0;
  
   // Alocates memory to receive data 
   if ((workerArray= (int *) malloc(sizeof(int) * size)) == NULL)
   {
     perror("Problems in workerArray allocation in worker");
     exit(EXIT_FAILURE);
   } 

   // Wait to receive data from master
   rc = MPI_Recv(workerArray, size, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);

   // Inverts the array
   invertedArray = invert(workerArray, size);
  
   // Sends the inverted array back to master
   rc = MPI_Send(invertedArray, size, MPI_INT, destiny, tag, MPI_COMM_WORLD);

   // Free allocated memory
   free(workerArray);
   free(invertedArray);
 }

 // Finalizes the  MPI
 MPI_Finalize();
 return 0;
}

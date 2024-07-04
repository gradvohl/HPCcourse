#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]) 
{
 int  numtasks, rank, len, rc; 
 char hostname[MPI_MAX_PROCESSOR_NAME];

 // Initializes MPI  
 MPI_Init(&argc,&argv);

 // Get the number of tasks
 MPI_Comm_size(MPI_COMM_WORLD,&numtasks);

 // Get my rank (process id in MPI ring)
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);

 // Get the name of processor (machine name where the process will run)
 MPI_Get_processor_name(hostname, &len);
 printf ("Numbe of tasks = %d My rank= %d Running in %s\n", numtasks, rank, hostname);

 // Finalizes MPI  
 MPI_Finalize();
}

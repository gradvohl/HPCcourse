/**
 * Example to illustrate the gather operation.
 * Adapted from https://rookiehpc.org/mpi/docs/mpi_gather/index.html
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define SIZE 4

int main(int argc, char* argv[])
{
    int rank, size;
    int myValue;
    int buffer[4];

    MPI_Init(&argc, &argv);

    /* Get number of processes and check that 4 processes are used */
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Get my rank */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size != SIZE)
    {
       if (rank == 0)
       {
        fprintf(stderr,"You must specify 4 process in mpirun.\n");
        fprintf(stderr,"Use the following command:\n\t");
        fprintf(stderr,"mpirun -np 4 -hostfile ../hostfile %s\n", argv[0]);
       }

        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    /* Define my own value equals rank * 100; */
    myValue = rank * 100;

    printf("Process %d, my value = %d.\n", rank, myValue);

    if (rank == 0) /*If I am the master process */
    {
        MPI_Gather(&myValue, 1, MPI_INT, buffer, 1, MPI_INT, 0 /*master rank*/, MPI_COMM_WORLD);
        printf("Values collected on master process : %d, %d, %d, %d.\n", 
			buffer[0], buffer[1], buffer[2], buffer[3]);
    }
    else /* If I am a worker process */
    {
	/* Notice that the 4th parameter is NULL. 
	 * We, the workers, don't need a buffer to handle the values.
	 */
        MPI_Gather(&myValue, 1, MPI_INT, NULL, 0, MPI_INT, 0 /*master rank*/, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}


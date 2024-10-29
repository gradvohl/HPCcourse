/**
 * Example to illustrate the reduce operation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define SIZE 4

int main(int argc, char* argv[])
{
    int size, rank;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    int localsum[4] = {0, 0, 0, 0};
    int globalsum[4] = {0, 0, 0, 0};

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

    /**
     * Processors with odd ranks will accumulate 5 in the local sum.
     * Processors with even ranks will accumulate 10 in the local sum.
     */
    if(rank % 2 == 1)
    {
        localsum[0] += 5;
	localsum[2] += 5;
    }
    else if( rank > 0 && (rank % 2 == 0))
    {
        localsum[1] += 10;
	localsum[3] += 10;
    }

    /* Show the data in different processes */
    printf("Rank: %d <%d, %d, %d, %d>\n", 
	    rank, localsum[0], localsum[1], localsum[2], localsum[3]);

    /* MPI Reduce operation */
    MPI_Reduce(localsum,globalsum,4,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

    /* Only master process will show the global sum */
    if(rank==0)
    {
        printf("globalsum[0] = %d \n",globalsum[0]);
        printf("globalsum[1] = %d \n",globalsum[1]);
	printf("globalsum[2] = %d \n",globalsum[2]);
        printf("globalsum[3] = %d \n",globalsum[3]);
    }

    MPI_Finalize();

    return (EXIT_SUCCESS);
}

#include <omp.h>
#include <stdio.h>
#include <math.h>
#define NUMTHREADS 4

int main( ) 
{
  int i=0;
  int id;
  omp_set_dynamic(0);
  omp_set_num_threads(NUMTHREADS);

  #pragma omp parallel private(id)
  {
    id = omp_get_thread_num();	  
    printf("Executing commands threadId: %d\n", id);
   
    if (id == 0) //Overload main thread
      for (i=0; i<100000; i++)
	      sqrt(i);
    
    #pragma omp single
    {
        printf("Only threadId: %d executes this line\n", omp_get_thread_num());
    }
  }
  return 0;
}

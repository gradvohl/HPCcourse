#include <omp.h>
#include <stdio.h>
#include <math.h>
#define NUMTHREADS 4

int main( ) 
{
  int i=0;
  int a=0;
  int id;
  omp_set_dynamic(0);
  omp_set_num_threads(NUMTHREADS);

  #pragma omp parallel private(id) shared(a)
  {
    id = omp_get_thread_num();	  
    printf("Executing commands threadId: %d\n", id);
   
    if (id == 0) //Overload main thread
      for (i=0; i<100000; i++)
	      sqrt(i);
    
    #pragma ordered
    {
        printf("threadId: %d executes this line. a = %d\n", id, a++);
    }
  }
  return 0;
}

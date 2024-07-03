#include <omp.h>
#include <stdio.h>
#define NUMTHREADS 4

int main( ) 
{
  int i=0;
  omp_set_dynamic(0);
  omp_set_num_threads(NUMTHREADS);

  #pragma omp parallel sections 
  {
    #pragma omp section
    {
        printf("Section A: threadId: %d\n", omp_get_thread_num());
    }
    
    #pragma omp section
    {
        printf("Section B: threadId: %d\n", omp_get_thread_num());
    }
  }
  return 0;
}

#include <stdio.h>
#include <omp.h>
int main () 
{
  int i=0, tmp=0, threadId=0;
  int firstTime = 1;

  #pragma omp parallel num_threads (4) firstprivate(tmp, firstTime, threadId) 
  {
    threadId = omp_get_thread_num();
    printf("Thread %d. Initial value for i: %d\n", threadId, i);

    #pragma omp for
    for (i=0; i<1000; i++)
    {
      if (firstTime)
      {
        printf("Thread %d, initial value: %d\n", threadId, i);
	firstTime=0;
      }	      
      tmp++;
    }

    printf("Thread %d, tmp:%d\n", omp_get_thread_num (), tmp);
  }

  printf("Final value of tmp: %d\n", tmp);

  return 0;
}

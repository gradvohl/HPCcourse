#include <stdio.h>
#include <omp.h>

int main(void)
{
 int i=0, j=0;

 omp_set_num_threads(4);

 #pragma omp parallel
 {
   #pragma omp for lastprivate(i,j)
   for (i=0; i < 1000; i++)
	   j++;
   printf("Thread id (%d): i: %d j:%d\n", omp_get_thread_num(), i, j);
 }

 printf("Final value for i: %d j: %d\n", i, j);
 return 0;
}

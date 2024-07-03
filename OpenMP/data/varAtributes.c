#include <stdio.h>
#include <omp.h>

int main(void)
{
 int i=0, j=0;

 omp_set_num_threads(4);

 #pragma omp parallel shared(i) firstprivate(j)
 {
   i+=2; j+=2;
   printf("Thread id (%d): i: %d, j:%d\n", omp_get_thread_num(), i, j);
 }

 printf("Values after parallel region: i: %d j: %d\n", i, j);

 return 0;
}

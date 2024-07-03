#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 10000
#define NTHREADS 4

int main()
{
  register int i;
  int *partialSum;
  int sum=0, thrdId;
  double ave=0;

  if ((partialSum= (int *) calloc(NTHREADS, sizeof(int))) == NULL)
  {
    perror("Problems allocation partialSum array\n");
    exit(EXIT_FAILURE);
  }

  #pragma omp parallel for num_threads(NTHREADS)
  for (i=0; i<SIZE; i++)
  {
    thrdId = omp_get_thread_num();
    partialSum[thrdId] = partialSum[thrdId] + i;
  }

  for (i=0; i<NTHREADS; i++)
    sum = sum + partialSum[i];

  ave = ((double) sum)/SIZE;
  printf("Average: %f\n", ave);

  return 0;
}

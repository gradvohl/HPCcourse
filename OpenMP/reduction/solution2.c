#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 10000
#define NTHREADS 4

int main()
{
  register int i;
  int sum=0, thrdId;
  double ave=0;

  #pragma omp parallel for num_threads(NTHREADS) reduction (+:sum)
  for (i=0; i<SIZE; i++)
    sum = sum + i;

  ave = ((double) sum)/SIZE;
  printf("Average: %f\n", ave);

  return 0;
}

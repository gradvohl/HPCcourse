#include <stdio.h>
#define SIZE 10000

int main()
{
  register int i;
  int sum=0;
  double ave=0;
  
  for (i=0; i<SIZE; i++)
  {
    sum = sum + i;
  }

  ave = ((double) sum)/SIZE;
  printf("Average: %f\n", ave);

  return 0;
}

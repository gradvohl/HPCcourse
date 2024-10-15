/**
 * Calculate pi using OpenMP.
 */ 
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <stdlib.h>
#include <sys/time.h>

double f(double a)
{
   return( 2.0 / sqrt(1 - a*a) );
}

int main(int argc, char *argv[])
{
   int    N;    // accuracy of the approximation 
   double sum;  
   double step, x;
   double mypi;
   int i;

   if ( argc != 2 )
   {
      printf("Usage:\n\t %s Num_Intervals\n", argv[0]);
      exit(1);
   }

   N = atoi(argv[1]);
   step = 1.0/(double) N;

   sum = 0.0;

   #pragma omp parallel private (mypi, x) shared(sum)
   {
     mypi = 0.0;

     #pragma omp for 
     for (i = 0; i < N; i++)	// Parallel Loop
     {
        x = step*(i + 0.5);
        mypi = mypi +  step*f(x);
     }

     #pragma omp critical
     {
      sum = sum + mypi;
     }
   }

  printf("Computed Pi = %lf\n", sum);
  return 0;
}



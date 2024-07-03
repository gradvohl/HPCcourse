#include <stdio.h>
int main()
{
   int j, k, jlast, klast;
   #pragma omp parallel for collapse(2) lastprivate(jlast, klast)
   for (k=1; k<=20; k++)
     for (j=1; j<=30; j++)
     {
       jlast=j;
       klast=k;
     }

   printf("%d %d\n", klast, jlast);
   return 0;
}

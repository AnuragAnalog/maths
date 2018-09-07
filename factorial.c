#include <stdio.h>
#include <stdlib.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   int                n;
   long double        fac, i;

   printf("Enter a value for N: ");
   scanf("%d", &n);

   if (n < 0)
   {
      printf("Enter a valid input for n\n");
      exit(0);
   }
   else if (n == 0)
   {
      printf("The value of factorial is 1\n");
      exit(0);
   }
   else if ((n == 2) || (n == 1))
   {
      printf("The value of factorial is %d\n", n*1);
      exit(0);
   }

   fac = 1;
   for (i=1; i<n; i++)
   {
      fac = fac * (i+1);
   }

   printf("%d! is %.1Lf", n,fac);
   printf("\n");
   exit(0);
}

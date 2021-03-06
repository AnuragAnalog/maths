#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
float factorial(int n);
double combi(int n, int k);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int         n, k;
   double      comb;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <value of n> <value of k>.\n", argv[0]);
      exit(1);
   }

   n = atoi(argv[1]);
   k = atoi(argv[2]);

   comb = combi(n, k);
   printf("%dC%d is %.1f.\n", n, k, comb);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
float factorial(int n)
{
   double        fac, i;

   if (n == 0)
   {
      return 1;
   }
   else if ((n == 2) || (n == 1))
   {
      return (n*1);
   }

   fac = 1;
   for (i=1; i<n; i++)
   {
      fac = fac * (i+1);
   }

   return fac;
}

double combi(int n, int k)
{
   double        val;

   if (k < 0 || n < 0)
   {
      printf("The values of k and n should be +ve.\n");
      exit(1);
   }
   else if (k > n)
   {
      printf("The no. of permutations are ZERO.\n");
      exit(0);
   }
   else if (k == n)
   {
      return 1;
   }

   val = factorial(n)/(factorial(n-k)*factorial(k));
   return val;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        100
#define POW        2

/********* FUNCTION DECLARATION *********/
void lab(int num, int factor[]);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        num;
   int        factor[MAX];

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <lab number>.\n", argv[0]);
      exit(1);
   }

   num = atoi(argv[1]);

   if (num <= 0)
   {
      fprintf(stderr, "Enter only +ve numbers.\n");
      exit(2);
   }

   lab(num, factor);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void lab(int num, int factor[])
{
   int        i = 1, j = 0;

   while (i != num+1)
   {
      if (num % i == 0)
      {
         factor[j] = i;
         j++;
      }
      i++;
   }

   for (i = 1; i < j; i++)
   {
      if (num % (int)powf(factor[i], POW) == 0)
      {
         printf("%d is a lab number.\n", num);
         return ;
      }
   }
   printf("%d is not a lab number.\n", num);

   return ;
}

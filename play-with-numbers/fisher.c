#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        100
#define POW        3

/********* FUNCTION DECLARATION *********/
void fisher(int num, int factor[]);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        num;
   int        factor[MAX];

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <fisher number>.\n", argv[0]);
      exit(1);
   }

   num = atoi(argv[1]);

   if (num < 0)
   {
      fprintf(stderr, "Enter only +ve numbers.\n");
      exit(2);
   }

   fisher(num, factor);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void fisher(int num, int factor[])
{
   int        i = 1, j = 0;
   int        pi = 1;

   while (i != num+1)
   {
      if (num % i == 0)
      {
         factor[j] = i;
         j++;
      }
      i++;
   }

   for (i = 0; i < j; i++)
   {
      pi = pi * factor[i];
   }

   if (powf(num, POW) == pi)
   {
      printf("%d is a fisher number.\n", num);
   }
   else
   {
      printf("%d is not a fisher number.\n", num);
   }

   return ;
}

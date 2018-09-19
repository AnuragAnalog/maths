#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        11

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        num, div_num, revnum[MAX];
   int        N = 0, i;

   printf("Enter the number to be reversed: ");
   scanf("%d", &num);

   if (num < 0)
   {
      printf("Enter a +ve number or number less than %d\n", MAXINT);
      exit(1);
   }

   div_num = num;

   while (div_num != 0)
   {
      div_num = div_num / 10;
      N = N + 1;
   }

   printf("The reverse of the number entered is \n");
   for (i = 0; i < N; i++)
   {
      revnum[i] = num % 10;
      num = num / 10;
      printf("%d", revnum[i]);
   }
   printf("\n");

   exit(0);
}

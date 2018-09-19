#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        10

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        i = 0, j, num, sq_num, rem, sq_rem;
   int        num1[MAX], num2[MAX];

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <number>\n", argv[0]);
      exit(1);
   }

   num = atoi(argv[1]);

   if (num < 0)
   {
      printf("Enter a +ve number.\n");
      exit(2);
   }
   else if (num == 0)
   {
      printf("It's a Automorphic number.\n");
      exit(0);
   }

   sq_num = num * num;

   while (num != 0)
   {
      rem = num % 10;
      num = num / 10;
      num1[i] = rem;

      sq_rem = sq_num % 10;
      sq_num = sq_num / 10;
      num2[i] = sq_rem;

      i++;
   }

   for (j = 0; j < i; j++)
   {
      if (num1[j] != num2[j])
      {
         printf("It's not an automorphic number.\n");
         exit(0);
      }
   }

   printf("It's an automorphic number.\n");
   exit(0);
}

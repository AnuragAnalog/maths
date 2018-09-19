#include <stdio.h>
#include <stdlib.h>

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        num, sq_num, sum = 0, rem;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <number>.\n", argv[0]);
      exit(1);
   }

   num = atoi(argv[1]);

   if ((num == 1) || (num == 0))
   {
      printf("%d is a Neon number.\n", num);
      exit(0);
   }

   sq_num = num * num;

   while (sq_num != 0)
   {
      rem = sq_num % 10;
      sq_num = sq_num / 10;
      sum = sum + rem;
   }

   if (num == sum)
   {
      printf("%d is a neon number.\n", num);
   }
   else
   {
      printf("%d is not a neon number.\n", num);
   }

   exit(0);
}

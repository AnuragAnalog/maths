#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        num, reminder, sum = 0;

   printf("Enter the number: ");
   scanf("%d", &num);

   if (num < 0)
   {
      printf("Enter only positive integer or number less than %d\n", MAXINT);
      exit(1);
   }
   else if (num == 0)
   {
      printf("The sum digits is 0\n");
      exit(1);
   }

   while (num <= 0 || num >= 9)
   {
      sum = 0;
      while (num != 0)
      {
         reminder = num % 10;
         num = num / 10;
         sum = sum + reminder;
      }
      num = sum;
   }

   printf("The sum of digits of number is %d\n", sum);
   exit(0);
}

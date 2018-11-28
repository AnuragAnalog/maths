#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   float        base, index, base1, i;
   
   printf("Enter the value of base: ");
   scanf("%f", &base);

   printf("Enter the value of index: ");
   scanf("%f", &index);

   if (base == 0 && index == 0)
   {
      printf("Zero to the power of zero is undefined\n");
      exit(1);
   }
   else if (base == 0 && index < 0)
   {
      printf("Zero raising to negative power is not possible\n");
      exit(1);
   }

   base1 = base;

   if (index == 0)
   {
      printf("%.1f raised to the power of %.1f is 1\n", base, index);
      exit(0);
   }
   else if (index < 0)
   {
      index = (-1) * index;

      for (i = 0; i <= index; i++)
      {
         base = base / base1;
      }
      printf("%.1f raised to the power of %.1f is %.4f\n", base1, -index, base);
      return 0;
   }

   for (i = 1; i < index; i++)
   {
      base = base * base1;
   }

   printf("%.1f raised to the power of %.1f is %.1f\n", base1, index, base);
   exit(0);
}

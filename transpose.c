#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        10

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i, j, k, l;
   int        matrix[MAX][MAX], matrixt[MAX][MAX];

   printf("Enter the number of rows and columns in first matrix\n");
   scanf("%d %d", &k, &l);

   if (k <= 0 || l <= 0)
   {
      printf("Enter a +ve value or value less than %d for rows and columns\n", MAXINT);
      exit(1);
   }
   else if (k > 10 || l > 10)
   {
      printf("Enter a value which is less than %d for rows and columns\n", MAX);
      exit(2);
   }

   printf("Enter the elements of matrix in row-wise order.\n");
   for (i = 0; i < k; i++)
   {
      for (j = 0; j < l; j++)
      {
         scanf("%d", &matrix[i][j]);
      }
   }

   printf("The transposed matrix:- \n");
   // transposing of matrix
   for (i = 0; i < l; i++)
   {
      for (j = 0; j < k; j++)
      {
         matrixt[i][j] = matrix[j][i];
         printf("  %d  ", matrixt[i][j]);
      }
      printf("\n");
   }

   exit(0);
}

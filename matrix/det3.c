#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        5
#define   MAXM       3

/********* MAIN STRATS HERE *********/
int main(void)
{
   int        i, j, k = 2, l = 0, ele1 = 1, ele2 = 1, det, ele11 = 0, ele22 = 0;
   int        matrix[MAX][MAX];

   printf("Enter the elements of matrix A(3by3) in row-wise order.\n");
   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < MAXM; j++)
      {
         scanf("%d", &matrix[i][j]);
      }
   }

   for (i = 0; i < MAXM; i++)
   {
      for (j = 3; j < MAX; j++)
      {
         matrix[i][j] = matrix[i][j-3];
      }
   }

   j = 0;
   while (l < 3)
   {
      for (i = 0; i < MAXM; i++)
      {
         ele1 *= (matrix[i][j+i]);
         ele2 *= (matrix[i][k-i]);
      }

      ele11 += ele1;
      ele22 += ele2;

      j = j + 1, k = k + 1, l = l + 1;
      ele1 = 1, ele2 = 1;
   }

   det = ele11 - ele22;
   printf("|A| = %d\n", det);

   exit(0);
}

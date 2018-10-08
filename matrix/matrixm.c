#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* DEFINED CONSTANTS *********/
#define   MAX       10

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i, j, k, l, m, n, q, ele;
   int        matrix1[MAX][MAX], matrix2[MAX][MAX], matrix3[MAX][MAX];

   printf("Enter the number of rows and columns in first matrix\n");
   scanf("%d %d", &k, &l);

   if (k < 0 || l < 0)
   {
      printf("Enter a +ve value or value less than %d for rows and columns\n", MAXINT);
      exit(1);
   }

   printf("Enter the elements of first matrix\n");
   for (i = 0; i < k; i++)
   {
      for (j = 0; j < l; j++)
      {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("Enter the number of rows and columns in the second matrix\n");
   scanf("%d %d", &m, &n);

   if (m < 0 || n < 0)
   {
      printf("Enter a +ve value or value less than %d for rows and columns\n", MAXINT);
      exit(1);
   }

   if (m != l)
   {
      printf("!!! Matrix multiplication is not possible !!!\n");
      printf("Multiplication of matricies is possible only if number of ");
      printf("columns of first matrix is equal to number of rows of second ");
      printf("matrix\n");
      exit(2);
   }

   printf("Enter the elements of second matrix \n");
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &matrix2[i][j]);
      }
   }

   // Initialization of matrix3
   for (i = 0; i < k; i++)
   {
      for (j = 0; j < n; j++)
      {
         matrix3[i][j] = 0;
      }
   }

   printf("The Resultant matrix is: \n");
   for (i = 0; i < k; i++)
   {
      for (j = 0; j < n; j++)
      {
         for (q = 0; q < m; q++)
         {
            ele = matrix1[i][q] * matrix2[q][j];
            matrix3[i][j] += ele;
         }
         printf("%d\t", matrix3[i][j]);
      }
      printf("\n");
   }
   exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15

/********* FUNCTION DECLARATION *********/
void diadomatrix(float matrix[MAX][MAX], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i, j, n;
   float      matrix[MAX][MAX];

   printf("Enter order of the matrix:- ");
   scanf("%d", &n);

   printf("Enter the elements of the matrix in row-wise order:- \n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%f", &matrix[i][j]);
      }
   }

   diadomatrix(matrix, n);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void diadomatrix(float matrix[MAX][MAX], int n)
{
   int        i, j, dd = 0, dd1 = 0;
   float      val = 0;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (i == j)
         {
            continue;
         }

         val += fabsf(matrix[i][j]);
      }
      if (fabsf(matrix[i][i]) > val)
      {
         dd = dd + 1;
         dd1 = dd1 + 1;
      }
      else if (fabs(matrix[i][i]) == val)
      {
         dd1 = dd1 + 1;
      }
      val = 0;
   }

   if (dd == n)
   {
      printf("The given matrix is strictly diagonally dominant matrix.\n");
      return ;
   }
   else if (dd1 == n)
   {
      printf("The given matrix is diagonally dominant matrix.\n");
   }
   printf("The given matrix is not diagonally dominant.\n");

   return ;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        5
#define   MAXM       3
#define   MAXC       1

/********* FUNCTION DECLARATION *********/
float det3(float matrix[MAX][MAX]);
float shft_mat(float coeff_mat[MAX][MAX], float const_mat[MAXM][MAXC], int ind);
int Error(char *message);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int          i, j, k = 0;
   float        coeff_mat[MAX][MAX], const_mat[MAXM][MAXC];
   float        det, del[MAXM];

   printf("Enter the elements of Co-efficient matrix in row-wise order.\n");
   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < MAXM; j++)
      {
         scanf("%f", &coeff_mat[i][j]);
      }
   }

   printf("Enter the elements of Constant matrix in row-wise order.\n");
   for (i = 0; i < MAXM; i++)
   {
      scanf("%f", &const_mat[i][MAXC]);
   }

   det = det3(coeff_mat);

   if (det == 0)
   {
      Error("The given set of equations have infinitely many solutions.");
   }

   printf("x       y       z\n");
   while (k < MAXM)
   {
      del[k] = shft_mat(coeff_mat, const_mat, k);
      printf("%f ", del[k]/det);
      k++;
   }
   printf("\n");

   exit(0);
}

/********* FUNCTION DEFINITION *********/
float det3(float matrix[MAX][MAX])
{
   int        i, j, k = 2, l = 0;
   float      ele1 = 1, ele2 = 1, det, ele11 = 0, ele22 = 0;

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

   return det;
}

float shft_mat(float coeff_mat[MAX][MAX], float const_mat[MAXM][MAXC], int ind)
{
   int          i, j;
   float        det;
   float        temp_mat[MAX][MAX];

   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < MAXM; j++)
      {
         temp_mat[i][j] = coeff_mat[i][j];
      }
   }

   for (i = 0; i < MAXM; i++)
   {
      temp_mat[i][ind] = const_mat[i][MAXC];
   }

   det = det3(temp_mat);

   return det;
}

int Error(char *message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}

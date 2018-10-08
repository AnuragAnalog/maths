#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX9       9
#define   MAX        5
#define   MAXM       3

/********* FUNCTION DECLARATION *********/
float det3(float matrix[MAX][MAX]);
void inverse(float matrix[MAXM][MAX], float det, float inv[MAXM][MAXM]);
void matrixm(float matrix[MAXM][MAXM], float const_mat[MAXM]);
int pow1(int ind);
int Error(char *message);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int          i, j;
   float        coeff_mat[MAX][MAX], const_mat[MAXM], inv[MAXM][MAXM];
   float        det;

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
      scanf("%f", &const_mat[i]);
   }

   det = det3(coeff_mat);

   if (det == 0)
   {
      Error("Singular matrix doesn't have an inverse.");
   }

   inverse(coeff_mat, det, inv);
   matrixm(inv, const_mat);

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

void inverse(float matrix[MAXM][MAX], float det, float inv[MAXM][MAXM])
{
   int        i, j, k = 0, m = 0, n = 0, l = 0;
   float      temp[MAXM+1], cofactor[MAXM][MAXM];

   while (k < MAX9)
   {
      for (i = 0; i < MAXM; i++)
      {
         for (j = 0; j < MAXM; j++)
         {
            if (i == m || j == n)
            {
               continue;
            }
            else
            {
               temp[l] = matrix[i][j];
               l++;
            }
         }
      }

      cofactor[m][n] = (pow1(m+n) * (temp[0]*temp[3] - temp[1]*temp[2]))/det;

      if (n == 2)
      {
         m++;
         n = 0;
      }
      else if (n != 2)
      {
         n++;
      }
      l = 0, k++;
   }

   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < MAXM; j++)
      {
         inv[i][j] = cofactor[j][i];
      }
   }

   return ;
}

void matrixm(float matrix[MAXM][MAXM], float const_mat[MAXM])
{
   int        i, j, q;
   float      ele;
   float      val = 0;

   printf("The solutions for the equations are:- \n");
   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < 1; j++)
      {
         for (q = 0; q < MAXM; q++)
         {
            ele = matrix[i][q] * const_mat[q];
            val += ele;
         }
         printf("%f ", val);
         val = 0;
      }
   }
   printf("\n");

   return ;
}

int pow1(int ind)
{
   int        i = 1, i1 = -1;  //Declaration of variables in int

   if (ind%2 == 0)
   {
      return i;  //returning 1
   }
   else
   {
      return i1;  //returning -1
   }
}

int Error(char *message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}

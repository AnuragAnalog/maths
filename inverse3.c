#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        5
#define   MAXM       3
#define   MAX9       9

/********* FUNCTION DECLARATION *********/
float det3(float matrix[MAXM][MAX]);
void inverse(float matrix[MAXM][MAX], float det);
int pow1(int ind);
int Error(char *message);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int          i, j;
   float        matrix[MAXM][MAX];
   float        det;

   printf("Enter the elements of Co-efficient matrix in row-wise order.\n");
   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < MAXM; j++)
      {
         scanf("%f", &matrix[i][j]);
      }
   }

   det = det3(matrix);
   if (det == 0)
   {
      Error("Inverse doesn't exist for a singular matrix.");
   }

   inverse(matrix, det);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
float det3(float matrix[MAXM][MAX])
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

void inverse(float matrix[MAXM][MAX], float det)
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

   printf("\nInverse of the given matrix:- \n");
   for (i = 0; i < MAXM; i++)
   {
      for (j = 0; j < MAXM; j++)
      {
         printf("%f  ", cofactor[j][i]);
      }
      printf("\n");
   }

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


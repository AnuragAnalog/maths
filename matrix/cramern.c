#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        15

/********* FUNCTION DECLARATION *********/
float shft_mat(float co[MAX][MAX], float con[MAX], int ind, int n);
float detn(float co[MAX][MAX], int n);
int Error(char *message);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int          i, j, k = 0, n;
   float        co[MAX][MAX], con[MAX];
   float        det, del[MAX];

   printf("Enter order of the matrix:- ");
   scanf("%d", &n);

   printf("Enter the elements of Co-efficient matrix in row-wise order.\n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%f", &co[i][j]);
      }
   }

   printf("Enter the elements of Constant matrix in row-wise order.\n");
   for (i = 0; i < n; i++)
   {
      scanf("%f", &con[i]);
   }

   while (k < n)
   {
      del[k] = shft_mat(co, con, k, n);
      k++;
   }
   det = detn(co, n);

   if (det == 0)
   {
      Error("The given set of equations have infinitely many solutions or no solutions.");
   }

   k = 0;
   while (k < n)
   {
      printf("Value of x%d is %f\n", k+1, del[k]/det);
      k++;
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
float detn(float co[MAX][MAX], int n)
{
   int        i, j, k = 0;  //Declaration of variables in int
   float      val, det = 1; //Declaation of variables in float

   while (k < n)
   {
      for (i = 0; i < n; i++)
      {
         if (k >= i)
         {
            continue;
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]);
         }
      }
      k++;
   }

   for (i = 0; i < n; i++)
   {
      det = det * co[i][i];
   }

   return det;
}

float shft_mat(float co[MAX][MAX], float con[MAX], int ind, int n)
{
   int          i, j;
   float        det;
   float        temp_mat[MAX][MAX];

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         temp_mat[i][j] = co[i][j];
      }
   }

   for (i = 0; i < n; i++)
   {
      temp_mat[i][ind] = con[i];
   }

   det = detn(temp_mat, n);

   return det;
}

int Error(char *message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void detn(float co[MAX][MAX], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j, n;  //Declaration of variables in int
   float       co[MAX][MAX]; //Declaration of arrays in float

   // Input Section
   printf("Enter the order of matrix:- ");
   scanf("%d", &n);

   printf("Enter the elements of the matrix in row-wise order:\n");
   while (i < n)  //Check condition
   {
      for (j = 0; j < n; j++)
      {
         scanf("%f", &co[i][j]);
      }
      i++;  // Incrementing i
   }

   detn(co, n);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void detn(float co[MAX][MAX], int n)
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
   printf("The determinant of the given matrix is %f.\n", det);

   return ;
}

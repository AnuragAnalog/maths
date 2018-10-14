#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        15

/********* FUNCTION DECLARATION *********/
float detn(float co[MAX][MAX], int n);
void gaussjori(float co[][MAX], int n, float in[][MAX]);
void matrixm(float co[][MAX], float con[], int n);
int Error(char *message);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int          i, j, n;
   float        det;
   float        co[MAX][MAX], con[MAX], inv[MAX][MAX];

   printf("Enter the order of the matrix: ");
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

   gaussjori(co, n, inv);
   det = detn(co, n);

   if (det == 0)
   {
      Error("Singular matrix doesn't have an inverse.");
   }

   matrixm(inv, con, n);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void gaussjori(float co[][MAX], int n, float inv[][MAX])
{
   int        i, j, k = 0;
   float      val;
   float      ai[MAX][MAX];

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         ai[i][j] = 0;
         if (i == j)
         {
            ai[i][j] = 1;
         }
      }
   }

   while (k < n)
   {
      for (i = 0; i < n; i++)
      {
         if (i == k)
         {
            continue;
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]);
            ai[i][j] = (ai[i][j]-val*ai[k][j]);
         }
      }
      k++;
   }

   for (i = 0; i < n; i++)
   {
      if (co[i][i] == 0)
      {
         printf("The given system of equations have no ");
         printf("or infinitely many solutions.\n");
         exit(1);
      }
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         inv[i][j] = (ai[i][j]/co[i][i]);
      }
   }
   return ;
}

void matrixm(float co[][MAX], float con[], int n)
{
   int        i, j, q;
   float      ele;
   float      val = 0;

   printf("The solutions for the equations are:- \n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < 1; j++)
      {
         for (q = 0; q < n; q++)
         {
            ele = co[i][q] * con[q];
            val += ele;
         }
         printf("value of x%d is %f.\n", i+1, val);
         val = 0;
      }
   }

   return ;
}

int Error(char *message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}

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

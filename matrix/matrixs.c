#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        10

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i,j,k,l,m,n;
   int        matrix1[MAX][MAX],matrix2[MAX][MAX],matrix3[MAX][MAX];

   printf("Enter the number of rows and columns of first matrix\n");
   scanf("%d%d", &k,&l);

   if ((k <= 0) || (l <=0))
   {
      printf("Enter a valid input for the order of matrix\n");
      exit(1);
   }
   else if ((k > MAX) || (l > MAX))
   {
      printf("The limit of matrix is %d by %d\n", MAX,MAX);
      exit(2);
   }

   printf("Enter the elements of first matrix\n");
   for (i = 0; i < k; i++)
   {
      for (j = 0; j < l; j++)
      {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("Enter the number of rows and columns of second matrix\n");
   scanf("%d%d", &m,&n);

   if ((m <= 0) || (n <= 0))
   {
      printf("Enter a valid input for the order of matrix\n");
      exit(1);
   }
   else if ((m > MAX) || (n > MAX))
   {
      printf("The limit of the matrix is %d by %d\n", MAX,MAX);
      exit(2);
   }
   else if ((k != m) || (l != n))
   {
      printf("Matrix subtraction is not possible for given order of matrices\n");
      exit(3);
   }

   printf("Enter the elements of second matrix\n");
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &matrix2[i][j]);
      }
   }

   for (i = 0; i < k; i++)
   {
      for (j = 0; j < l; j++)
      {
         matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
      }
   }

   printf("The resultant matrix is:- \n");
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         printf(" %d  ", matrix3[i][j]);
      }
      printf("\n");
   }
   exit(0);
}

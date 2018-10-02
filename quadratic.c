#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

/********* DEFINED CONSTANTS *********/
#define MAX         3

/********* FUNCTION DECLARATION *********/
void realvalue(float real[]);
void complexvalue(float complex z[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int                 i;
   float               real[MAX], imag[MAX];
   float complex       z[MAX];

   for (i = 0; i < MAX; i++)
   {
      printf("Enter the coefficient of x^%d\n", i);
      printf("real part of x^%d:- ", i);
      scanf("%f", &real[i]);
      printf("imag part of x^%d:- ", i);
      scanf("%f", &imag[i]);
      printf("\n");
   }

   if (imag[0] == 0 && imag[1] == 0 && imag[2] == 0)
   {
      realvalue(real);
   }
   else
   {
      for (i = 0; i < MAX; i++)
      {
         z[i] = real[i]+imag[i]*I;
      }
      complexvalue(z);
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void realvalue(float real[])
{
   float              det, root1, root2, a, b;
   float complex      z1, z2;

   det = ((real[1]*real[1])-(4*real[2]*real[0]));

   if (det >= 0)
   {
      root1 = (-real[1]+sqrtf(det))/(2*real[2]);
      root2 = (-real[1]-sqrtf(det))/(2*real[2]);
      printf("The roots are %f and %f.\n", root1, root2);
   }
   else
   {
      det = -det;
      a = (-real[1]/(2*real[2]));
      b = (sqrtf(det)/(2*real[2]));

      z1 = a+b*I;
      z2 = conjf(z1);
      printf("Roots are %f+(%fi) and its conjugate ", creal(z1), cimag(z1));
      printf("%f+(%fi).\n", creal(z2), cimag(z2));
   }

   return ;
}

void complexvalue(float complex z[])
{
   float complex         z1, z2, det;

   det = ((z[1]*z[1])-(4*z[2]*z[0]));

   z1 = (-z[1]+csqrtf(det))/(2*z[2]);
   z2 = (-z[1]-csqrtf(det))/(2*z[2]);

   printf("Roots are %f+(%fi) and its conjugate ", creal(z1), cimag(z1));
   printf("%f+(%fi).\n", creal(z2), cimag(z2));

   return ;
}

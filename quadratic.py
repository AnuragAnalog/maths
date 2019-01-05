#!/usr/bin/python3.6

""" This program takes the co-efficients of the quadratic equation as input computes the roots even if they are complex and does the computation for a complex-valued function. """

from cmath import sqrt as csqrt
from math import sqrt

###### Function definition ######

def realvalue(real):
    det = ((real[1]*real[1])-(4*real[2]*real[0]))

    if det >= 0:
        root1 = (-real[1]-sqrt(det))/(2*real[2])
        root2 = (-real[1]+sqrt(det))/(2*real[2])
        print("The roots are", root1, "and", root2)
    else:
        det = -det
        a = (-real[1]/(2*real[2]))
        b = (sqrt(det)/(2*real[2]))
        print("The roots are a complex conjugate pair:")
        print(complex(a, b), "and", complex(a, -b))

def complexvalue(z):
    det = ((z[1]*z[1])-(4*z[2]*z[0]))

    a = (-z[1]/(2*z[2]))
    b = (csqrt(det)/(2*z[2]))
    print("The roots are:")
    print(a+b, "and", a-b)

real = list()
imag = list()
for i in range(3):
    print(f"Enter the co-efficent of x^{i}")
    print("Real part of x^{i}")
    a = float(input(""))
    print("Imag part of x^{i}")
    b = float(input(""))
    real.append(a)
    imag.append(b)

if imag[0] == 0 and imag[1] == 0 and imag[2] == 0:
    realvalue(real)
else:
    z = list()
    for i in range(3):
        a = complex(real[i], imag[i])
        z.append(a)
    complexvalue(z)

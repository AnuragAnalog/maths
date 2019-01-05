#!/usr/bin/python3.6
""" This program finds the maximum of a given function(static) in the given interval,
with a precision of 3 digits""" 

import numpy as np
import math

def f(x):
    fx = x**3 + 4*x + 25
    return fx

def function_max(a, b):
    fmax = f(a)
    values = np.arange(a, b+0.0001, 0.0001)
    for i in values:
        if f(i) > fmax:
            fmax = f(i)
            at = i
    return at, fmax

a = float(input("Enter the lower bound: "))
b = float(input("Enter the upper bound: "))

if a < b:
    point, maxi = function_max(a, b)
    print(f"The maximum of the f(x) in [{a}, {b}] is {maxi} at {point}")
else:
    print("The length of the interval should be greater than zero")

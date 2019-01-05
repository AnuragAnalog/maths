#!/usr/bin/python3.6
""" This program finds the minimum of a given function(static) in the given interval, with a precision of 3 digits"""

import numpy as np
import math

def f(x):
    fx = math.sin(x) + math.cos(x)
    return fx

def function_max(a, b):
    fmin = f(a)
    values = np.arange(a, b+0.0001, 0.0001)
    for i in values:
        if f(i) < fmin:
            fmin = f(i)
            at = i
    return at, fmin

a = float(input("Enter the lower bound: "))
b = float(input("Enter the upper bound: "))

if a < b:
    point, mini = function_max(a, b)
    print(f"The minimum of the f(x) in [{a}, {b}] is {mini} at {point}")
else:
    print("The length of the interval should be greater than zero")

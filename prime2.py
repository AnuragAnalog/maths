#!/usr/bin/python3

from math import *
from math import sqrt as sqrt

def primes(n):
    yes = "{} is a prime".format(n)
    no = "{} is not a prime".format(n)

    if n == 1:
        return no
    elif n == 2:
        return yes
    elif n>2 and n%2 == 0:
        return no

    sqrtn = int(sqrt(n))
    for i in range(3, sqrtn+1, 2):
        if n%i == 0:
            return no
    return yes

n = int(input("Enter the number: "))
status = primes(n)
print(status)

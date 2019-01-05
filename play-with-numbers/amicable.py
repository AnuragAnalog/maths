#!/usr/bin/python3.6

""" 
   Let d(n) be defined as the sum of proper diviors of n (numbers less than n which divide evenly into n).
    If d(a) = b and d(b) = a, where a != b, then a and b ae an amicable pair and each of the a and b are called amicable numbers.
"""

def properdivisors(num):
    factors = list()
    for i in range(1, num):
        if num%i == 0:
            factors.append(i)
    return factors

def amicable(n):
    for i in range(2, n+1):
        properdiv1 = list()
        properdiv2 = list()

        properdiv1 = properdivisors(i)
        num = sum(properdiv1)
        properdiv2 = properdivisors(num)

        if (i == sum(properdiv2) and i != num):
            print(i, num)
    print(f"These are the amicable numbers between 2 and {n+1}")

num = int(input("Enter the number: "))
amicable(num)

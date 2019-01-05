#!/usr/bin/python3.6
""" A perfect number is a number for which the sum of its proper divisors is
exactly equal to the number. For example, the sum of the proper divisors of 28
would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n
 and it is called abundant if this sum exceeds n. """

def numbers(n):
    tot = 0
    for i in range(1, n):
        if n%i == 0:
            tot = tot + i

    if tot == n:
        print(f"{n} is a perfect number.")
    elif tot > n:
        print(f"{n} is a abundant number")
    elif tot < n:
        print(f"{n} is a deficient number")
    return None

n = int(input("Enter a number: "))
numbers(n)

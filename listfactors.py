#!/usr/bin/python3

""" Finds all the factors of a given number. """

num = int(input("Enter the number: "))

factors = list()
for i in range(1, num+1):
    if num%i == 0:
        factors.append(i)

print(factors)

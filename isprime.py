#!/usr/bin/python3.6

""" Checks wheather the given number is a prime or not."""

def isprime(num):
    if num == 1:
        print("1 is not a prime number.")
        quit()
    factors = list()
    for i in range(1, num+1):
        if num%i == 0:
            factors.append(i)

    if len(factors) == 2:
        print(f"{num} is a prime.")
    else:
        print(f"{num} is not a prime")

n = int(input("Enter a number: "))
isprime(n)

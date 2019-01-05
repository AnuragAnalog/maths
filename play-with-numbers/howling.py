#!/usr/bin/python3.6

"""
    A Howling prime is a prime number if the sum of it's digits is also a prime number.
"""

def isprime(num):
    if num == 1:
        print("1 is not a prime number.")
        quit()
    factors = list()
    for i in range(1, num+1):
        if num%i == 0:
            factors.append(i)

    if len(factors) == 2:
        return 1
    else:
        return 0

def howling(num):
    if isprime(num) == 0:
        print(f"{num} is not a prime.")
        quit()
    num2list = list(map(int, list(str(num))))
    num2 = sum(num2list)

    if isprime(num2):
        print(f"{num} is a howling prime")
    else:
        print(f"{num} is not a howling prime")

num = int(input("Enter a prime: "))
howling(num)

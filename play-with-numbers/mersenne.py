#!/usr/bin/python3.6

"""
    A Mersenne prime is a prime number hat is one less than a power of two. It is a prime number of the form 2^n-1 for some integer n.
"""

def isprime(num):
    factors = list()
    for i in range(1, num+1):
        if num%i == 0:
            factors.append(i)

    if len(factors) == 2:
        return None
    else:
        print(f"{num} is not a prime")
        quit()

def mersenne(num):
     isprime(num)
     one = "1"
     i = 0
     while True:
         if bin(num)[2:] == one*(i+1):
             print(f"{num} is a mersenne prime")
             quit()
         if int(one*(i+1), 2) > num:
             print(f"{num} is not a mersenne prime")
             quit()
         i = i + 1

num = int(input("Enter a prime number: "))
mersenne(num)

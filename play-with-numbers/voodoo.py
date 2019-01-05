#!/usr/bin/python3.6

def isprime(num):
    factors = list()
    for i in range(1, num+1):
        if num%i == 0:
            factors.append(i)
    if (len(factors) == 2):
        return None
    else:
        print(f"{num} is not a prime number.")
        quit()

def voodoo(n):
    isprime(n)

    if str(n) in str(1/n):
        print(f"{n} is a voodoo prime")
    else:
        print(f"{n} is not a voodoo prime")

num = int(input("Enter a prime number: "))
voodoo(num)

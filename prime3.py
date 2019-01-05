#!/usr/bin/python3.6

##### Sieve of Eratosthenes #####

""" Calculates prime numbers, Enter the upper range of Primes."""

def seiveoferatosthenes(num):
    primes = [i for i in range(2, num+1)]
    i = 0
    while i < len(primes):
        p = primes[i]
        j = i + 1
        while j < len(primes):
            if primes[j]%p == 0:
                primes.remove(primes[j])
            else:
                j = j + 1
        i = i + 1
    print(primes)

num = int(input("Enter a upper range of primes: "))
seiveoferatosthenes(num)

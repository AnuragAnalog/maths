#!/usr/bin/python3.6
""" The number 3797 has an interesting property. Being prime itself, it
 is possible to continuously remove digits from left to right, and remain
 prime at each stage: 3797, 797, 97, and 7. Similarly we can work from
 right to left: 3797, 379, 37, and 3. """

def isprime(n):
    check = 0
    if n == 1:
        return False
    for i in range(1, n+1):
        if n%i == 0:
            check = check + 1
    if check == 2:
        return True
    return False

def truncate_prime(n):
    if isprime(int(n)) != 1:
        print(f"{n} is not a prime")
        return

    for i in range(1,len(n)):
        if isprime(int(n[i:])):
            continue
        else:
            print(f"{n} is not a truncatable prime from left to right")
            return

    for i in range(2, len(n)):
        if isprime(int(n[-i::-1])):
            continue
        else:
            print(n[-i::-1])
            print(f"{n} is not a truncatable prime from right to left")
            return

n = input("Enter the number: ")
truncate_prime(n)

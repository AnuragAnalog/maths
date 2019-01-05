#!/usr/bin/python3.6
""" The following iterative sequence is defined for the set of positive integers:
    n → n/2 (n is even)
    n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1 """

def collatz(n):
    lt = [n]
    while n != 1:
        if n%2 == 0:
            n = n/2
        else:
            n = 3*n + 1
        lt.append(n)
    return lt

n = int(input("Enter the number: "))
n1 = n
lt = collatz(n)
print(f"The collatz sequence with starting number {n1} is")
print(lt)

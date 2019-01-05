#!/usr/bin/python3.6
""" The given program will say whether the given number is a circular prime or not. The number, 197, is called a circular prime because all rotations of the
digits: 197, 971, and 719, are themselves prime."""

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

def circular_number(n):
    nums = list()
    lt = list(map(int, n))
    for i in range(len(lt)):
        nums.append(int("".join(list(map(str, lt)))))
        x = lt[0]
        lt = lt[1:]
        lt.append(x)
    return nums

def circular_prime(n):
    check = 0
    nums = circular_number(n)
    for i in range(len(nums)):
        if isprime(nums[i]):
            check = check + 1
    if check == len(nums):
        print(f"Given number {n} is a circular prime")
    else:
        print(f"Given number {n} is not a circular prime")

n = input("Enter the number: ")
circular_prime(n)

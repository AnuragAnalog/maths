#!/usr/bin/python3.6
""" This program computes the square root of the number using babylonian method"""

def babylonian(n):
    y = 1
    x = n
    err = 0.1 ** 6
    while x - y > err:
        x = (x+y)/2
        y = n/x
    return x

n = int(input("Enter the number: "))
if n == 0 or n == 1:
    print("The sqrt of {} is {}".format(n, float(n)))
    quit()
elif n < 0:
    print("Enter only positive number")
    quit()

sqroot = babylonian(n)
print(f"The sqrt of {n} is {sqroot}")

#!/usr/bin/python3.6
""" If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
    It is thought that some numbers, like 196, never produce a palindrome.
 A number that never forms a palindrome through the reverse and add process
  is called a Lychrel number. Due to the theoretical nature of these numbers,
 and for the purpose of this problem, we shall assume that a number is Lychrel
 until proven otherwise. In addition you are given that for every number below
 ten-thousand, it will either (i) become a palindrome in less than fifty
 iterations, or, (ii) no one, with all the computing power that exists, has
 managed so far to map it to a palindrome. """

def ispalindrome(s):
    return s[:] == s[::-1]

def lychrel(n):
    tot = n
    for i in range(50):
        temp = list(str(tot))
        temp.reverse()
        tot += int("".join(temp))
        if ispalindrome(str(tot)):
            print(f"Given {n} is not a lychrel number")
            return None
    print(f"Given {n} is a lychrel number")

n = int(input("Enter the number: "))
lychrel(n)

#!/usr/bin/python3.6
""" This script takes n +ve numbers as input and displays a histogram bar graph""" 

import numpy as np
import matplotlib.pyplot as plt

def histogram(n):
    ls = list()
    for i in range(n):
        num = int(input("Enter the number: "))
        ls.append(num)
    ls = np.array(ls)
    freq = np.bincount(ls)
    mini = ls.min()
    maxi = ls.max()
    print({i:freq[i] for i in range(mini, maxi+1)})
    return freq

def bar_graph(freq):
    index = np.arange(len(freq))
    plt.bar(index, freq)
    plt.xlabel("Numbers", fontsize=8)
    plt.ylabel("Frequency", fontsize=8)
    plt.xticks(index, [i for i in range(len(freq))], fontsize=12)
    plt.title("Histogram")
    plt.show()

n = int(input("Enter the number of values in the list: "))
freq = histogram(n)
bar_graph(freq)

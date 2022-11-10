from cmath import sqrt


import math


def check(n):

    for i in range(2, n):
        if n % i == 0:
            return 0
    return 1


j = int(input())

if (check(j) == 1):
    print("la so nguyn to", j)
else:
    print("ko la so nguyen to")

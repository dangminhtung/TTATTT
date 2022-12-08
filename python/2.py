import math


def check(n):
    if (n < 2):
        return False
    for i in range(2, int(math.sqrt(n)+1)):
        if n % i == 0:
            return False
    return True


n = int(input("nhap n: "))
s = int(math.pow(10, n-1))
e = int(math.pow(10, n)-1)
for i in range(s, e):
    if (check(i)):
        print(i, " ")

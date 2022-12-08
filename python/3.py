import math


def check(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


p = 0
s = 0
k = 0
q = 0
n = int(input("nhap N: "))
for i in range(1, n+1):
    if (n % i == 0):
        s += 1
        p += i
        if (check(i)):
            k += 1
            q += i
sum = n+p+s-q-k
print("tong bang :", sum)

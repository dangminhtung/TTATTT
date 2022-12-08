import math


def reverse(n):
    tp = n
    rev = 0
    while (tp > 0):
        rev = (rev*10)+tp % 10
        tp //= 10
    return rev


def check(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


n = int(input("nhap N: "))
print("cac so thoa man: ")
for i in range(1, n):
    rev = reverse(i)
    if check(i) and check(rev):
        print(i)

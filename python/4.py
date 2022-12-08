import math


def check(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


a = int(input("nhap A: "))
b = int(input("nhap B: "))
print("cac so nguyen to: ")
for i in range(a, b+1):
    if check(i):
        print(i)

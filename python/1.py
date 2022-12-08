
def prime(n):
    d = 2
    for i in range(2, int(n/2)+1, 1):
        if (n % i == 0):
            d = d+1
    if (d != 4):
        return False
    return True


n = -1
while (n < 0):
    n = int(input("nhap n: "))
for i in range(0, n, 1):
    if (prime(i)):
        print(i, "is prime")

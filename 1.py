def check(n):
    d = 2
    for i in range(2, n, 1):
        if (n % i == 0):
            d = d+1
    if (d == 4):
        return 1
    else:
        return 0


print("nhap so N: ")

n = int(input())
for i in range(2, n+1):
    if (check(i) == 1):
        print("la so prime", i)

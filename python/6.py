temp = int(input("nhap n:"))
p = q = 0
for i in range(2, temp):
    p = q = 0
    n = i
    for j in range(1, n):
        if n % j == 0:
            p += j
    for h in range(1, p):
        if p % h == 0:
            q += h

    if q == n and p != q:
        print("cap so do la: ", n, p)

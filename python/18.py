import math


def tinhmang(w, t, a):
    j = 1
    temp = []
    for i in range(3, -1, -1):
        temp[i] = a//math.pow(2, (t-j)*w)
        a = a % int(math.pow(2, (t-j)*w))
        j += 1
    return temp


a = int(input("nhap a: "))
tp = tinhmang(8, 4, a)
for i in range(3, -1, -1):
    print(tp[i])

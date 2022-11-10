n = int(input("nhap so N:"))
for i in range(2, n):
    p = q = 0
    for j in range(1, i):
        if i % j == 0:
            p += j
    for h in range(1, p):
        if p % h == 0:
            q += h
    if (q == i and p != q):
        print("2 so do la ", i, p)
# phân tích ước n là p
# xem p có phải số hòa hợp với n không bằng các thử lại
# thêm 1 vòng lặp for tìm các ước của p
# nếu tổng các ước của p bằng n => n và p là 2 số hòa hợp
# note : nếu tổng các ước của n bằng chính nó thì ko thỏa mãn

#include <stdio.h>
#include <math.h>
// giống câu 4 nhưng tính tổng
int main()
{
    int n, i, j, p, t, d, a, b, Tong;
    Tong = 0;
    printf("\nNhap A: ");
    scanf("%d", &a);
    printf("\nNhap B: ");
    scanf("%d", &b);
    int c[b];
    for (i = a; i <= b; i++)
    {
        c[i] = 1;
    }
    for (p = 2; p < b; p++)
    {
        t = b / p;
        for (i = 2; i <= t; i++)
            c[p * i] = 0;
    }
    printf("(");
    for (i = a; i <= b; i++)
    {
        if (c[i] == 1)
        {
            Tong = Tong + i;
        }
    }
    printf("%d)", Tong);
}

#include <stdio.h>
#include <stdlib.h>
int euclideMR(int a, int b)
{
    int q, r, x, y, x2, x1, y2, y1, d;
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        return y2;
    }
    x2 = 1;
    x1 = 0;
    y2 = 0;
    y1 = 1;
    while (b > 0)
    {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    y = y2;
    return y2;
}
int main()
{
    int p, n;
    printf("Nhap p: ");
    scanf("%d", &p);
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    int i, arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
        printf("%d ", euclideMR(p, arr[i]));
}

#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, d, q, r, x, y, x1, x2, y1, y2;
    printf("\nNhap hai so duong a,b, a lon hon b:");
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("\nNhap b: ");
    scanf("%d", &b);
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        printf("\n(d,x,y) = (%d,%d,%d)\n", d, x, y);
        return 1;
    }
    x1 = 0;
    x2 = 1;
    y1 = 1;
    y2 = 0;
    /*    int a1=a,b1=b,r1;
        while (a1>0)
        {
            r1=a1%b1;
            a1=b1;
            b1=r1;
        }
        if(b1!=1)
        {
            printf("khong co ket qua d thoa man a^-1 mod b = d ");
            reutrn 0;
        }*/
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
    d = a;
    x = x2;
    y = y2;
    printf("\n(d,x,y) = (%d,%d,%d)\n", d, x, y);
}

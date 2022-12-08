// cách 2 nhưng time chạy lâu hơn nhưng có thể chạy được dãy số dài hơn
#include <stdio.h>
#include <math.h>

int check(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;

    printf("nhap n:");
    scanf("%d", &n);
    int s, e;
    s = pow(10, n - 1);
    printf("%d", s);
    e = pow(10, n) - 1;
    printf("%d", e);
    int i;
    for (i = s; i < e; i++)
    {
        // printf("%d", i);

        if (check(i) == 1)
        {
            printf("%d    ", i);
        }
    }
}

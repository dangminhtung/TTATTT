#include <stdio.h>
#include <math.h>
// chắc tùy máy vì máy mình làm đc 5 là căng, máy bạn mình làm đc tận 10
int main()
{
    long n, i, j, p, t, d;
    printf("\nNhap n: ");
    scanf("%d", &n);
    d = pow(10, n - 1);
    n = pow(10, n) - 1;
    long a[n];
    for (i = d; i <= n; i++)
    {
        a[i] = 1;
    }
    for (p = 2; p < n; p++)
    {
        t = n / p;
        for (i = 2; i <= t; i++)
            a[p * i] = 0;
    }
    printf("(");
    for (i = d; i <= n; i++)
    {
        if (a[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf(")");
}

// cách 2 nhưng time chạy lâu hơn nhưng có thể chạy được dãy số dài hơn
// #include <stdio.h>
// #include <math.h>

// int check(int n)
// {

//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     int n;

//     printf("nhap n:");
//     scanf("%d", &n);
//     int s, e;
//     s = pow(10, n - 1);
//     printf("%d", s);
//     e = pow(10, n) - 1;
//     printf("%d", e);
//     int i;
//     for (i = s; i < e; i++)
//     {
//         // printf("%d", i);

//         if (check(i) == 1)
//         {
//             printf("%d    ", i);
//         }
//     }
// }
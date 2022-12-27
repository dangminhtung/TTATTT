#include <stdio.h>
int chuyenHeNP(int k, int arr[20])
{
    int i = 0;
    while (k > 0)
    {
        arr[i] = k % 2;
        k /= 2;
        i++;
    }
    return i;
}
long long int TTNhanBPCoLap(int a, int k, long long int n)
{
    if (k == 0)
        return a;
    long long int b = 1, i, A = a;
    int arr[20];
    int k0 = chuyenHeNP(k, arr);
    if (arr[0] == 1)
        b = a;
    for (i = 1; i < k0; i++)
    {
        A = A * A % n;
        if (arr[i] == 1)
            b = b * A % n;
    }
    return b;
}
int kiemTraMillerRabin(int n, int t)
{
    int s = 0, r = n - 1, i, j, y;
    while (r % 2 == 0)
    {
        r = r / 2;
        s++;
    }
    for (i = 0; i < t; i++)
    {
        int a = rand() % (n - 2) + 2;
        y = TTNhanBPCoLap(a, r, n);
        if (y != 1 && y != n - 1)
        {
            j = 1;
            while (j < s && y != n - 1)
            {
                y = y * y % n;
                if (y == 1)
                    return 0;
                j++;
            }
            if (y != n - 1)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n = 2, t;
    while (n < 3 || n % 2 == 0)
    {
        printf("Nhap so nguyen le n: ");
        scanf("%d", &n);
    }
    printf("Nhap t: ");
    scanf("%d", &t);
    if (kiemTraMillerRabin(n, t))
        printf("So nguyen to");
    else
        printf("Hop so");
}

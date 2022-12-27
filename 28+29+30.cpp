#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

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

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
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
    // tach n = 2^s * r
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

bool isCarmichaelNumber(int n)
{
    if (n <= 2 || kiemTraMillerRabin(n, 1))
        return false;
    for (int b = 2; b < n; b++)
    {
        if (gcd(b, n) == 1)
        {
            if (TTNhanBPCoLap(b, n - 1, n) != 1)
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    printf("nhap N: ");
    scanf("%d", &n);
    printf("so Carmichael la: ");
    int count = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isCarmichaelNumber(i))
        {
            printf("%d ", i);
            count++;
            sum += i;
        }
    }
    printf("so so Carmichael la: %d", count);
    printf("Tong cua cac so Carmichael la: %d", sum);
    return 0;
}
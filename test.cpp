#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

long long int nhanbpcolap(long long int A, long long int n, long long int p)
{
    int i = 0;
    long long int b = 1;
    int Arr[100];
    while (n > 0)
    {
        if (n & 1)
        {
            Arr[i++] = 1;
        }

        else
        {
            Arr[i++] = 0;
        }
        n >>= 1;
    }
    if (Arr[0] == 1)
        b = A;
    for (int j = 1; j < i; j++)
    {

        A = A * A % p;
        if (Arr[j])
        {
            b = A * b % p;
        }
    }
    return b;
}

int get_a(int n)
{
    return 2 + rand() % (n - 3);
}
int miller_rabin(int n)
{
    if (n % 2 == 0)
        return 0;
    int r = n - 1;
    int s = 0;
    while (!(r & 1))
    {
        r >>= 1;
        s++;
    }
    int a = 0;
    a = get_a(n);
    int b, y;
    b = nhanbpcolap(a, r, n);
    if (b - 1 == 0 || b + 1 == n)
        return 1;
    for (int j = 0; j <= s - 1; j++)
    {
        b = b * b % n;
        if (b + 1 == n)
            return 1;
    }
    return 0;
}
int MR_t(int n, int t)
{
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 1; i <= t; i++)
    {
        if (miller_rabin(n) == 0)
            return 0;
    }
    return 1;
}

int inverse(int a, int b)
{
    int d, q, r, x, y, x2, x1, y2, y1, temp;
    int preb = b;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    x2 = 1;
    x1 = 0;
    y2 = 0;
    y1 = 1;
    while (b > 0)
    {
        q = a / b;
        r = a % b;
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
    if (y < 0)
        y = y + preb;
    return y;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int p, q, phi, c;
    int n;
    int d;
    srand(time(0));
    p = rand() % 400 + 100;
    q = rand() % 400 + 100;
    while (!MR_t(p, 3) || !MR_t(q, 3))
    {
        if (!MR_t(p, 3))
            p = rand() % 400 + 100;
        if (!MR_t(q, 3))
            q = rand() % 400 + 100;
    }
    printf("p = %d ,q = %d\n", p, q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    printf("n = %d , phi = %d\n", n, phi);
    int m;
    printf("nhap ma sinh vien: ");
    scanf("%d", &m);
    m = m + 123;
    int e = rand() % (phi - 1) + 1;
    while (gcd(e, phi) != 1)
        e = rand() % (phi - 1) + 1;
    printf("Plaintext : %d\n", m);
    printf("e  = %d\n", e);
    printf("%d^%d mod %d\n", m, e, n);
    if (m > n)
    {
        printf("%d^%d mod %d\n", m % n, e, n);
    }
    c = nhanbpcolap(m, e, n);
    if (c < 0)
        c += n;
    printf("Ciphertext: %d\n", c);
    d = inverse(e, phi);
    printf("d = %d\n", d);
    int plaintext = nhanbpcolap(c, d, n);
    printf("Decode: %d\n", plaintext);
}
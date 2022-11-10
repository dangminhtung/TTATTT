#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    int rev = 0;
    while (x > 0)
    {
        rev = (rev * 10) + x % 10;
        x = x / 10;
    }
    return rev;
}
void printEmirp(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            int rev = reverse(p);
            if (p != rev && rev <= n && prime[rev])
            {
                cout << p << "" << rev << "";
                prime[rev] = false;
            }
        }
    }
}
int main()
{
    int n = 40;
    printEmirp(n);
    return 0;
}
// #include <iostream>
// #include <math.h>
// using namespace std;

// int reverse(int n)
// {
//     int temp = n;
//     int rev = 0;
//     while (temp > 0)
//     {
//         rev = (rev * 10) + temp % 10;
//         temp /= 10;
//     }

//     return rev;
// }
// int check(int n)
// {
//     if (n == 2)
//     {
//         return 1;
//     }
//     for (int i = 2; i < sqrt(n); i++)
//     {
//         if (n % i == 0)
//             return 0;
//     }
//     return 1;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i < n; i++)
//     {
//         int rev = reverse(i);
//         if (check(i) == 1 && check(rev) == 1)
//         {
//             cout << i << " ";
//         }
//     }
// }

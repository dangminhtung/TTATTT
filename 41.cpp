#include <iostream>
#include <math.h>
using namespace std;

bool check(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int power(int a, int k, int mod)
{
    if (k == 0)
        return 1;
    int temp = power(a, k / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (k % 2 == 1)
    {
        temp = (temp * a) % mod;
    }
    return temp;
}
int main()
{
    int a = -1, k = -1, n = -1;
    while (a < 0 || a > 1000)
    {
        cout << "nhap 0<a<1000: ";
        cin >> a;
    }
    while (k < 0 || n < 0 || k > n || k > 1000 || n > 1000)
    {
        cout << "nhap 0<k<n<1000: ";
        cin >> k >> n;
    }
    cout << power(a, k, n);
    if (check(power(a, k, n)))
    {
        cout << "thoa man";
    }
    else
    {
        cout << "ko thoa man";
    }
}
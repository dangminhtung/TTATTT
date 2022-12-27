#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
        temp = (temp * x) % mod;
    return temp;
}
bool check(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isCarmichaelNumber(int n)
{
    if (n <= 2)
        return false;
    for (int b = 2; b < n; b++)
    {

        if (gcd(b, n) == 1)

            if (power(b, n - 1, n) != 1 || check(n))
                return false;
    }
    return true;
}

int main()
{
    int n, c = 0, sum = 0;
    cout << "nhap N: ";
    cin >> n;
    cout << "so Carmichael la: ";
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isCarmichaelNumber(i))
        {
            cout << i << " " << endl;
            c++;
            sum += i;
        }
    }
    cout << "so luong: " << c;
    cout << "tong: " << sum;
}
#include <iostream>
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
    // sử dụng thuật toán nhân bình phương
    // phân tích mũ ra số nhị phân
    // nhân với chính nó rồi mod
    // tương ứng với 1 thì nhân thêm với x
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
        temp = (temp * x) % mod;
    return temp;
}

bool isCarmichaelNumber(int n)
{
    for (int b = 2; b < n; b++)
    {

        if (gcd(b, n) == 1)

            if (power(b, n - 1, n) != 1)
                return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "nhap N: ";
    cin >> n;
    cout << "so Carmichael la: ";
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isCarmichaelNumber(i))
        {
            cout << i << " ";
            // count++;
        }
    }
    // cout << count;
    return 0;
}
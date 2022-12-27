#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
int check(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int EuclidExtended(int e, int phi)
{
    int x, y, x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    int r, q;
    while (e > 0)
    {
        q = phi / e;
        r = phi % e;
        x = x2 - q * x1;
        y = y2 - q * y1;
        phi = e;
        e = r;
        x2 = x1;
        y2 = y1;
        x1 = x;
        y1 = y;
    }
    return y2;
}
int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
    {
        temp = (temp * x) % mod;
    }
    return temp;
}
int main()
{
    int p,
        q;
    while (p <= 100)
    {
        cout << "Nhap p la so NT: ";
        cin >> p;
    }
    while (q >= 500)
    {
        cout << "Nhap q la so NT: ";
        cin >> q;
    }
    int n = p * q;
    int phiN = (p - 1) * (q - 1);
    cout << "PhiN :" << phiN << endl;
    int e;
    while (1)
    {
        cout << "chon e thoa man e va phiN  la NT cung nhau: ";
        cin >> e;
        if (gcd(e, phiN) == 1)
        {
            break;
        }
        else
            cout << "ko thoa man thu lai!" << endl;
    }
    // tìm d(nếu d là âm thì cộng thêm với phiN để ra số dương)
    int d = EuclidExtended(e, phiN);
    if (d < 0)
        d = d + phiN;
    cout << "d= " << d << endl;

    int sbd;
    int m;
    cout << "nhap SBD: ";
    cin >> sbd;

    m = sbd + 123;

    cout << "ban ma M luc dau: " << m << endl;
    int c = power(m, e, n);
    cout << "ma hoa: " << c << endl;
    int temp = power(c, d, n);
    cout << "giai ma: " << temp;
}
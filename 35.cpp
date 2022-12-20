#include <iostream>
#include <math.h>
using namespace std;

int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int r = power(x, y / 2, mod) % mod;
    r = (r * r) % mod;
    if (y % 2 == 1)
    {
        r = (r * x) % mod;
    }
    return r;
}
int check_miller_rabin(int n, int y, int s)
{
    if (y != 1 && y != n - 1)
    {
        int j = 1;
        while (j < s && y != n - 1)
        {
            y = (y * y) % n;
            if (y == 1)
                return 0;
            j += 1;
        }
        if (y != n - 1)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    cout << "nhap n la so le >1:  ";
    cin >> n;
    // while (n < 2 || n % 2 == 0)
    // {
    // cout << "loi nhap lai!" << endl;
    // cout << "nhap n la so le >1:  ";
    // cin >> n;
    // }
    int s;
    int r = n - 1;
    while (r > 0)
    {
        if (r % 2 == 1)
        {
            cout << "s= " << s << " r= " << r << endl;
            break;
        }
        if (r % 2 == 0)
        {
            s++;
            r /= 2;
        }
    }
    int a = 2 + rand() % n - 2;
    cout << "a dc lua chon: " << a << endl;
    int y = power(a, r, n);
    cout << "y= " << y << endl;
    if (check_miller_rabin(n, y, s) == 1)
    {
        cout << "nguyen to!";
    }
    else
    {
        cout << "hop so";
    }
    int e;
    cin >> e;
    for (int i = 2; i <= e; i++)
    {
        if (check_miller_rabin(i, y, s) == 1)
        {
            cout << i << " ";
        }
    }
}
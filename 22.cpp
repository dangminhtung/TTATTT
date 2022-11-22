#include <iostream>
#include <math.h>
using namespace std;
bool check(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int tinhF(int i)
{
    if (check(i))
    {
        return i;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int l, r, tong = 0;
    cout << "nhap L, R: ";
    cin >> l >> r;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            if (j > i)
            {
                cout << "F[" << i << "]"
                     << "*"
                     << "F[" << j << "]= " << tinhF(i) * tinhF(j) << endl;
                ;
                tong = tong + tinhF(i) * tinhF(j);
            }
        }
    }
    cout << "tong= " << tong;
}
#include <iostream>
#include <math.h>
using namespace std;

bool check(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    int tong, hieu;
    cout << "nhap N:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            for (int j = i; j <= n; j++)
            {
                if (check(j))
                {
                    tong = i + j;
                    hieu = abs(i - j);
                    if (check(tong) && check(hieu))
                    {
                        cout << "2 so do la :" << i << " " << j << endl;
                    }
                }
            }
        }
    }
}
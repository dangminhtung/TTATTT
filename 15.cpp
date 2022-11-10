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
int main()
{
    int n;
    cout << "Nhap N:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            for (int j = i; j <= n; j++)
            {
                if (check(j) && j - i == 2)
                {
                    cout << "2 Cap so do la: " << i << " " << j << endl;
                }
            }
        }
    }
}
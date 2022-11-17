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
    int count = 0;
    int n;
    cout << "nhap N: ";
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (check(i))
        {
            cout << i;
            count++;
        }
    }
    cout << "so luong" << count;
}
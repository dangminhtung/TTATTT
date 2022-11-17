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
    int a, b;
    int count = 0;
    cout << "nhap a, b: ";
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (check(i))
        {
            cout << i;
            count += i;
        }
    }
    cout << "so nguyen to: " << count;
}
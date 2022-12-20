// cách 2 nhưng time chạy lâu hơn nhưng có thể chạy được dãy số dài hơn
#include <math.h>
#include <iostream>
using namespace std;

bool check(unsigned long long int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (unsigned long long int i = 5; i <= sqrt(n); i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long int n;
    cin >> n;
    long long int s, e;
    s = pow(10, n - 1);
    e = pow(10, n) - 1;
    for (long long int i = s; i < e; i++)
    {
        if (check(i) == 1)
        {
            cout << i << ".0" << endl;
        }
    }
}
#include <iostream>
#include <cmath>
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
    unsigned long long int a, b, s = 0;
    cin >> a >> b;
    for (unsigned long long int i = a; i <= b; i++)
    {
        if (check(i))
        {
            s += i;
        }
    }
    cout << s;
}
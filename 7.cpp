#include <iostream>
#include <math.h>
using namespace std;

int reverse(int n)
{
    int temp = n;
    int rev = 0;
    while (temp > 0)
    {
        rev = (rev * 10) + temp % 10;
        temp /= 10;
    }

    return rev;
}
int check(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int rev = reverse(i);
        if (check(i) == 1 && check(rev) == 1)
        {
            cout << i << " ";
        }
    }
}

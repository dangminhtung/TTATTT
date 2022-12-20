// Q-prime aka 1 số có 4 ước thì là đúng

#include <stdio.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
bool check(long long int n)
{
    long long int d = 2; // Mỗi số có ít nhất là 2 ước : 1 và chính nó
    for (long long int i = 2; i <= n / 2; i++)
    { // Giảm thiểu bước nhảy, tự suy luận đi bạn :(
        if (n % i == 0)
            d++;
    }
    return d == 4;
}
int main()
{
    long long int n, s = 0;
    cin >> n;
    if (n <= 5)
    {
        cout << "No";
    }
    else
    {
        for (long long int i = 1; i <= n; i++)
        {
            if (check(i))
            {
                s = 1;
                cout << i << endl;
            }
        }
        if (s == 0)
        {
            cout << "No";
        }
    }
}

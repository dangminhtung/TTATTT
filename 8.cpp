#include <stdio.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
bool check(unsigned long long int n)
{
    unsigned long long int d = 2; // Mỗi số có ít nhất là 2 ước : 1 và chính nó
    for (unsigned long long int i = 2; i <= n / 2; i++)
    { // Giảm thiểu bước nhảy, tự suy luận đi bạn :(
        if (n % i == 0)
        {
            d++;
        }
    }
    return d == 3;
}
int main()
{
    unsigned long long int n;
    cin >> n;
    for (unsigned long long int i = 4; i <= n; i++)
    {
        if (check(i))
            cout << i << endl;
    }
}

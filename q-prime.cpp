// Q-prime aka 1 số có 4 ước thì là đúng

#include <stdio.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
bool check(int n)
{
    int d = 2; // Mỗi số có ít nhất là 2 ước : 1 và chính nó
    for (int i = 2; i <= n / 2; i++)
    { // Giảm thiểu bước nhảy, tự suy luận đi bạn :(
        if (n % i == 0)
            d++;
    }
    return d == 4;
}
int main()
{
    int n, t = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            t = 1;
            cout << i << endl;
        }
    }
    if (t == 0)
    {
        cout << "No";
    }

    return 0;
}

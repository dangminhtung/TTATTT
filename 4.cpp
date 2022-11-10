#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int check(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a, b;
    printf("nhap a:");
    scanf("%d", &a);
    cout << "nhap b:";
    cin >> b;
    cout << "(";
    for (a; a < b; a++)
    {
        if (check(a) == 1)
        {
            cout << a << " ";
        }
    }
    cout << ")";
}
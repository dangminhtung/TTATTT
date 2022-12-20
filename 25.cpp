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
    int n, m, j = 0;
    cout << "nhap n, m: ";
    cin >> n >> m;
    int a[100] = {0};
    int count = 0;
    int sum = 0;
    // cài mảng bằng các số nguyên tố
    for (int i = 2; i < n; i++)
    {
        if (check(i))
        {
            a[j] = i;
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        sum = 0;
        count = 0;
        for (int h = i; h < j; h++)
        {
            sum += a[h];
            count++;

            if (count == m)
            {
                if (sum == n)
                {
                    cout << h << " ";
                    cout << "cac so do la: ";
                    for (int k = i; k <= h; k++)
                    {
                        cout << a[k] << " ";
                    }
                }
                break;
            }
        }
    }
}
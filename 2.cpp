
#include <math.h>
#include <iostream>
using namespace std;

void sangNT_NguyenThuy(int arr[10000], int n)
{

    int i, j;
    for (i = 2; i < n; i++)
        arr[i] = 1;
    arr[0] = arr[1] = 0;
    j = 2;
    while (2 * j < n)
    {
        arr[2 * j]--;
        j++;
    }
    j = 3;
    while (3 * j < n)
    {
        arr[3 * j]--;
        j += 2;
    }
    for (i = 5; i < sqrt(n); i = i + 6)
    {
        if (arr[i] == 1)
        {
            j = 5;
            while (i * j < n)
            {
                arr[i * j]--;
                arr[i * (j + 2)]--;
                j += 6;
            }
        }
        if (arr[i + 2] == 1)
        {
            j = 5;
            while ((i + 2) * j < n)
            {
                arr[(i + 2) * j]--;
                arr[(i + 2) * (j + 2)]--;
                j += 6;
            }
        }
    }
}

int main()
{
    int arr[10000];
    long long int n;
    cin >> n;
    long long int s, e;
    s = pow(10, n - 1);
    e = pow(10, n) - 1;
    sangNT_NguyenThuy(arr, e);
    for (long long int i = s; i < e; i++)
    {
        if (arr[i] == 1)
        {
            cout << i << endl;
        }
    }
}

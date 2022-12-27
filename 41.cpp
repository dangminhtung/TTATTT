#include <iostream>
#include <math.h>
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
int power(int a, int k, int mod)
{
    if (k == 0)
        return 1;
    int temp = power(a, k / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (k % 2 == 1)
    {
        temp = (temp * a) % mod;
    }
    return temp;
}
int main()
{
    int a = -1, k = -1, n = -1, arr[10000];
    {
        cout << "nhap 0<a<1000: ";
        cin >> a;
    }
    while (k < 0 || n < 0 || k > n || k > 1000 || n > 1000)
    {
        cout << "nhap 0<k<n<1000: ";
        cin >> k >> n;
    }
    sangNT_NguyenThuy(arr, n);
    cout << power(a, k, n);
    if (arr[power(a, k, n)] == 1)
    {
        cout << " thoa man";
    }
    else
    {
        cout << " ko thoa man";
    }
}
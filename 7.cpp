#include <iostream>
#include <math.h>
using namespace std;

long long int reverse(long long int n)
{
    long long int temp = n;
    long long int rev = 0;
    while (temp > 0)
    {
        rev = (rev * 10) + temp % 10;
        temp /= 10;
    }

    return rev;
}
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
    long long int n;
    int arr[10000];
    cin >> n;
    sangNT_NguyenThuy(arr, n);
    for (long long int i = 1; i < n; i++)
    {
        long long int rev = reverse(i);
        if (arr[i] == 1 && arr[rev] == 1)
        {
            cout << i << endl;
        }
    }
}

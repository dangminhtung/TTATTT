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

int main()
{
    int n, m, j = 0, arr[10000];
    cout << "nhap n, m: ";
    cin >> n >> m;
    int a[100] = {0};
    int count = 0;
    int sum = 0;
    // cài mảng bằng các số nguyên tố
    sangNT_NguyenThuy(arr, n);
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == 1)
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
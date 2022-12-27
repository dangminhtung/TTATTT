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
int tinhF(int i)
{
    int arr[10000];
    sangNT_NguyenThuy(arr, 1000);
    if (arr[i] == 1)
    {
        return i;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int l, r, tong = 0;
    cout << "nhap L, R: ";
    cin >> l >> r;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            if (j > i)
            {
                cout << "F[" << i << "]"
                     << "*"
                     << "F[" << j << "]= " << tinhF(i) * tinhF(j) << endl;
                ;
                tong = tong + tinhF(i) * tinhF(j);
            }
        }
    }
    cout << "tong= " << tong;
}
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
    int a, b, arr[10000];
    int count = 0;
    int temp = 0;
    cout << "nhap a, b: ";
    cin >> a >> b;
    sangNT_NguyenThuy(arr, b);
    for (int i = a; i < b; i++)
    {

        count = 0;
        for (int j = 2; j < i; j++)
        {

            if (arr[j] == 1)
            {
                count++;
            }
        }
        if (arr[count] == 1)
        {
            cout << i << endl;
            temp++;
        }
    }
    cout << "co " << temp << " so sieu nguyen to";
}
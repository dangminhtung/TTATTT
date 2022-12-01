#include <iostream>
#include <math.h>
using namespace std;
int *tinhmang(int w, int t, int a)
{
    int j = 1;
    int *temp = new int[3]();
    for (int i = 3; i > -1; i--)
    {
        temp[i] = a / powf(2, (t - j) * w);
        a = a % (int)powf(2, (t - j) * w);
        j++;
    }
    return temp;
}
int main()
{
    int a, b;
    cout << "nhap a: ";
    cin >> a;
    cout << "nhap b ";
    cin >> b;
    int w = 8;
    int *tp1 = tinhmang(8, 4, a);
    int *tp2 = tinhmang(8, 4, b);
    // tinh tong
    int *sum = new int[3];
    int t = 0;
    for (int i = 0; i < 4; i++)
    {
        sum[i] = tp1[i] + tp2[i] + t;
        if (sum[i] >= 0 && sum[i] < (int)powf(2, 8))
        {
            t = 0;
        }
        else
        {
            t = 1;
        }
        sum[i] = sum[i] % (int)powf(2, w);
    }
    cout << "t= " << t << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << " " << sum[i];
    }
}

#include <iostream>
#include <math.h>
using namespace std;
int *tinhmang(int w, int t, int a)
{
    int *temp = new int[3]();
    int surplus;
    for (int i = 3; i > -1; i--)
    {
        if (i == 3)
        {
            temp[3] = a / (powf(2, (t - 1) * w));
            surplus = a % (int)(powf(2, (t - 1) * w));
        }
        else if (i == 2)
        {
            temp[2] = surplus / powf(2, 2 * w);
            surplus = surplus % (int)powf(2, 2 * w);
        }
        else if (i == 1)
        {
            temp[1] = surplus / powf(2, w);
            surplus = surplus % (int)powf(2, w);
        }
        else
        {
            temp[0] = surplus;
        }
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
        if (sum[i] > (int)powf(2, w))
        {
            sum[i] = sum[i] % (int)powf(2, w);
        }
    }
    cout << "t= " << t << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << " " << sum[i];
    }
}

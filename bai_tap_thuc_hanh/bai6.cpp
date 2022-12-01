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
int *phepnhan(int *a, int *b)
{
    int uv, u, v;
    int *c = new int[8]{};

    for (int i = 0; i < 4; i++)
    {
        u = 0;
        for (int j = 0; j < 4; j++)
        {
            uv = c[i + j] + a[i] * b[j] + u;
            u = uv / 256;
            v = uv % 256;
            c[i + j] = v;
        }
        c[i + 4] = u;
    }
    return c;
}
int main()
{
    // int a;
    // cout << "nhap a: ";
    // cin >> a;
    // int b;
    // cout<<"nhap b:";cin>>b;
    int *tp1 = tinhmang(8, 4, 524647);
    int *tp2 = tinhmang(8, 4, 32549);
    for (int i = 3; i > -1; i--)
    {
        cout << " " << tp1[i];
    }
    cout << endl;
    for (int i = 3; i > -1; i--)
    {
        cout << " " << tp2[i];
    }
    int *c = phepnhan(tp1, tp2);
    cout << endl;
    for (int i = 7; i > -1; i--)
    {
        cout << " " << c[i];
    }
}
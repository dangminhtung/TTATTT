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
    int a;
    cout << "nhap a: ";
    cin >> a;
    int *tp1 = tinhmang(8, 4, a);
    for (int i = 3; i > -1; i--)
    {
        cout << " " << tp1[i];
    }
}
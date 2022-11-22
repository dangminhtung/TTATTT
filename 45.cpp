#include <iostream>
#include <math.h>
using namespace std;

int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int r = power(x, y / 2, mod) % mod;
    r = (r * r) % mod;
    if (y % 2 == 1)
    {
        r = (r * x) % mod;
    }
    return r;
}
int check_miller_rabin(int n, int y, int s)
{
    if (y != 1 && y != n - 1)
    {
        int j = 1;
        while (j < s && y != n - 1)
        {
            y = (y * y) % n;
            if (y == 1)
                return 0;
            j += 1;
        }
        if (y != n - 1)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    srand((int)time(0));
    int tp[n] = {-1};
    for (int i = 0; i < n; i++)
    {

        while (1)
        {
            tp[i] = -1;
            while (tp[i] < 2 || tp[i] % 2 == 0)
            {
                tp[i] = 1 + rand();
            }
            cout << tp[i] << endl;
            int s;
            int r = tp[i] - 1;
            while (r > 0)
            {
                if (r % 2 == 1)
                {
                    break;
                }
                if (r % 2 == 0)
                {
                    s++;
                    r /= 2;
                }
            }
            int a = 2 + rand() % tp[i] - 2;
            int y = power(a, r, tp[i]);
            if (check_miller_rabin(tp[i], y, s) == 1)
                break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << " " << tp[i];
    }
    int min = abs(tp[0] - tp[1]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            min = (min > abs(tp[j] - tp[i])) ? abs(tp[j] - tp[i]) : min;
        }
    }
    cout << endl;
    cout << "gia tri nho nhat: " << min;
}
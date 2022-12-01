#include <iostream>
using namespace std;
int euclidExtend(int phi, int e)
{
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    int x, y, r, q;
    while (e > 0)
    {
        q = phi / e;
        r = phi % e;
        x = x2 - x1 * q;
        y = y2 - y1 * q;
        phi = e;
        e = r;
        x2 = x1;
        y2 = y1;
        x1 = x;
        y2 = y;
    }
    return y2;
}
int main()
{
    int test = euclidExtend(489573857, 45682375);
    if (test < 0)
        test = test + 489573857;
    cout << test;
}
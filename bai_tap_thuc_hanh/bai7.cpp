#include <iostream>
using namespace std;
int ucln(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    else
    {
        while (a != b)
        {
            if (a < b)
                b = b - a;
            else
                a = a - b;
        }
    }
    return a;
}
int main()
{
    int result = ucln(10507620, 10507620);
    cout << result;
}

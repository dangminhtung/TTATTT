#include <iostream>
#include <math.h>
using namespace std;

int check(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a, b;
    int count = 0;
    int temp = 0;
    cout << "nhap a, b: ";
    cin >> a >> b;
    for (int i = a; i < b; i++)
    {
        if (check(i))
        {
            count = 0;
            for (int j = 2; j < i; j++)
            {

                if (check(j))
                {
                    count++;
                }
            }
            if (check(count))
            {
                cout << i << endl;
                temp++;
            }
        }
    }
    cout << "co " << temp << " so sieu nguyen to";
}
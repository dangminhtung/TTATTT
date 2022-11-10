#include <iostream>
#include <math.h>
using namespace std;

int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
    {
        temp = (temp * x) % mod;
    }
    return temp;
}
int main()
{
    int n;
    int check;
    cout << "nhap so muon kiem tra: ";
    cin >> n;
    cout << "so la muon lap :" << endl;
    cin >> check;
    int a;
    for (int i = 0; i < check; i++)
    {
        cout << "--------lan " << i + 1 << endl;
        // cho chạy random từ [1, n)
        a = 1 + rand() % n - 1;
        cout << "chon ngau nhien a la: " << a << endl;
        int temp = power(a, n - 1, n);
        if (temp == 1)
        {
            // nếu (a^n-1)mod n=1 thì n khả năng là 1 số nguyên tố
            // nếu kết quả khác 1 thì n chắc chắn là 1 hợp số
            cout << "voi a= " << a << " thi " << n << " la so nguyen to" << endl;
        }
        else
        {
            cout << n << " la hop so" << endl
                 << "ket thuc random";
            break;
        }
    }
}

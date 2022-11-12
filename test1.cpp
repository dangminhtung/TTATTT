#include <iostream>
#include <math.h>
#include <cstring>
// chuỗi p là gốc còn biến xét theo chuỗi T
using namespace std;
int main()
{

    char t[1000], p[1000];
    int l[1000];
    cout << "nhap chuoi T: ";
    cin >> t;
    cout << "nhap chuoi P: ";
    cin >> p;
    for (int i = 0; i <= 127; i++)
    {
        l[i] = -1;
    }
    // các giá trị assci là chỉ số còn giá trị mảng l tăng dần
    for (int i = 0; i < (int)strlen(p); i++)
    {
        l[(int)p[i]] = i;
    }
    int d = 0;
    int i = strlen(p) - 1,
        j = strlen(p) - 1;
    while (i < strlen(t))
    {
        d = 0;
        while (d < strlen(p))
        {
            if (p[j] == t[i])
            {
                i--;
                j--;
                d++;
            }
            else
            {
                // so sánh giá trị i đc xets với các phần tử của p thông qua mảng l
                int min;
                if (j > l[(int)t[i]])
                {
                    min = 1 + l[(int)t[i]];
                }
                // tịnh tiến giá trí i của mảng T để so sánh tiếp sao cho giá trị i trùng với giá trị j, mặc định giá trị j bằng chiều dài p, chỉ thay đổi i
                i = i + strlen(p) - min;
                break;
            }
        }

        if (d == strlen(p))
        {
            cout << "chuoi p co trong t bat dau tu vi tri: " << i + 2 << endl;
            return 0;
        }
    }
    cout << "khong xuat hien trong chuoi T";
}
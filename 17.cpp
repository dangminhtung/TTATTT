#include <iostream>
#include <math.h>
using namespace std;
bool check(int n)
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
	int n, a, b, c, tong;
	cout << "nhap n: ";
	cin >> n;
	cout << "nhap a, b, c:";
	cin >> a >> b >> c;
	for (int i = 1; i < n; i++)
	{
		tong = a * i * i + b * i + c;
		if (check(tong))
		{
			cout << "so nguyen  x la: " << i;
			break;
		}
	}
}
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
int power(int x, int y, int mod)
{
	// thuật toán nhân bình  phương
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
	int tren = 0, duoi = 0;
	int n, a;

	cout << "nhap N: ";
	cin >> n;
	cout << "nhap a: ";
	cin >> a;
	int temp1 = n;
	int temp2 = n;
	if (check(n))
	{
		cout << "true";
	}
	else
	{

		while (1)
		{
			temp1++;
			tren++;
			if (check(temp1))
				break;
		}
		while (1)
		{
			temp2--;
			duoi++;
			if (check(temp2))
				break;
		}
		if (tren == duoi)
		{
			n = (temp1 > temp2) ? temp2 : temp1;
			cout << n;
		}
		else if (tren > duoi)
		{
			n = temp2;
			cout << "so nguyen to lay la: " << n << endl;
		}
		else
		{
			n = temp1;
			cout << "so nguyen to lay: " << n << endl;
		}
	}
	int ketqua = power(a, n, 1234);
	cout << "ket qua:" << ketqua;
}

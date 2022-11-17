#include <iostream>
#include <math.h>
using namespace std;
bool check(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
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
	cout << "nhap N: ";
	cin >> n;
	while (n < 0 || n > 1000)
	{
		cout << "sau dk , nhap lai: ";
		cin >> n;
	}

	int p = -1;
	while (1)
	{
		if (check(p))
		{
			break;
		}
		else
			p = 2 + rand() % 99;
	}
	cout << "chon p: " << p << endl;
	cout << "a lan luot la: ";
	for (int i = 1; i < n; i++)
	{
		if (check(power(i, p, n)))
		{
			cout << " " << i;
		}
	}
}
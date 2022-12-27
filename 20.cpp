#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return a + b;
	}
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
}
int main()
{

	int m, n, d, uoc;
	cout << "nhap m, n: ";
	cin >> m >> n;

	while (m < 0 || n < 0 || m > 1000 || n > 1000)
	{
		cout << "Loi nhap lai!";
		cout << "nhap m, n: ";
		cin >> m >> n;
	}
	cout << "nhap d: ";
	cin >> d;

	while (d < 0 || d > 1000)
	{
		cout << "loi nhap lai!";
		cout << "nhap d: ";
		cin >> d;
	}
	for (int i = m; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			uoc = gcd(i, j);
			if (uoc == d)
			{
				cout << "cap so do la: " << i << " " << j << endl;
			}
		}
	}
}
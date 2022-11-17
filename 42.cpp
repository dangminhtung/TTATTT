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
	int p = -1, q = -1;
	while (1)
	{
		if (check(p))
			break;
		else
			p = 2 + rand() % 999;
	}
	while (1)
	{
		if (check(q))
			break;
		else
			q = 2 + rand() % 999;
	}
	cout << "chon p random: " << p << endl;
	cout << "chon q random: " << q << endl;
	cout << "so a Lan Luot : ";
	for (int a = 1; a < 100; a++)
	{
		int temp = power(a, p, q);
		if (check(temp))
		{
			cout << " " << a;
		}
	}
}
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
	int uoc = 0;
	int uocnt = 0;
	int n;
	cout << "nhap N: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			uoc++;
			if (check(i))
			{
				uocnt++;
			}
		}
	}
	cout << "so luong uoc: " << uoc << endl;
	cout << "so luong uoc NT: " << uocnt;
}
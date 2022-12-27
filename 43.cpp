#include <iostream>
#include <math.h>
using namespace std;
void sangNT_NguyenThuy(int arr[10000], int n)
{

	int i, j;
	for (i = 2; i < n; i++)
		arr[i] = 1;
	arr[0] = arr[1] = 0;
	j = 2;
	while (2 * j < n)
	{
		arr[2 * j]--;
		j++;
	}
	j = 3;
	while (3 * j < n)
	{
		arr[3 * j]--;
		j += 2;
	}
	for (i = 5; i < sqrt(n); i = i + 6)
	{
		if (arr[i] == 1)
		{
			j = 5;
			while (i * j < n)
			{
				arr[i * j]--;
				arr[i * (j + 2)]--;
				j += 6;
			}
		}
		if (arr[i + 2] == 1)
		{
			j = 5;
			while ((i + 2) * j < n)
			{
				arr[(i + 2) * j]--;
				arr[(i + 2) * (j + 2)]--;
				j += 6;
			}
		}
	}
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
	int n, arr[10000];
	cout << "nhap N: ";
	cin >> n;
	sangNT_NguyenThuy(arr, n);
	while (n < 0 || n > 1000)
	{
		cout << "sau dk , nhap lai: ";
		cin >> n;
	}

	int p = -1;
	while (1)
	{
		if (arr[p] == 1)
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
		if (arr[power(i, p, n)] == 1)
		{
			cout << " " << i;
		}
	}
}
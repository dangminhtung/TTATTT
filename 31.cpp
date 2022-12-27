#include <iostream>
#include <math.h>
using namespace std;

void check(int arr[10000], int n)
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
	int n, a, arr[10000];

	cout << "nhap N: ";
	cin >> n;
	cout << "nhap a: ";
	cin >> a;
	int temp1 = n;
	int temp2 = n;
	check(arr, n);
	if (arr[n] == 1)
	{
		cout << "true" << endl;
	}
	else
	{

		while (1)
		{
			temp1++;
			tren++;
			if (arr[temp1])
				break;
		}
		while (1)
		{
			temp2--;
			duoi++;
			if (arr[temp2])
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
	int ketqua = power(a, n, 123456);
	cout << "ket qua:" << ketqua;
}

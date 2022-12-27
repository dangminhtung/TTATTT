#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
	int tmp;
	if (b > a)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b > 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

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
int main()
{
	int a, b, arr[10000];
	do
	{
		printf("nhap vao so a : ");
		scanf("%d", &a);
		printf("nhap vao so b :");
		scanf("%d", &b);
	} while (a < 0 || b > 1000);
	int d;
	int dem = 0;
	int i, j, k;
	sangNT_NguyenThuy(arr, b);
	for (i = a; i < b; i++)
	{
		for (j = a; j < b; j++)
		{
			d = gcd(i, j);
			if (arr[d] == 1)
			{
				printf("[%d %d] %d \n", i, j, d);
			}
		}
	}
}

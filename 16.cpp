#include <stdio.h>
#include <math.h>
#include <iostream>
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
	int check, n, i, j, ra, arr[10000];

	printf("Nhap so n");
	scanf("%d", &n);
	sangNT_NguyenThuy(arr, n);
	for (j = 0; j < n; j++)
	{
		check = 1;
		ra = rand();
		printf("%d", ra);
		// for (i = 2; i < sqrt(ra); i++)
		// {
		// 	if (ra % i == 0)
		// 		check = 0;
		// }
		if (arr[ra] == 1)
			printf(" Day la so nguyen to\n");
		else
			printf(" Day khong phai la so nguyen to\n");
	}
}

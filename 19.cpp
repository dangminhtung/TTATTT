#include <stdio.h>
#include <math.h>
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
	int check, m, l, i, j, ra, x, A, B, C, check2, arr[10000];

	check2 = 0;

	printf("Nhap so m: ");
	scanf("%d", &m);
	printf("Nhap so l>m nhe: ");
	scanf("%d", &l);
	printf("Nhap A: ");
	scanf("%d", &A);
	printf("Nhap B: ");
	scanf("%d", &B);
	printf("Nhap C: ");
	scanf("%d", &C);
	sangNT_NguyenThuy(arr, l);
	for (x = m; x <= l; x++)
	{
		check = 1;
		ra = A * x * x + B * x + C;

		if (arr[ra] == 1)
		{
			printf("%d la so nguyen to cua tong A.x^2+B.x+C=%d\n", x, ra);
			check2 = 1;
		}
	}
	if ((check2 == 0) && ((x - 1) == l))
		printf("Khong co gia tri thoa man");
}

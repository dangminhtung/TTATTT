#include <stdio.h>
#include <math.h>
int main()
{
	int check, m, l, i, j, ra, x, A, B, C, check2;

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
	for (x = m; x <= l; x++)
	{
		check = 1;
		ra = A * x * x + B * x + C;
		for (i = 2; i < sqrt(ra); i++)
		{
			if (ra % i == 0)
				check = 0;
		}
		if (check == 1)
		{
			printf("%d la so nguyen to cua tong A.x^2+B.x+C=%d\n", x, ra);
			check2 = 1;
		}
	}
	if ((check2 == 0) && ((x - 1) == l))
		printf("Khong co gia tri thoa man");
}

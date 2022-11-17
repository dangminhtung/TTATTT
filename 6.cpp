#include <stdio.h>
int main()
{
	int N, p, q, i, dem, j;
	printf("Nhap so N duong ");
	scanf("%d", &dem);

	for (j = 2; j < dem; j++)
	{
		p = q = 0;
		N = j;
		// tìm ước chung của n trước , rồi từ tìm ước của  ước chung  của n xem dó bằng n ko

		for (i = 1; i < N; i++)
		{
			if (N % i == 0)
			{
				p = p + i;
			}
		}

		for (i = 1; i < p; i++)
		{
			if (p % i == 0)
			{
				q = q + i;
			}
		}

		if (q == N && p != q)
			printf("Cap so do la: %d  %d\n", N, p);
	}
}

#include <stdio.h>
#include <math.h>
// Co the tim lap phuong truoc roi check nguoc lai su nguyen to
// ĐMT: nên thêm 1 hàm check số nguyên tố để làm nhanh hơn
int reverse(int n)
{
	int reNum = n % 10;
	n /= 10;
	int last;
	while (n > 0)
	{
		last = n % 10;
		n /= 10;
		reNum = reNum * 10 + last;
	}
	return reNum;
}
int main()
{
	int i;
	for (i = 100; i < 1000; i++)
	{
		int res = 0;
		int tmp;
		int count = 0;
		for (int j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count == 0)
		{
			int daoNguoc = reverse(i);
			for (int z = 1; z <= sqrt(daoNguoc); z++)
			{
				if (z * z * z == daoNguoc)
				{
					// printf("Vay so can tim la %d va lap phuong cua no la: %d", i, daoNguoc);
					printf("%d", i);
				}
			}
		}
	}
}

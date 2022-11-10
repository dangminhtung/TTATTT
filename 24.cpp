#include <iostream>
#include <math.h>

using namespace std;
bool check(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i < sqrt(n); i++)
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
	int a, b;
	cout << "nhap a, b: ";
	cin >> a >> b;
	int sb = sqrt(b);
	int s1[b], s2[b];
	for (int i = 1; i <= sb; i++)
	{
		s1[i] = i * i;
		s2[i] = i * i;
	}
	for (int i = a; i <= b; i++)
	{
		if (check(i))
		{
			for (int j = 1; j <= sb; j++)
			{
				for (int h = j; h <= sb; h++)
				{
					if (s1[j] + s2[h] == i)
					{
						cout << "cap so do la: " << s1[j] << " + " << s2[h] << "= " << i << endl;
					}
				}
			}
		}
	}
}
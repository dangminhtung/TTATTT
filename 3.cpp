
#include <stdio.h>
#include <math.h>
int check(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int s = 0, p = 0;
    int k = 0, q = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            p = p + i;
            s++;
            if (check(i) == 1)
            {
                q = q + i;
                k++;
            }
        }
    }
    int tong = n + p + s - q - k;
    printf("%d", tong);
}
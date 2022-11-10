Q - prime aka 1 số có 4 ước thì là đúng

#include <stdio.h>
#include <stdbool.h>
    bool
    check(int n)
{
    int d = 2; // Mỗi số có ít nhất là 2 ước : 1 và chính nó
    for (int i = 2; i <= n / 2; i++)
    { // Giảm thiểu bước nhảy, tự suy luận đi bạn :(
        if (n % i == 0)
            d++;
    }
    return d == 3;
}
int main()
{
    int n;
    int d;
    do
    {
        printf("Enter the N: ");
        scanf("%d", &n);
    } while (n < 0);
    for (int i = 0; i <= n; i++)
    {
        if (check(i))
            printf("%d is T-Prime.\n", i);
    }
    return 0;
}

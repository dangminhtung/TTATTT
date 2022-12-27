#include <stdio.h>
#include <stdlib.h>
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
    int i, A, B;
    int sum = 0;
    int arr[10000];
    scanf("%d", &A);
    scanf("%d", &B);
    sangNT_NguyenThuy(arr, B);
    for (i = A; i <= B; i++)
    {
        if ((arr[i] == 1) && (i != 1))
        {
            printf("%d\t", i);
            sum += i;
        }
        else
            sum = sum;
    }
    printf("\n");
    printf("Sum = %d", sum);
    printf("\n");
    if (arr[sum] == 1)
        printf("YES"); // YES neu 'Sum' la so nguyen to
    else
        printf("NO"); // No neu 'Sum' khong la so nguyen to
}
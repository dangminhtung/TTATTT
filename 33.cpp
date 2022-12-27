#include <stdio.h>
#include <malloc.h>
struct stack
{
    int s[30];
    int top;
};
typedef struct stack STACK;
void resetStack(STACK *t, int n)
{
    for (int i = 0; i <= n; i++)
        t->s[i] = 0;
    t->top = -1;
}
STACK *capPhatStack(int top)
{
    STACK *t = (STACK *)malloc(sizeof(STACK));
    resetStack(t, top);
}
void chiaDaThuc(STACK *a, STACK *b, STACK *q)
{
    resetStack(q, a->top);
    q->top = a->top - b->top;

    while (a->top >= b->top)
    {
        int k = a->top - b->top;
        q->s[k]++;
        for (int i = 0; i <= b->top; i++)
        {

            if (b->s[i] == 1)
            {
                if (a->s[i + k] == 1)
                    a->s[i + k]--;
                else
                    a->s[i + k]++;
            }
        }
        a->top--;
        while (a->top >= 0 && a->s[a->top] == 0)
            a->top--;
    }
}
STACK *nhanDaThuc(STACK *q, STACK *x, int n)
{
    STACK *t = capPhatStack(n);
    if (q->top == -1 || x->top == -1)
        return t;
    t->top = q->top + x->top;
    for (int i = 0; i <= q->top; i++)
    {
        if (q->s[i] == 1)
            for (int j = 0; j <= x->top; j++)
            {
                if (x->s[j] == 1)
                {
                    if (t->s[i + j] == 1)
                        t->s[i + j]--;
                    else
                        t->s[i + j]++;
                }
            }
    }
    return t;
}
STACK *truDaThuc(STACK *a, STACK *b, int n)
{
    STACK *x = capPhatStack(n);
    int k = a->top, i;
    if (k > b->top)
        k = b->top;
    for (i = 0; i <= k; i++)
    {

        if (a->s[i] + b->s[i] == 1)
        {
            x->top = i;
            x->s[i] = 1;
        }
    }
    while (i <= a->top)
    {
        if (a->s[i] == 1)
        {
            x->top = i;
            x->s[i] = 1;
        }
        i++;
    }
    while (i <= b->top)
    {
        if (b->s[i] == 1)
        {
            x->top = i;
            x->s[i] = 1;
        }
        i++;
    }
    return x;
}
STACK *euclideMR(STACK *a, STACK *b)
{
    STACK *y = capPhatStack(a->top);
    if (b->top == -1)
        return y;
    STACK *x = capPhatStack(a->top);
    STACK *x2 = capPhatStack(a->top);
    STACK *x1 = capPhatStack(a->top);
    STACK *y2 = capPhatStack(a->top);
    STACK *y1 = capPhatStack(a->top);
    STACK *q = capPhatStack(a->top);
    x2->top++;
    x2->s[0] = 1;
    y1->top++;
    y1->s[0] = 1;
    while (b->top > -1)
    {

        chiaDaThuc(a, b, q);
        STACK *tmp = a;
        a = b;
        b = tmp;
        x = truDaThuc(x2, nhanDaThuc(q, x1, 30), 30);
        y = truDaThuc(y2, nhanDaThuc(q, y1, 30), 30);
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        for (int k = b->top; k >= 0; k--)
            printf("%d ", b->s[k]);
        printf("\n");
    }
    return y2;
}
void inPut(STACK *x, STACK *f)
{
    printf("Nhap da thuc theo dang sau: \nVIDU: x^5+x^3+x^2+1 thi nhap 1 0 1 1 0 1\n");
    printf("Da thuc g bac may? ");
    int m;
    scanf("%d", &m);
    printf("Nhap da thuc g: ");
    for (int i = m; i >= 0; i--)
        scanf("%d", &x->s[i]);
    x->top = m;
    printf("Da thuc a bac may? ");
    scanf("%d", &m);
    printf("Nhap da thuc a: ");
    for (int i = m; i >= 0; i--)
        scanf("%d", &f->s[i]);
    f->top = m;
}
int main()
{
    STACK *y = (STACK *)malloc(sizeof(STACK));
    STACK *x = (STACK *)malloc(sizeof(STACK));
    STACK *f = (STACK *)malloc(sizeof(STACK));
    inPut(x, f);
    y = euclideMR(x, f);
    for (int i = y->top; i >= 0; i--)
        printf("%d ", y->s[i]);
}

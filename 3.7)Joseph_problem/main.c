#include <stdio.h>

int joseph(int n, int m, int c);

int main()
{
    int n, m;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);
    printf("The first number departed is %d\n", joseph(n, m, 1));
    printf("The second number departed is %d\n", joseph(n, m, 2));
    printf("The last one to leave is %d\n", joseph(n, m, 3));
    return 0;
}

int joseph (int n, int m, int c)
{
    int out = 0;
    for (int i = 1; i <= n; i++)
    {
        out = (out + m) % i;
        if (c == 1 && i == n - 2)
            return out + 1;
        else if (c == 2 && i == n - 1)
            return out + 1;
    }
    return out + 1;
}
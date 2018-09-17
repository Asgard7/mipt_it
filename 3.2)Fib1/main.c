#include <stdio.h>

int main()
{
    int n, F;
    printf("Enter n: ");
    scanf("%d", &n);
    int f1 = 1, f2 = 1;
    if(n == 1 || n == 2)
        printf("%d", f1);
    else
    {
        for (int i = 2; i < n; i++)
        {
            F = f1 + f2;
            f2 = f1;
            f1 = F;
        }
        printf("Fib[%d] = %d", n, F);
    }
    return 0;
}
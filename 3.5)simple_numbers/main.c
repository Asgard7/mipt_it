#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if(n == 1)
    {
        printf("1 not composite and not simple");
        return 0;
    }
    for (int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            printf("%d is composite number", n);
            return 0;
        }
    }
    printf("%d is simple number", n);
    return 0;
}
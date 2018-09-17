#include <stdio.h>
#include <malloc.h>

int main()
{
    int n, temp = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * n);
    printf("Enter %d numbers:", n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &A[j]);
    }
    for (int i = 0; i < n; i++)
    {
        if(A[i] >= temp)
            temp = A[i];
    }
    printf("%d", temp);
    return 0;
}
#include <stdio.h>
#include <stddef.h>
#include <malloc.h>

int **dynamic_array_alloc(size_t n);
void dynamic_array_free(int** A, size_t n);
void print_array(int **A, size_t n);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int** Cnk = dynamic_array_alloc(n);
    for (int k = 0; k <= n; k++)
        Cnk[k][k] = 1;
    for (int m = 0; m <=n ; m++)
        Cnk[0][m] = 1;
    for (int j = 1; j <= n; j++)
        for (int l = 1; l <= j; l++)
            if(l == j)
                Cnk[l][j] = 1;
            else
                Cnk[l][j] = Cnk[l][j - 1] + Cnk[l - 1][j - 1];
    print_array(Cnk, n);
    dynamic_array_free(Cnk, n);
    return 0;
}

int **dynamic_array_alloc(size_t n)
{
    int** A = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++)
    {
        A[i] = (int*)malloc((n + 1) * sizeof(int*));
    }
    return A;
}

void dynamic_array_free(int **A, size_t n)
{
    for (int i = 0; i <= n; i++)
    {
        free(A[i]);
    }
    free(A);
}

void print_array(int **A, size_t n)
{
    for (int i1 = 0; i1 <= n; i1++)
    {
        printf("C[%d][%d] = %d\n", i1, n, A[i1][n]);
    }
}
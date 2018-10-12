#include <stdio.h>

typedef struct section{
    int x1;
    int x2;
}Section;

void get_struct(Section *A, int k);

int main()
{
    int n, max = 0, X2, s, X3 = 0;
    printf("Enter number of section: ");
    scanf("%d", &n);
    Section A[n];
    int D[n], N[n], P[n];
    get_struct(A, n);
    for (int i = 0; i < n; i++)
    {
        D[i] = A[i].x2 - A[i].x1;
    }
    for (int m = 0; m < n; m++)
    {
        P[m] = 1;
    }
    for (int l = 0; l < n; l++)
    {
        if(A[l].x1 == 0 && D[l] > max)
        {
            max = D[l];
            N[0] = l;
            X2 = A[l].x2;
            P[l] = 0;
        }
    }
    for (int j = 1; j < n; j++)
    {
        max = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i].x1 == X2 && D[i] >= max && P[i] != 0)
            {
                max = D[i];
                N[j] = i;
                P[i] = 0;
                X3 = A[i].x2;
                if(A[i].x2 == 1000)
                {
                    s = j;
                    j = n;
                    i = n;
                }
            }
        }
        X2 = X3;
    }
    for (int k = 0; k <= s; k++)
    {
        printf("%d\n", N[k]);
    }
    return 0;
}

void get_struct(Section *A, int k)
{
    printf("Enter x1 and x2 by space: ");
    for (int i = 0; i < k; i++)
        scanf("%d %d", &A[i].x1, &A[i].x2);
}

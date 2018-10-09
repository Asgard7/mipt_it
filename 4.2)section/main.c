#include <stdio.h>

typedef struct section{
    int x1;
    int x2;
}Section;

void get_struct(Section *A, int k);

int main()
{
    int n;
    printf("Enter number of section: ");
    scanf("%d", &n);
    Section A[n];
    Section B[n];
    get_struct(A, n);
    for (int i = 0; i < n; i++)
    {

    }
    return 0;
}

void get_struct(Section *A, int k)
{
    printf("Enter x1 and x2 by space: ");
    for (int i = 0; i < k; i++)
        scanf("%d %d", &A[i].x1, &A[i].x2);
}

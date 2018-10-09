#include <stdio.h>
#include <math.h>

typedef struct point { //структура представляющая точку с координатами (x, y)
    double x;
    double y;
}Point;

double mod(double a);
double mod_vector(double x, double y);

void get_struct(Point *A, int n);
void sort(int n, double *B[n][n], int x1, int x2);

int main()
{
    int n, jmin, i = 0;
    const int INF = 1000000;
    double min, s = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    Point A[n];
    get_struct(A, n);
    double B[n][n];
    double C[2][n];
    for (int l = 0; l < n; l++)
        C[0][l] = l;
    for (int f = 0; f < n; f++)
        for (int j = 0; j < n; j++)
            B[f][j] = mod_vector((A[f].x - A[j].x), (A[f].y - A[j].y));
    for (int k = 0; k < n; k++)
    {
        sort(n, B, k, k + n);
        C[1][k] =
    }
    return 0;
}

double mod(double a) //функция для расчета модуля числа
{
    if(a < 0)
        a = -a;
    return a;
}

double mod_vector(double x, double y)
{
    return sqrt(mod(x * x) + mod(y * y));
}

void get_struct(Point *A, int n) //функция для получения координат точки
{
    printf("Enter coordinates other points(in pairs in space, e.g 1 1 2 2 3 3 4 4): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &A[i].x, &A[i].y);
    }
}

void sort(int n, double B[n][n], int x1, int x2) //сортирует в пределах от x1 до x2
{
    for(int k = x1 ; k < x2 - 1; k++)
    {
        for(int j = 0 ; j < n - k - 1 ; j++) {
            if(B[k][j] > B[k][j + 1])
            {
                double tmp = B[k][j]; // сортируем расстояния между точками по возрастанию
                B[k][j] = B[k][j + 1] ;
                B[k][j + 1] = tmp;
            }
        }
    }
}
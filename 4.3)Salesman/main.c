#include <stdio.h>
#include <math.h>

typedef struct point { //структура представляющая точку с координатами (x, y)
    double x;
    double y;
}Point;

double mod(double a);
double mod_vector(double x, double y);

void get_struct(Point *A, int n);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    Point A[n];
    get_struct(A, n);
    double B[2][n];
    for (int j = 0; j < n; j++)
    {
        B[0][j] = j;
    }
    for (int i = 1; i < n; i++)
    {
        double x = (A[i].x - A[0].x);
        double y = (A[i].y - A[0].y);
        B[1][i] = mod_vector(x, y);
    }
    B[1][0] = 0;
    B[1][n - 1] = 0;
    printf("You enter:\n");
    printf("Start point - %f:%f, End point - %f:%f\n", A[0].x, A[0].y, A[n].x, A[n].y);
    for (int l = 1; l < n - 1; l++)
    {
        printf("point %d - %f:%f\n", l, A[l].x, A[l].y);
    }
    for(int k = 0 ; k < n - 1; k++)
    {
        for(int j = 0 ; j < n - k - 1 ; j++) {
            if(B[1][j] > B[1][j + 1])
            {
                double tmp = B[1][j]; // сортируем расстояния между точками по возрастанию
                B[1][j] = B[1][j + 1] ;
                B[1][j + 1] = tmp;
                double tmp1 = B[0][j]; // сдвигаем изначальные индексы расстояний вместе с расстояниями
                B[0][j] = B[0][j + 1];
                B[0][j + 1] = tmp1;
            }
        }
    }
    //только для дебага
    /*for (int l = 0; l < n; l++)
    {
        printf("%f - %f\n", B[0][l], B[1][l]);
    }*/
    printf("Marshrut: \n");
    for (int m = 2; m < n; m++)
    {
        printf("point %.0f -> ", B[0][m]);
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
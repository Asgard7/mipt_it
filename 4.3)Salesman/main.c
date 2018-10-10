#include<stdio.h>
#include<math.h>

typedef struct point { //структура представляющая точку с координатами (x, y)
    double x;
    double y;
}Point;

void get_struct(Point *A, int n);

double mod(double a);
double mod_vector(double x, double y);

int main()
{
    int i = 0, j, k, jmin, n;
    const int INF = 1000000;
    printf("Enter the number of points, without start and end point: ");
    scanf("%d", &n);
    double d[n + 2][n + 2];
    Point A[n + 2];
    get_struct(A, n + 2);
    printf("You enter:\n");
    printf("Start point - %f:%f, End point - %f:%f\n", A[0].x, A[0].y, A[n + 1].x, A[n + 1].y);
    for (int l = 1; l < n + 1; l++)
    {
        printf("point %d - %f:%f\n", l, A[l].x, A[l].y);
    }
    for (i = 0; i < n + 2; i++)
        for (j = 0; j < n + 2; j++)
            d[i][j] = mod_vector((A[i].x - A[j].x), (A[i].y - A[j].y));
    int c[n + 1], p[n];
    for (i = 1; i <= n; i++)
        c[i] = 1;
    double min;
    i = 0;
    for (k = 0; k < n; k++)
    {
        min = INF;
        for (j = 1; j <= n; j++)
        {
            if ((c[j] == 1) && (d[i][j] < min))
            {
                jmin = j;
                min = d[i][j]; //находим наименьший эллемент
            }
        }
        i = jmin;
        p[k] = i; //записываем индекс наименьшего эллемента в массив
        c[i] = 0; //исключаем эллемент из дальнейших операций
    }
    printf("Way: start point ->");
    for (k = 0; k < n; k++)
        printf("%d ->", p[k]);
    printf("end point");
    return 0;
}

void get_struct(Point *A, int n) //функция для получения координат точки
{
    printf("Enter coordinates of points in pairs in space(!important: start point may be first, end point - last; in pairs in space): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &A[i].x, &A[i].y);
    }
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
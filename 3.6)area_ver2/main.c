//решение основано на формуле площади Гаусса
#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
}Point;

double mod(double a);

void get_struct(Point *rectangle); //функция для получения координат точки
void get_area(Point rectangle[4]);

int main()
{
    Point rectangle[4];
    get_struct(rectangle);
    get_area(rectangle);
    return 0;
}

double mod(double a) //функция для расчета модуля числа
{
    if(a < 0)
        a = -a;
    return a;
}

void get_struct(Point *rectangle)
{
    printf("Enter coordinates(in pairs in space, e.g 1 1 2 2 3 3 4 4): ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%lf %lf", &rectangle[i].x, &rectangle[i].y);
    }
}

void get_area(Point rectangle[4])
{
    double area = mod(rectangle[0].x * rectangle[1].y + rectangle[1].x * rectangle[2].y + rectangle[2].x * rectangle[0].y - rectangle[1].x * rectangle[0].y - rectangle[2].x * rectangle[1].y - rectangle[0].x * rectangle[2].y);
    printf("area = %f", area);
}
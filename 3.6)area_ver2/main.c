#include <stdio.h>
#include <math.h>

typedef struct point {
    int x;
    int y;
}Point;

int mod(int a);

void get_struct(Point *rectangle);

int main()
{
    Point rectangle[4];
    get_struct(rectangle);
    int a = mod(rectangle[0].x - rectangle[1].x);
    int b = mod(rectangle[0].y - rectangle[1].y);
    int a1 = mod(rectangle[1].x - rectangle[2].x);
    int b1 = mod(rectangle[1].y - rectangle[2].y);
    printf("area = %f", sqrt((a*a + b*b) * (a1*a1 + b1*b1)));
    return 0;
}

int mod(int a) //функция для расчета модуля числа
{
    if(a < 0)
        a = -a;
    return a;
}

void get_struct(Point *rectangle) //функция для получения координат точки
{
    printf("Enter coordinates(in pairs in space, e.g 1 1 2 2 3 3 4 4): ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &rectangle[i].x, &rectangle[i].y);
    }
}
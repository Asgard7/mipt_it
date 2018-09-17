#include <stdio.h>
#include <stdlib.h>

typedef struct point { //структура представляющая точку с координатами (x, y)
    int x;
    int y;
}Point;

int mod(int a);
int module_side_h(Point rectangle[4]);
int module_side_w(Point rectangle[4]);
int cmp_x(const void* a, const void* b);
int cmp_y(const void* a, const void* b);

void get_struct(Point *rectangle);
void calculate_area(Point rectangle[4]);
void sort_struct_x(Point *rectangle);
void sort_struct_y(Point *rectangle);


int main()
{
    Point rectangle[4];
    get_struct(rectangle);
    calculate_area(rectangle);
    return 0;
}


int mod(int a) //функция для расчета модуля числа
{
    if(a < 0)
        a = -a;
    return a;
}

int module_side_h(Point rectangle[4]) //функция для расчета одной стороны фигуры
{
    sort_struct_y(rectangle);
    return mod(rectangle[3].y - rectangle[0].y);
}

int module_side_w(Point rectangle[4]) //функция для расчета другой стороны фигуры
{
    return mod(rectangle[3].x - rectangle[0].x);
}

int cmp_x(const void* a, const void* b) //компаратор x
{
    return (((Point*)a)->x - ((Point*)b)->x);
}

int cmp_y(const void* a, const void* b) //компаратор y
{
    return (((Point*)a)->y - ((Point*)b)->y);
}

void get_struct(Point *rectangle) //функция для получения координат точки
{
    printf("Enter coordinates(in pairs in space, e.g 1 1 2 2 3 3 4 4): ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &rectangle[i].x, &rectangle[i].y);
    }
}

void calculate_area(Point rectangle[4]) //функция для расчета и вывода площади фигуры
{
    sort_struct_x(rectangle);
    int s1 = (mod(rectangle[1].x - rectangle[0].x) * mod(rectangle[1].y - rectangle[0].y));
    int s2 = (mod(rectangle[3].x - rectangle[1].x) * mod(rectangle[3].y - rectangle[1].y));
    printf("area of rectangle = %d", ((module_side_w(rectangle) * module_side_h(rectangle)) - (s1 + s2)));
}

void sort_struct_x(Point *rectangle) //функция для сортировки координат по x
{
    qsort(rectangle, 4, sizeof(rectangle[0]), cmp_x);
}

void sort_struct_y(Point *rectangle) //функция для сортировки координат по y
{
    qsort(rectangle, 4, sizeof(rectangle[0]), cmp_y);
}
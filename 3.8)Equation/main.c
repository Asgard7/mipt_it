#include <stdio.h>
#include <math.h>

const double pi = 3.145926;

double f(double x);
double mod(double a);
double make_interval(double *a, double *b);

int main(void)
{

    double a, b;
    printf("Enter an interval(separated by a space): ");
    scanf("%lf %lf", &a, &b);
    double *x = &a, *y = &b;
    make_interval(x, y);
    double c, eps = 1.0e-11;
    if(f(*x) * f(*y) <= 0)
    {
        while(mod(*y - *x) >= eps)
        {
            c = (*x + *y) / 2;
            if(f(*x) * f(c) <= 0)
                *y = c;
            else
                *x = c;
        }
        printf("root x = %.10f", c);
    }
    else
        printf("Error: an invalid interval (the function values at the end of the interval must be a different sign)");
    return 0;
}

double f(double x)
{
    return x*cos(x) - sin(x);
}

double mod(double a)
{
    if(a < 0)
        return (-a);
    else
        return a;
}

double make_interval(double *a, double *b)
{
    if(mod(*a) > mod(*b))
    {
        if(*a > 0)
            *b = *a - (pi/2 + pi);
        else
            *b = *a + (pi/2 + pi);
    }
    else
    {
        if(*b > 0)
            *a = *b - (pi/2 + pi);
        else
            *a = *b + (pi/2 + pi);
    }
}
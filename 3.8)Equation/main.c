#include <stdio.h>
#include <math.h>

double f(double x);

int main(void)
{
    double a, b;
    printf("Enter an interval(separated by a space): ");
    scanf("%lf %lf", &a, &b);
    double x, c, eps = 1.0e-11;
    if(f(a) * f(b) <= 0)
    {
        while((b - a) >= eps)
        {
            c = (a + b) / 2;
            if(f(a) * f(c) <= 0)
                b = c;
            else
                a = c;
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
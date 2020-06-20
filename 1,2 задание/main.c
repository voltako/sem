#include <math.h>
#include <stdio.h>
#define FCN_A_COST 1
#define IDEAL_INTEGRAL_VALUE 42

#define RECTANGLE 1
#define TRAPEZOIDAL 2
#define SIMPSON 3

#define  MAX_ITER 1000

double f1(double,double );
double freq(double);
double getIntegralValue(int method, double a, double start_x, double stop_x, int n);
double rectIntegral(double a, double start_x, double stop_x, int N);
double trapIntegral(double a, double start_x, double stop_x, int N);
double simpIntegral(double a, double start_x, double stop_x, int N);

void absDifferenceCompare(int, int, int, double, double );

int main()
{
    printf("Ideal integral value: 42\n");
    printf("Rect integral value: %lf\n", getIntegralValue(RECTANGLE, 1, 0, 2 * M_PI, MAX_ITER));
    printf("Trap integral value: %lf\n", getIntegralValue(TRAPEZOIDAL, 1, 0, 2 * M_PI, MAX_ITER));
    printf("Simp integral value: %lf\n", getIntegralValue(SIMPSON, 1, 0, 2 * M_PI, MAX_ITER));
    return 0;
}

double fcn(double a, double x)
{
    return sin(M_PI * (6 * pow(a, 2) + a * x - 2 * pow(x, 2)));
}

double getIntegralValue(int method, double a, double start_x, double stop_x, int n)
{
    double result = 0.0;

    switch (method) {
        case RECTANGLE:
            result = rectIntegral(a, start_x, stop_x, n);
            break;
        case TRAPEZOIDAL:
            result = trapIntegral(a, start_x, stop_x, n);
            break;
        case SIMPSON:
            result = simpIntegral(a, start_x, stop_x, n);
            break;
        default:
            break;
    }

    return result;
}

double rectIntegral(double a, double start_x, double stop_x, int N)
{
    return ((stop_x - start_x) * ((start_x + stop_x)/2));
}
double trapIntegral(double a, double start_x, double stop_x, int N)
{
    return 0.5*(stop_x - start_x)*(start_x + stop_x);
}
double simpIntegral(double a, double start_x, double stop_x, int N) {
    return (stop_x - start_x) / 6.0 * (start_x + 4.0 * 0.5 * (start_x + stop_x) + stop_x);
}
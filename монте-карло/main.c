#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>


#define MAX_ITER 10000

int main() {
    
    double x, y;
    double PI;
    double z = 1;
    int count = 0;

    for (int i = 1; i < MAX_ITER; i += 2)
    {
        PI += z * 4 / i;
        z *= -1;

        printf("%f\n", PI);
    }

    return 0;
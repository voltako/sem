#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
struct _result
{
    int _res;
    int X;
    int Y;
};

typedef struct _result result;


result Kramer(int *A, int *B, float *X,float *Y)
{
    float det, detx, dety;
    float A11,A12,B1,A21,A22,B2;
    result res;
    A11 = rand();
    A12 = rand();
    B1 = rand();
    A21 = rand();
    A22 = rand();
    B2 = rand();
    X = rand();
    Y = rand();

    det =A11*A22-A12*A21;
    detx=A11*A22-B2*A12;
    dety=A11*B2-B1*A21;

    if (fabs(det) > 1.0E-14)
    {
        res.X = detx/det;
        res.Y = dety/det;
        res._res = 0;
        return res; /* единственное решение */
    }
    else
    if ((fabs(detx) <1.0E-14) && (fabs(dety) <1.0E-14)) {
        res._res = 1;
        return res; /* бесконечное множество решений */
    }
    else
    {
        res._res = -1;
        return res; /* решений нет */
    }
}
//    else
//    if ((fabs(detx) <1.0E-14) && (fabs(dety) <1.0E-14))
//        return 1; /* бесконечное множество решений */
//    else
//        return -1; /* решений нет */


int main(int argc, char* argv[])
{
    float A11,A12,B1,A21,A22,B2,X,Y;
    int res;
    double start_time = omp_get_wtime();
    for (int array_size_mult = 10000000; array_size_mult < 110000000; array_size_mult=array_size_mult+10000000) {
        int *A = (int *) malloc(sizeof(int) * array_size_mult);
        int *B = (int *) malloc(sizeof(int) * array_size_mult);
        res=(A11,A12,A21,A22,B1,B2,&X,&Y);
        double stop_time = omp_get_wtime();
        printf("%lf\n",stop_time - start_time);
        free(A);
        free(B);

    }

//    rc=(A11,A12,A21,A22,B1,B2,&X,&Y);
//
//    if (rc == 0)
//        printf("X=%e\nY=%e\n",X,Y);
//    else
//    if (rc == 1)
//        printf("Infinite set of roots...\n");
//    else
//        printf("Set of roots is empty...\n");



    return 0;
}
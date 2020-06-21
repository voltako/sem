#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
    for (int n = 100; n < 1100; n=n+100)
    {
        volatile int i, j, k;
        i = 0;
        float *c;
        c = (float*) malloc(n * sizeof(float));
        for (float c = 0; c < 1 ; c++) {
            //printf("\nВедите размер матрицы: ");
            //scanf("%d",&n);
            for(i=1; i<=n; i++);{
                for(j=1; j<=(n+1); j++){
                    i = rand();
                    j = rand();
                }
            }

            
        }
        // float A[20][20], c, x[10]; -> malloc

        free(c);

//    printf("\nВедите размер матрицы: ");
//       scanf("%d", &n);
//    printf("\nВведите элементы матрицы:\n");
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= (n + 1); j++) {
                //printf(" A[%d][%d]:", i, j);
                //scanf("%f", &A[i][j]);
                // A[i][j] <- rand();
            }
        }

// TIME START
        double start_time = omp_get_wtime();
        for (j = 1; j <= n; j++) {
            for (i = 1; i <= n; i++) {
                if (i != j) {
                    //c = A[i][j] / A[j][j];
                    for (k = 1; k <= n + 1; k++) {
                        //A[i][k] = A[i][k] - c * A[j][k];
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            //x[i] = A[i][n + 1] / A[i][i];
        }
// TIME STOP
        double stop_time = omp_get_wtime();

        //printf("n = %d time = %lf\n", n, stop_time - start_time);
        printf("%lf\n",stop_time - start_time);

        // free time~!!! ))))
    }

    return 0;
}
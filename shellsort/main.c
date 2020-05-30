#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

double getShellSortTime(int n);
void ShellSort(int arr[], int n)
{
    int step, i, j, tmp;

    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
            for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
            {
                tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
            }
}

int main()
{
    for (int n = 100000; n <= 1000000; n+=100000)
    {
        printf("%d;%lf\n", n, getShellSortTime(n));
    }

    return 0;
}
double getShellSortTime(int n) {
    int *data;

    data = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        data[i] = rand();

    double start_time = omp_get_wtime();

    ShellSort(data,n);
    double stop_time = omp_get_wtime();

    free(data);

    return stop_time - start_time;
}
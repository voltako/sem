#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

double getInserationSortTime(int n);
void InserationSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] < temp)
                break;

            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
}

int main()
{
    for (int n = 10000; n <= 100000; n+=10000)
    {
        printf("%d;%lf\n", n, getInserationSortTime(n));
    }

    return 0;
}
double getInserationSortTime(int n) {
    int *data;

    data = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        data[i] = rand();

    double start_time = omp_get_wtime();

    InserationSort(data,n);
    double stop_time = omp_get_wtime();

    free(data);

    return stop_time - start_time;
}
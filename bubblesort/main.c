#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double getBubbleSortTime(int n);
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)


        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


int main() {
    for (int n = 50000; n <= 1000000; n+=50000)
    {
        printf("%d;%lf\n", n, getBubbleSortTime(n));
    }

    return 0;
}
double getBubbleSortTime(int n) {
    int *data;

    data = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        data[i] = rand();
    double start_time = omp_get_wtime();

    bubbleSort(data, n);
    double stop_time = omp_get_wtime();

    free(data);

    return stop_time - start_time;
}



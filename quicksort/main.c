#include<stdio.h>
#include <omp.h>
#include <stdlib.h>

double getQuickSortTime(int n);

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}


int main()
{
    for (int n = 100000; n <= 1000000; n+=100000)
    {
        printf("%d;%lf\n", n, getQuickSortTime(n));
    }

    return 0;
}
double getQuickSortTime(int n) {
    int *data;

    data = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        data[i] = rand();

    double start_time = omp_get_wtime();

    quickSort(data,0,n-1);
    double stop_time = omp_get_wtime();

    free(data);

    return stop_time - start_time;
}

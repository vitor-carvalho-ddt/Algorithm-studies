#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// NEXT YOUTUBE VIDEO

int partition(int *arr, int start, int end);
void swap(int *arr, int a, int b);
void quickSort(int *arr, int start, int end);
void fillArr(int *arr, int size);
void printArr(int *arr, int size);

int main()
{
    srand(time(NULL));
    int size = 20;
    int arr[size];


    fillArr(arr, size);
    printf("Array before Quicksort...\n");
    printArr(arr, size);
    
    quickSort(arr, 0, size-1);
    printf("Array after Quicksort...\n");
    printArr(arr, size);

    return 0;
}


void printArr(int *arr, int size)
{
    int i=0;
    for(;i<size-1;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}


void fillArr(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i] = rand()%size;
    }
}


int partition(int *arr, int start, int end)
{
    int pivot = end;
    int less_than = start;

    for(int i=start;i<pivot;i++)
    {
        if(arr[i]<arr[pivot])
        {
            swap(arr, i, less_than);
            less_than++;
        }
    }
    swap(arr, less_than, pivot);

    return less_than;
}


void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}


void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

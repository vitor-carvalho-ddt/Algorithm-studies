#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void swap(int arr[], int i, int j);
void bubbleSort(int arr[], int size);
int partitioningStart(int arr[], int start, int end);
void quickSortStart(int arr[], int start, int end);
int partitioningEnd(int arr[], int start, int end);
void quickSortEnd(int arr[], int start, int end);

int main()
{
    
    srand(time(NULL));
    
    int size = 30;
    
    int arr1[size];
    int arr2[size];
    int arr3[size];
    
    generateRandomArray(arr1, size);
    generateRandomArray(arr2, size);
    generateRandomArray(arr3, size);
    
    printf("ORIGINAL ARRAY 1: \n");
    printArray(arr1, size);
    bubbleSort(arr1, size);
    printf("SORTED ARRAY 1 (BUBBLE SORT): \n");
    printArray(arr1, size);
    printf("\n\n");
    
    
    printf("ORIGINAL ARRAY 2: \n");
    printArray(arr2, size);
    quickSortEnd(arr2, 0, size-1);
    printf("SORTED ARRAY 2 (QUICK SORT - PIVOT AT THE END): \n");
    printArray(arr2, size);
    printf("\n\n");
    
    
    printf("ORIGINAL ARRAY 3: \n");
    printArray(arr3, size);
    quickSortStart(arr3, 0, size-1);
    printf("SORTED ARRAY 3 (QUICK SORT - PIVOT AT THE START): \n");
    printArray(arr3, size);
    printf("\n\n");

    return 0;
}


void generateRandomArray(int arr[], int size)
{
    for(int i=0; i<size;i++)
    {
        arr[i] = rand() % size;
    }
}


void printArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        (i == 0)? printf("%d", arr[i]) : printf(" %d", arr[i]);
    }
    printf("\n");
}


void swap(int arr[], int i, int j)
{
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void bubbleSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-1-i;j++)
        {
            if(arr[j] > arr[j+1]) swap(arr, j, j+1);
        }
    }
}


int partitioningEnd(int arr[], int start, int end)
{
    int pivot = end;
    int less_than = start;
    
    for(int i=start; i<end; i++)
    {
        if((arr[i] < arr[pivot]) && (less_than != i))
        {
            swap(arr, less_than, i);
            less_than++;
        }
        else if(arr[i] < arr[pivot])
        {
            less_than++;
        }
    }
    swap(arr, less_than, pivot);
    
    return less_than;
}


void quickSortEnd(int arr[], int start, int end)
{
    int pivot = 0;
    
    if(start < end)
    {
        pivot = partitioningEnd(arr, start, end);
        quickSortEnd(arr, start, pivot - 1);
        quickSortEnd(arr, pivot + 1, end);
    }
}


int partitioningStart(int arr[], int start, int end)
{
    int pivot = start;
    int less_than = start+1;
    
    for(int i=start+1; i<=end; i++)
    {
        if((arr[i] < arr[pivot]) && (less_than != i))
        {
            swap(arr, less_than, i);
            less_than++;
        }
        else if(arr[i] < arr[pivot])
        {
            less_than++;
        }
    }
    
    less_than--;
    swap(arr, less_than, pivot);
    
    return less_than;
}


void quickSortStart(int arr[], int start, int end)
{
    int pivot = 0;
    
    if(start < end)
    {
        pivot = partitioningStart(arr, start, end);
        quickSortStart(arr, start, pivot - 1);
        quickSortStart(arr, pivot + 1, end);
    }
}
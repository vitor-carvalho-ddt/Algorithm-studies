#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int arr[], int size);
void swap(int arr[], int i, int j);
void bubbleSort(int arr[], int size);
int partitioning(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

int main()
{
    srand(time(NULL)); // INITIALIZING RANDOM NUMBERS
    int size = 10;
    int arr1[size];
    int arr2[size];
    for(int i=0;i<size;i++)
    {
        arr1[i] = rand() % size;
        arr2[i] = arr1[i];
    }
    
    printf("ORIGINAL ARRAY:\n");
    print_arr(arr1, size);
    
    bubbleSort(arr1, size);
    printf("SORTED ARRAY (BUBBLE SORT):\n");
    print_arr(arr1, size);
    
    quickSort(arr2, 0, size-1);
    printf("SORTED ARRAY (QUICK SORT):\n");
    print_arr(arr2, size);
}


void print_arr(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        (i == 0 ) ? printf("%d", arr[i]) : printf(" %d", arr[i]);
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
    for(int i=0;i<size-1;i++)
    {
        for (int j=0;j<size-1-i;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
            }
        }
    }
}


int partitioning(int arr[], int start, int end)
{
    int pivot = end;
    int less_than_ptr = start;
    if (start < end)
    {
        for(int i=start;i<end;i++)
        {
            if(arr[i] <= arr[pivot])
            {
                swap(arr, i, less_than_ptr);
                less_than_ptr++;
            }
        }
        swap(arr, less_than_ptr, pivot);
    }
    return less_than_ptr;
}


void quickSort(int arr[], int start, int end)
{
    int pivot = end;
    
    if(start < end)
    {
        pivot = partitioning(arr, start, pivot);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArr(int *arr, int size);
void fillArr(int *arr, int size);
void mergeSort(int *arr, int size);
void merge(int *arr, int size, int *left, int sizeLeft, int *right, int sizeRight);


int main()
{
    srand(time(NULL));
    int size = 20;
    int arr[size];
    fillArr(arr, size);
    
    printf("Array before Merge Sort...\n");
    printArr(arr, size);
    
    mergeSort(arr, size);
    printf("Array after Merge Sort....\n");
    printArr(arr, size);
    
    return 0;
}


void fillArr(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i] = rand()%size;
    }
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


void mergeSort(int *arr, int size)
{
    if(size <= 1) return;
    
    int mid = size/2;
    int left[mid];
    int right[size-mid];
    
    int j=0;
    int i=0;
    for(i;i<size;i++)
    {
        if(i < mid)
        {
            left[i] = arr[i];
        }
        else
        {
            right[j] = arr[i];
            j++;
        }
    }
    
    mergeSort(left, mid);
    mergeSort(right, size-mid);
    merge(arr, size, left, mid, right, size-mid);
}


void merge(int *arr, int size, int *left, int sizeLeft, int *right, int sizeRight)
{
    int i=sizeLeft-1;
    int j=sizeRight-1;
    int k=size-1;
    
    while(i>=0 && j>=0)
    {
        if(left[i] > right[j])
        {
            arr[k] = left[i];
            i--;
            k--;
        }
        else
        {
            arr[k] = right[j];
            j--;
            k--;
        }
    }
    while(i>=0)
    {
        arr[k] = left[i];
        i--;
        k--;
    }
    while(j>=0)
    {
        arr[k] = right[j];
        j--;
        k--;
    }
}

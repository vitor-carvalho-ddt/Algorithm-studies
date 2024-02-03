#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// REVIEWED

void fillArr(int *arr, int size);
void printArr(int *arr, int size);
void swap(int *arr, int a, int b);
void insertionSort(int *arr, int size);

int main()
{
    srand(time(NULL));
    int size = 20;
    int arr[size];

    fillArr(arr, size);
    printf("Array before Insertion Sort...\n");
    printArr(arr, size);
    
    insertionSort(arr, size);
    printf("Array after Insertion Sort...\n");
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
    for(i;i<size-1;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}


void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void insertionSort(int *arr, int size)
{
    if(size == 1) return;
    
    int temp = 0;
    int current = 1;
    
    while(current < size)
    {
        temp = arr[current];
        for(int i=current-1;i>=0;i--)
        {
            if(arr[i] > temp)
            {
                arr[i+1] = arr[i];
            }
            else
            {
                arr[i+1] = temp;
                current++;
                break;
            }
            if(i==0)
            {
                arr[0] = temp;
                current;
            }
        }
    }
}

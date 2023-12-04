#include <iostream>
#include <stdlib.h>
#include <time.h>

void fillArr(int *arr, int size);
void printArr(int *arr, int size);
void swap(int *arr, int a, int b);
void selectionSort(int *arr, int size);

int main()
{
    srand(time(NULL));
    int size = 20;
    int arr[size];

    fillArr(arr, size);
    std::cout << "Array before Selection Sort...\n";
    printArr(arr, size);
    
    selectionSort(arr, size);
    std::cout << "Array after Selection Sort...\n";
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
        std::cout << arr[i] << " ";
    }
    std::cout << arr[i] << "\n";
}


void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void selectionSort(int *arr, int size)
{
    int min = 0;
    for(int i=0;i<size-1;i++)
    {
        min = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr, min, i);
    }
}
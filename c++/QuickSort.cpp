#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ZERO 0 // THIS IS FOR DEBUGGING
#define ASC 1
#define DESC 0

void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void swap(int arr[], int i, int j);
int partitioningStart(int arr[], int start, int end, int direction);
void quickSortStart(int arr[], int start, int end, int direction);
int partitioningEnd(int arr[], int start, int end, int direction);
void quickSortEnd(int arr[], int start, int end, int direction);

int main()
{
    
    srand(time(NULL)); // INITIALIZING RANDOM NUMBER SEED
    
    int size = 30;
    
    int arr1[size];
    int arr2[size];
    
    generateRandomArray(arr1, size);
    generateRandomArray(arr2, size);
    

    std::cout << "ORIGINAL ARRAY 1:" << "\n";
    printArray(arr1, size);
    quickSortEnd(arr1, 0, size-1, ASC);
    std::cout << "SORTED ARRAY 1 (QUICK SORT - PIVOT AT THE END (ASCENDENT)):" << "\n";
    printArray(arr1, size);
    
    quickSortEnd(arr1, 0, size-1, DESC);
    std::cout << "SORTED ARRAY 1 (QUICK SORT - PIVOT AT THE END (DESCENDENT)):" << "\n";
    printArray(arr1, size);
    std::cout << "\n\n";
    
    
    std::cout << "ORIGINAL ARRAY 2:" << "\n";
    printArray(arr2, size);
    quickSortStart(arr2, 0, size-1, ASC);
    std::cout << "SORTED ARRAY 2 (QUICK SORT - PIVOT AT THE START (ASCENDENT)):" << "\n";
    printArray(arr2, size);
    
    quickSortStart(arr2, 0, size-1, DESC);
    std::cout << "SORTED ARRAY 2 (QUICK SORT - PIVOT AT THE START (DESCENDENT)):" << "\n";
    printArray(arr2, size);
    std::cout << "\n\n";
    
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
        (i == 0)? std::cout << arr[i] : std::cout << " " << arr[i];
    }
    std::cout << "\n";
}


void swap(int arr[], int i, int j)
{
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}


int partitioningEnd(int arr[], int start, int end, int direction)
{
    int pivot = end;
    int less_than = start;
    
    for(int i=start; i<end; i++)
    {
        switch(direction)
        {
            case 0:
            {
                if((arr[i] > arr[pivot]) && (less_than != i))
                {
                    swap(arr, less_than, i);
                    less_than++;
                }
                else if(arr[i] > arr[pivot])
                {
                    less_than++;
                }
                break;
            }
            case 1:
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
                break;
            }
        }
        
    }
    swap(arr, less_than, pivot);
    
    return less_than;
}


void quickSortEnd(int arr[], int start, int end, int direction)
{
    int pivot = 0;
    
    if(start < end)
    {
        pivot = partitioningEnd(arr, start, end, direction);
        quickSortEnd(arr, start, pivot - 1, direction);
        quickSortEnd(arr, pivot + 1, end, direction);
    }
}


int partitioningStart(int arr[], int start, int end, int direction)
{
    int pivot = start;
    int less_than = start+1;
    
    for(int i=start+1; i<=end; i++)
    {
        switch(direction)
        {
            case 0:
            {
                if((arr[i] > arr[pivot]) && (less_than != i))
                {
                    swap(arr, less_than, i);
                    less_than++;
                }
                else if(arr[i] > arr[pivot])
                {
                    less_than++;
                }
                break;
            }
            case 1:
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
                break;
            }
            
        }
        
    }
    
    less_than--;
    swap(arr, less_than, pivot);
    
    return less_than;
}


void quickSortStart(int arr[], int start, int end, int direction)
{
    int pivot = 0;
    
    if(start < end)
    {
        pivot = partitioningStart(arr, start, end, direction);
        quickSortStart(arr, start, pivot - 1, direction);
        quickSortStart(arr, pivot + 1, end, direction);
    }
}
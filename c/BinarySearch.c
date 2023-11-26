#include <stdio.h>

void fillArray(int arr[], int size);
int binarySearch(int arr[], int size, int value);

int main()
{
    int size = 50;
    int arr[size];
    fillArray(arr, size);
    
    int value = 27;
    int return_index = binarySearch(arr, size, value);
    
    if(return_index!=-1)
    {
        printf("The element %d has been found in the index: %d\n", value, return_index);
    }
    else
    {
        printf("The element %d has not been found in the array.\n", value);
    }

}


void fillArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i] = i+1;
    }
}


int binarySearch(int arr[], int size, int value)
{
    int low = 0;
    int high = size-1;
    int mid = 0;
    
    while(low <= high)
    {
        mid = low + (high - low)/2;
       
        if(arr[mid] == value)
        {
            return mid;
        }
        else if(arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
}
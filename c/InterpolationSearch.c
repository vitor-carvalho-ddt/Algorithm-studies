#include <stdio.h>
#include <stdlib.h>

// NEED TO MAKE YOUTUBE VIDEO

void fillArr(int *arr, int size);
void printArr(int *arr, int size);
int interpolationSearch(int *arr, int size, int value);

int main()
{
    int size = 20;
    
    int *arr = (int*) malloc(sizeof(int)*size);
    if(arr==NULL) return -1;
    
    int index = 0;
    int value = 180;
    
    fillArr(arr, size);
    printArr(arr, size);
    
    
    
    index = interpolationSearch(arr, size, value);
    (index != -1) ? printf("The value %d was found in the index %d", value, index) : printf("The value %d was not found in the array!", value);
    
    return 0;
}


void fillArr(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i] = (i+1)*10;
    }
}


void printArr(int *arr, int size)
{
    int i=0;
    for(i;i<size - 1;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}


int interpolationSearch(int *arr, int size, int value)
{
    int low = 0;
    int high = size-1;
    int probe = 0;
    
    while(value >= arr[low] && value <= arr[high] && low <= high)
    {
        probe = low + (((high - low) * (value - arr[low]))/ (arr[high] - arr[low]));
        printf("low + (((high - low) * (value - arr[low]))/ (arr[high] - arr[low]));\n");
        printf("%d  + (((%d - %d) * (%d - %d))/ (%d - %d));\n", low, high, low, value, arr[low], arr[high], arr[low]);
        printf("PROBE: %d\n", probe);
        if(arr[probe] == value)
        {
            return probe;
        }
        else if(arr[probe] < value)
        {
            low = probe + 1;
        }
        else
        {
            high = probe - 1;
        }
    }
    
    return -1;
}

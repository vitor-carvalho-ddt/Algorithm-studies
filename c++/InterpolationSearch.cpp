#include <iostream>
#include <stdlib.h>

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
    (index != -1) ? std::cout << "The value " << value << " was found in the index " << index << "\n" : std::cout << "The value " << value << " was not found in the array!";
    
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
        std::cout << " " << arr[i];
    }
    std::cout << arr[i] << "\n";
}


int interpolationSearch(int *arr, int size, int value)
{
    int low = 0;
    int high = size-1;
    int probe = 0;
    
    while(value >= arr[low] && value <= arr[high] && low <= high)
    {
        probe = low + (((high - low) * (value - arr[low]))/ (arr[high] - arr[low]));
        std::cout << "low + (((high - low) * (value - arr[low]))/ (arr[high] - arr[low]));\n";
        std::cout << " " << low << "  + (((" << high << " - " << low << ") * (" << value << " - " << arr[low] << "))/ (" << arr[high] << " - " << arr[low] << "));\n";
        std::cout << "PROBE: " << probe << "\n";
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
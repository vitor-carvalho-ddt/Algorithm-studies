#include <iostream>

int linearSearch(int arr[], int size, int value);

int main(int argc, char** argv[])
{
    int size = 10;
    int arr[] = {9, 34, 23, 1, 8, 56, 76, 2, 5, 11};
    
    int value = 76;
    int resulting_index = 0;
    resulting_index = linearSearch(arr, size, value);
    
    if(resulting_index != -1)
    {
        std::cout << "The value was found on index: " << resulting_index << "\n";
    }
    else
    {
        std::cout << "The value was not found in the array." << "\n";   
    }
    
    return 0;
}


int linearSearch(int arr[], int size, int value)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
    return -1;
}
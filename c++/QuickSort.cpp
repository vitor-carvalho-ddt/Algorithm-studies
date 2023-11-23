#include <iostream>

void printArray(int nums[], int size);
void swap(int nums[], int i, int j);
int partition(int nums[], int start, int end);
void quickSort(int nums[], int start, int end);

int main()
{
	int nums[] = { 10, 4, 6, 3, 9, 1, 8, 7, 5, 2 };
	int arr_size = sizeof(nums) / sizeof(nums[0]);
	std::cout << "Original array: " << "\n";
	printArray(nums, arr_size);

	quickSort(nums, 0, arr_size-1);
	std::cout << "Sorted array (quicksort): " << "\n";
	printArray(nums, arr_size);
}


void printArray(int nums[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
}


void swap(int nums[], int i, int j)
{
	int aux = nums[i];
	nums[i] = nums[j];
	nums[j] = aux;
}


int partition(int nums[], int start, int end)
{
	int pivot = end;
	int i = start;

	if (start < end)
	{
		for (int j = start; j < end; j++)
		{
			if (nums[j] <= nums[pivot])
			{
				swap(nums, i, j);
				i++;
			}
		}
		if (i != start)
		{
			swap(nums, i, pivot);
		}
	}
	return i;
}


void quickSort(int nums[], int start, int end)
{
	int pivot = end;

	if (start < end)
	{
		pivot = partition(nums, start, end);
		quickSort(nums, start, pivot - 1);
		quickSort(nums, pivot + 1, end);
	}
}
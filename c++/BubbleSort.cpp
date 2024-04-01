#include <iostream>

// ALREADY ON YOUTUBE IN C

void bubbleSort(int nums[], int size, bool asc);
void swap(int nums[], int i, int j);
void print_arr(int nums[], int size);

int main()
{
	int nums[] = { 7, 8, 4, 1, 9, 10, 2, 3, 5, 6 };
	int size = sizeof(nums) / sizeof(nums[0]);
	bool asc = 1;
	bool desc = 0;
	std::cout << "Original array: " << "\n";
	print_arr(nums, size);

	bubbleSort(nums, size, asc);
	std::cout << "Sorted array (ascendent): " << "\n";
	print_arr(nums, size);
	
	
	bubbleSort(nums, size, desc);
	std::cout << "Sorted array (descendent): " << "\n";
	print_arr(nums, size);

	return 0;
}

void print_arr(int nums[], int size)
{
	for (int i=0; i<size; i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
}

void bubbleSort(int nums[], int size, bool asc = 1)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			switch (asc)
			{
				case 0:
				{
					if (nums[j] < nums[j+1])
					{
						swap(nums, j, j+1);
					}
					break;
				}
				case 1:
				{
					if (nums[j] > nums[j+1])
					{
						swap(nums, j, j+1);
					}
					break;
				}
			}
			
		}
	}
}

void swap(int nums[], int i, int j)
{
	int aux = nums[i];
	nums[i] = nums[j];
	nums[j] = aux;
}

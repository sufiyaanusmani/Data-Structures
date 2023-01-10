#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

void getMinMax(int arr[], int start, int end, int &min, int &max)
{
	for (int i = start; i <= end; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
}

void findUnsortedArray(int arr[], int n)
{
	if (isSorted(arr, n))
	{
		cout << "Array is already sorted" << endl;
	}
	else
	{
		int index1, index2;

		// finding the lower index for sub array
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				index1 = i;
				break;
			}
		}

		// finding the upper index for sub array
		for (int i = n - 1; i > 0; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				index2 = i;
				break;
			}
		}

		int min, max;
		min = INT_MAX;
		max = INT_MIN;
		// find the max and min value inside sub array
		getMinMax(arr, index1, index2, min, max);

		// checking appropriate position for min value
		for (int i = 0; i < index1; i++)
		{
			if (min < arr[i])
			{
				// updating lower index if correct position is found
				index1 = i;
				break;
			}
		}

		// checking appropriate position for min value
		for (int i = index2 + 1; i < n; i++)
		{
			if (max > arr[i])
			{
				// updating upper index if correct position is found
				index2 = i;
				break;
			}
		}

		cout << "The sub array lies between " << index1 << " and " << index2 << endl;
		cout << "Minumum length of subarray: " << index2 - index1 + 1 << endl;
	}
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	int size;

	// unsorted array
	int arr1[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	size = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Array: ";
	print(arr1, size);
	findUnsortedArray(arr1, size);

	// unsorted array
	int arr2[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	size = sizeof(arr2) / sizeof(arr2[0]);
	cout << "\nArray: ";
	print(arr2, size);
	findUnsortedArray(arr2, size);

	// sorted array
	int arr3[] = {1, 5, 6, 7, 8, 8, 9};
	size = sizeof(arr3) / sizeof(arr3[0]);
	cout << "\nArray: ";
	print(arr3, size);
	findUnsortedArray(arr3, size);

	return 0;
}

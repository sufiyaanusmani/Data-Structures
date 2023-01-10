// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 3

#include <iostream>
using namespace std;

void sort(int *arr, int size)
{
	int temp;
	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size - 1 - pass; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void rearrange(int *arr, int size)
{
	int *num = new int[size];
	int minIndex = 0;
	int maxIndex = size - 1;
	bool storeMax = true;

	for (int i = 0; i < size; i++)
	{
		// using storeMax to toggle between storing max and min values
		if (storeMax == true)
		{
			num[i] = arr[maxIndex];
			maxIndex--;
			storeMax = false;
		}
		else
		{
			num[i] = arr[minIndex];
			minIndex++;
			storeMax = true;
		}
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = num[i];
	}

	// deallocating
	delete[] num;
}

int main()
{
	int size;
	cout << "Enter number of elements: ";
	cin >> size;

	int *arr = new int[size];

	// inputting values
	for (int i = 0; i < size; i++)
	{
		cout << "Enter value at index " << i << ": ";
		cin >> arr[i];
	}

	sort(arr, size); // array will be sorted in case unsorted array is used
	rearrange(arr, size);

	// Displaying values
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "   ";
	}

	// deallocating
	delete[] arr;
}

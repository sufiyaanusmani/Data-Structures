// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 4

#include <iostream>
#include <string>
using namespace std;

void combSort(int arr[], int size, int type)
{
	// if type == 0, then array will be sorted in ascending order
	// if type == 1, then array will be sorted in descending order
	int temp, gap;
	gap = size;
	bool isSwapped = true;

	while (gap != 1 || isSwapped == true)
	{
		gap = (int)(gap / 1.3);
		if (gap <= 1)
		{
			// when gap equals 1, this algorithm works like bubble sort
			gap = 1;
		}
		isSwapped = false;
		for (int i = 0; i < size - gap; i++)
		{
			// for ascending sort
			if (type == 0)
			{
				if (arr[i] > arr[i + gap])
				{
					temp = arr[i];
					arr[i] = arr[i + gap];
					arr[i + gap] = temp;
					isSwapped = true;
				}
			}
			else
			{
				// for descending sort
				if (arr[i] < arr[i + gap])
				{
					swap(arr[i], arr[i + gap]);
					isSwapped = true;
				}
			}
		}
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
	// Using flag to sort either ascending or descending
	// 0: ascending
	// 1: descending
	int size;

	int arr1[] = {20, 4, 6, 18, 10};
	size = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Before Sorting: ";
	print(arr1, size);

	combSort(arr1, size, 0);
	cout << "\nAfter Sorting (Ascending) : ";
	print(arr1, size);

	cout << "After Sorting (Descending): ";
	combSort(arr1, size, 1);
	print(arr1, size);

	return 0;
}

// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 3

#include <iostream>
using namespace std;

void sortInner(int *, int, int, int);
void sortOuter(int *arr, int size, int i)
{
	if (i >= size)
	{
		return;
	}
	else
	{
		sortInner(arr, size, i, 0);
	}
}

void sortInner(int *arr, int size, int i, int j)
{
	int temp;
	if (j >= size - 1 - i)
	{
		sortOuter(arr, size, i + 1);
	}
	else
	{
		if (arr[j] > arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
		sortInner(arr, size, i, j + 1);
	}
}

void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	int size;

	// Array 1
	int arr1[] = {12, 11, 13, 5, 6, 7};
	size = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Array 1 before sorting: ";
	print(arr1, size);
	cout << "Array 1 after sorting : ";
	sortOuter(arr1, size, 0);
	print(arr1, size);

	// Array 2
	int arr2[] = {8, 5, 45, 0, 1, 7, 70, 6};
	size = sizeof(arr2) / sizeof(arr2[0]);
	cout << "\nArray 2 before sorting: ";
	print(arr2, size);
	cout << "Array 2 after sorting : ";
	sortOuter(arr2, size, 0);
	print(arr2, size);

	return 0;
}

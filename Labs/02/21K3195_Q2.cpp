// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 2

#include <iostream>
using namespace std;

void sortAscending(int *arr, int size)
{
	int *ptr[10];
	int *temp;

	for (int i = 0; i < size; i++)
	{
		ptr[i] = &arr[i];
	}

	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size - 1 - pass; i++)
		{
			if (*ptr[i] > *ptr[i + 1])
			{
				temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << *ptr[i] << "   ";
	}
}

void sortDescending(int *arr, int size)
{
	int *ptr[10];
	int *temp;

	for (int i = 0; i < size; i++)
	{
		ptr[i] = &arr[i];
	}

	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size - 1 - pass; i++)
		{
			if (*ptr[i] < *ptr[i + 1])
			{
				temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << *ptr[i] << "   ";
	}
}

int main()
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter value at index " << i << ": ";
		cin >> arr[i];
	}

	cout << "\nOriginal Array: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "   ";
	}

	cout << "\nAscending : ";
	sortAscending(arr, 10);

	cout << "\nDescending: ";
	sortDescending(arr, 10);

	return 0;
}

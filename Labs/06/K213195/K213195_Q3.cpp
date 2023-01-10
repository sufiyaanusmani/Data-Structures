// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 3

#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
	int temp, i, j;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j > -1 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "   ";
	}
}

void input(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element at index " << i << ": ";
		cin >> arr[i];
	}
}

int main()
{
	int n;
	cout << "Enter size of array: ";
	cin >> n;

	int *arr = new int[n];

	input(arr, n);

	cout << "\nBEFORE SORTING: ";
	print(arr, n);

	insertionSort(arr, n);

	cout << "\nAFTER SORTING : ";
	print(arr, n);

	delete[] arr;
	return 0;
}

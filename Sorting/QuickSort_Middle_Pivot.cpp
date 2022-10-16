// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 2

#include <iostream>
using namespace std;

int partition(int arr[], int l, int h)
{
	int pIndex = (l + h) / 2; // using pivot as middle
	int pivot = arr[pIndex];
	int temp;
	int i = l;
	int j = h;

	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}

		while (arr[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	return i;
}

void quickSort(int arr[], int l, int h)
{
	int partitionIndex;
	if (l < h)
	{
		partitionIndex = partition(arr, l, h);
		quickSort(arr, l, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, h);
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

	// array 1
	int arr1[] = {5, 4, 3, 2, 1};
	cout << "Before Sorting: ";
	size = sizeof(arr1) / sizeof(arr1[0]);
	print(arr1, size);
	quickSort(arr1, 0, size - 1);
	cout << "After Sorting : ";
	print(arr1, size);

	cout << "\n----------------------------------\n";

	// array 2
	int arr2[] = {999, 612, 589, 856, 56, 945, 243};
	cout << "Before Sorting: ";
	size = sizeof(arr2) / sizeof(arr2[0]);
	print(arr2, size);
	quickSort(arr2, 0, size - 1);
	cout << "After Sorting : ";
	print(arr2, size);
	return 0;
}

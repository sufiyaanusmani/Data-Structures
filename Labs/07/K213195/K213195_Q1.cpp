// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 1

#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void merge(int arr[], int l, int m, int h, int max)
{
	int a = l;
	int b = m + 1;
	int c = l;

	while (a <= m && b <= h)
	{
		if ((arr[a] % max) <= (arr[b] % max))
		{
			arr[c] += ((arr[a] % max) * max);
			a++;
			c++;
		}
		else
		{
			arr[c] += ((arr[b] % max) * max);
			b++;
			c++;
		}
	}

	for (; a <= m; a++)
	{
		arr[c] += ((arr[a] % max) * max);
		c++;
	}

	for (; b <= h; b++)
	{
		arr[c] += ((arr[b] % max) * max);
		c++;
	}

	for (int i = l; i <= h; i++)
	{
		arr[i] /= max;
	}
}

void mergeSort(int arr[], int l, int h, int max)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		mergeSort(arr, l, mid, max);
		mergeSort(arr, mid + 1, h, max);
		merge(arr, l, mid, h, max);
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
	int size, max;

	// array 1
	int arr1[] = {5, 4, 3, 2, 1};
	cout << "Before Sorting: ";
	size = sizeof(arr1) / sizeof(arr1[0]);
	max = getMax(arr1, size) + 1;
	print(arr1, size);
	mergeSort(arr1, 0, size - 1, max);
	cout << "After Sorting: ";
	print(arr1, size);

	cout << "\n----------------------------------\n";

	// array 2
	int arr2[] = {999, 612, 589, 856, 56, 945, 243};
	cout << "Before Sorting: ";
	size = sizeof(arr2) / sizeof(arr2[0]);
	max = getMax(arr2, size) + 1;
	print(arr2, size);
	mergeSort(arr2, 0, size - 1, max);
	cout << "After Sorting: ";
	print(arr2, size);
	return 0;
}
// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 5

#include <iostream>
using namespace std;

int binarySearch(int arr[], int data, int left, int right, int &count)
{
	// count is used to record number of iterations
	bool found = false;
	int mid;
	while (left <= right)
	{
		count++;
		mid = left + (right - left) / 2;
		if (arr[mid] == data)
		{
			found = true;
			break;
		}
		else if (data > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (found == true)
	{
		return mid;
	}
	else
	{
		return -1;
	}
}

int interpolationSearch(int arr[], int size, int data, int &count)
{
	int l, h, index, temp;
	l = 0;
	h = size - 1;
	bool found = false;

	while (l <= h && data >= arr[l] && data <= arr[h])
	{
		count++;
		temp = (data - arr[l]) / (arr[h] - arr[l]);
		index = l + (h - l) * temp;

		if (arr[index] == data)
		{
			found = true;
			break;
		}

		if (data < arr[index])
		{
			h = index - 1;
		}
		else
		{
			l = index + 1;
		}
	}

	if (found == true)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

int main()
{
	// this program will first ask user for data to search
	// and will then print the index of that data
	// and will also tell number of iterations for each algorithm
	int data, index, size, count;
	int arr[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36};
	size = sizeof(arr) / sizeof(arr[0]);

	cout << "Enter data to search: ";
	cin >> data;

	cout << "----- Binary Search -----" << endl;
	count = 0;
	index = binarySearch(arr, data, 0, size - 1, count);
	if (index != -1)
	{
		cout << "Data found at index " << index << endl;
		cout << "Number of iterations: " << count << endl;
	}
	else
	{
		cout << "Data not found" << endl;
	}

	cout << "\n----- Interpolation Search -----" << endl;
	count = 0;
	index = interpolationSearch(arr, size, data, count);
	if (index != -1)
	{
		cout << "Data found at index " << index << endl;
		cout << "Number of iterations: " << count << endl;
	}
	else
	{
		cout << "Data not found" << endl;
	}
	return 0;
}

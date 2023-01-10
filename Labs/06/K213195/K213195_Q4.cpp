// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 4

#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int getMaxToys(int arr[], int n, int k)
{
	int count = 0;
	int total = 0;

	// first sorting the array
	sort(arr, n);

	for (int i = 0; i < n; i++)
	{
		if ((total + arr[i]) <= k) // checking first
		{
			// incrementing count only when total amount added is less than k
			total += arr[i];
			count++;
		}
		else
		{
			// this will only run when total exceeds the value of k
			// loop will break when value of total gets greter than k
			// which means you can not buy more toys
			break; // this is done to make program efficient
		}
	}
	return count;
}

int main()
{
	int n, k;

	int arr1[] = {1, 12, 5, 111, 200, 1000, 10};
	n = sizeof(arr1) / sizeof(arr1[0]);
	k = 50;
	cout << "You can buy a maximum of " << getMaxToys(arr1, n, k) << " toys" << endl;

	int arr2[] = {20, 30, 50};
	n = sizeof(arr2) / sizeof(arr2[0]);
	k = 100;
	cout << "\nYou can buy a maximum of " << getMaxToys(arr2, n, k) << " toys" << endl;
	return 0;
}

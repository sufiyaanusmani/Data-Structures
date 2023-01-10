// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 1

#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string arr[], int n)
{
	string temp;
	for (int i = 0; i < n - 1; i++)
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

void display(string arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	string arr[] = {"Fouzan", "Sufiyaan", "Qasim", "Yousuf", "Ahsan"};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "BEFORE SORTING: ";
	display(arr, size);

	bubbleSort(arr, size);

	cout << "\nAFTER SORTING : ";
	display(arr, size);
	return 0;
}

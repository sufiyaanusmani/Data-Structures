// Sufiyaan Usmani

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int data)
{
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 3;

        // if data exists at mid
        if (arr[mid] == data)
        {
            return mid;
        }

        if (data > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 7, 8, 10, 56, 88, 99, 102, 105, 109};
    int size = sizeof(arr) / sizeof(arr[0]);
    int data;
    cout << "Enter data to search: ";
    cin >> data;
    int index = binarySearch(arr, 0, size - 1, data);
    if (index != -1)
    {
        cout << "Data found at index " << index << endl;
    }
    else
    {
        cout << "Data not found" << endl;
    }
    return 0;
}
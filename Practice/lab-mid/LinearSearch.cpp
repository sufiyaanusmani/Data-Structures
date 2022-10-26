// Sufiyaan Usmani

#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int data)
{
    bool flag = false;
    int index;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            index = i;
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        cout << "Data found at index: " << index << endl;
    }
    else
    {
        cout << "Data not found" << endl;
    }
}

void binarySearch(int arr[], int l, int r, int data)
{
    int mid, index;
    bool found = false;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] == data)
        {
            found = true;
            index = mid;
            break;
        }

        if (data < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (found == true)
    {
        cout << "Data found at index: " << index << endl;
    }
    else
    {
        cout << "Data not found" << endl;
    }
}

void interpolationSearch(int arr[], int n, int data)
{
    int low = 0;
    int high = n - 1;
    bool flag = false;
    int index;
    while (low <= high && data >= arr[low] && data <= arr[high])
    {
        int q = (data - arr[low]) / (arr[high] - arr[low]);
        int pos = low + (high - low) * q;
        if (arr[pos] == data)
        {
            index = pos;
            flag = true;
            break;
        }
        if (data > arr[pos])
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    if (flag == true)
    {
        cout << "Data found at index: " << index << endl;
    }
    else
    {
        cout << "Data not found" << endl;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    linearSearch(arr, size, 8);
    binarySearch(arr, 0, size - 1, 8);
    interpolationSearch(arr, size, 8);
    return 0;
}
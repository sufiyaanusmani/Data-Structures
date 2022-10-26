// Sufiyaan Usmani

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int data)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int data)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == data)
        {
            return mid;
        }
        if (data > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int l, int r, int data)
{
    while (l <= r && data >= arr[l] && data <= arr[r])
    {
        int temp = (data - arr[l]) / (arr[r] - arr[l]);
        int pos = l + (r - l) * temp;
        if (arr[pos] == data)
        {
            return pos;
        }
        if (data > arr[pos])
        {
            l = pos + 1;
        }
        else
        {
            r = pos - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << linearSearch(arr, size, 6) << endl;
    cout << binarySearch(arr, 0, size - 1, 6) << endl;
    cout << interpolationSearch(arr, 0, size - 1, 6) << endl;
    return 0;
}
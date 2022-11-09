// Sufiyaan Usmani

#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == data)
        {
            cout << "Index: " << i << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

void binarySearch(int arr[], int l, int h, int data)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == data)
        {
            cout << "Index: " << mid << endl;
            return;
        }
        if (data < arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "Not found" << endl;
}

void interpolationSearch(int arr[], int l, int h, int data)
{
    while (l <= h && data >= arr[l] && data <= arr[h])
    {
        int q = (data - arr[l]) / (arr[h] - arr[l]);
        int pos = l + (h - l) * q;
        if (data == arr[pos])
        {
            cout << "Index: " << pos << endl;
            return;
        }
        if (data < arr[pos])
        {
            h = pos - 1;
        }
        else
        {
            l = pos + 1;
        }
    }
    cout << "Not found" << endl;
}

int main()
{
    int arr[] = {3, 6, 9, 12, 15, 18, 21, 24, 27};
    int size = sizeof(arr) / sizeof(arr[0]);
    linearSearch(arr, size, 12);
    binarySearch(arr, 0, size - 1, 12);
    interpolationSearch(arr, 0, size - 1, 12);
    return 0;
}
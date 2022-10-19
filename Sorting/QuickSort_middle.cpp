// Sufiyaan Usmani

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pIndex = high;
    int pivot = arr[pIndex]; // pivot
    int i = (low - 1);       // Index of smaller element and indicates
                             // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pIndex]);
    return (i + 1);
}

void sort(int arr[], int low, int high)
{
    if (low < high)
    {
        swap(arr[(low + high) / 2], arr[high]);
        int pIndex = partition(arr, low, high);
        sort(arr, low, pIndex - 1);
        sort(arr, pIndex + 1, high);
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
    int arr[] = {3, 2, 1, 7, 1, 8, 10, 2, 66, 3, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    print(arr, size);
    sort(arr, 0, size - 1);
    cout << "After sorting : ";
    print(arr, size);
    return 0;
}
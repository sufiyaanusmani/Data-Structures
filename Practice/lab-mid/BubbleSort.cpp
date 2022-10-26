// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int pass = 0; pass < n - 1; pass++)
    {
        for (int i = 0; i < n - 1 - pass; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
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
    sort(arr, size);
    cout << "After sorting : ";
    print(arr, size);
    return 0;
}
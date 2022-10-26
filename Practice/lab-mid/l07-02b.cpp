// Sufiyaan Usmani

#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int partition(int arr[], int l, int r)
{
    int pIndex = r;
    int pivot = arr[pIndex];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pIndex]);
    print(arr, 7);
    return (i + 1);
}

void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        cout << "Pivot: " << arr[(l + r) / 2] << endl;
        swap(arr[(l + r) / 2], arr[r]);
        int pIndex = partition(arr, l, r);
        sort(arr, l, pIndex - 1);
        sort(arr, pIndex + 1, r);
    }
}

int main()
{
    int arr[] = {999, 612, 589, 856, 56, 945, 243};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    print(arr, size);
    sort(arr, 0, size - 1);
    cout << "After sorting : ";
    print(arr, size);
    return 0;
}
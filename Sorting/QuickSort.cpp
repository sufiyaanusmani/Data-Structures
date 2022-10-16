// Sufiyaan Usmani

#include <iostream>
using namespace std;

int partition(int *arr, int l, int h)
{
    // two variables: i and j
    // i will look for greater elements
    // j will look for smaller elements
    int pIndex, pivot;
    // int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        pIndex = l;
        pivot = arr[l];
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void QuickSort(int *arr, int l, int h)
{
    int pIndex;
    if (l < h)
    {
        pIndex = partition(arr, l, h);
        QuickSort(arr, l, pIndex - 1);
        QuickSort(arr, pIndex + 1, h);
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int *arr1 = new int[n];

    cout << "Enter " << n << " integers in any order" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << endl
         << "Before Sorting: " << endl;
    print(arr1, n);

    cout << endl
         << endl
         << "SHELL SORT " << endl;

    QuickSort(arr1, 0, n - 1); // QUICK SORT CALLED HERE

    cout << endl
         << "After Sorting: " << endl;
    print(arr1, n);

    return 0;
}
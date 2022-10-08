// Sufiyaan Usmani

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[100];

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    for (; i <= m; i++)
    {
        temp[k] = arr[i];
        k++;
    }
    for (; j <= h; j++)
    {
        temp[k] = arr[j];
        k++;
    }

    for (int p = l; p <= h; p++)
    {
        arr[p] = temp[p];
    }
}

void MergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 5, 2, 3, 7, 8, 8, 0, 2, 34, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    MergeSort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}
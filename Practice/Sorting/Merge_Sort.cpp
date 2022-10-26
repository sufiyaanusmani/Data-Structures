#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    int size = right - left + 1;
    k = left;

    int *merged = new int[size];
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            merged[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            merged[k] = arr[j];
            j++;
            k++;
        }
    }
    for (; i <= mid; i++)
    {
        merged[k] = arr[i];
        k++;
    }
    for (; j <= right; j++)
    {
        merged[k] = arr[j];
        k++;
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = merged[i];
    }
    delete[] merged;
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "   " << arr[i];
    }
    cout << endl;
}

int main()
{
    int arr[6] = {3, 9, 8, 2, 5, 6};
    print(arr, 6);
    mergeSort(arr, 0, 5);
    print(arr, 6);
    return 0;
}
// Sufiyaan Usmani

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            swap(arr[i], arr[k]);
        }
    }
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int h)
{
    int size1 = m - l + 1;
    int size2 = h - m;
    int *left = new int[size1];
    int *right = new int[size2];

    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < size2; i++)
    {
        right[i] = arr[m + 1 + i];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < size1 && j < size2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = l + (h - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int partition(int arr[], int l, int h)
{
    int pIndex = h;
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pIndex]);
    return i + 1;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
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
    int arr[] = {1, 5, 2, 67, 2, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, size);
    // shellSort(arr, size);
    // mergeSort(arr, 0, size - 1);
    quickSort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}
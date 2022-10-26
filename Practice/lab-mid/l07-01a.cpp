// Sufiyaan Usmani

#include <iostream>
using namespace std;

void merge(int arr[], int size, int l, int m, int h)
{
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
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

void sort(int arr[], int size, int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        sort(arr, size, l, m);
        sort(arr, size, m + 1, h);
        merge(arr, size, l, m, h);
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
    sort(arr, size, 0, size - 1);
    cout << "After sorting : ";
    print(arr, size);
    return 0;
}
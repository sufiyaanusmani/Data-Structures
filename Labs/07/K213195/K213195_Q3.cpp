// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 3

#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp, int type)
{
    // if type == 0, then array will be sorted in ascending order
    // if type == 1, then array will be sorted in descending order
    int *temp = new int[n];
    int count[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    if (type == 0)
    {
        // sorting in ascending order
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
    }
    else
    {
        // sorting in descending order
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[n - 1 - i];
        }
    }
    delete[] temp;
}

void radixSort(int arr[], int n, int type)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp, type);
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
    // Using flag to sort either ascending or descending
    // 0: ascending
    // 1: descending
    int size;

    // array 1
    int arr1[] = {5, 4, 3, 2, 1};
    cout << "Before Sorting: ";
    size = sizeof(arr1) / sizeof(arr1[0]);
    print(arr1, size);
    radixSort(arr1, size, 0);
    cout << "After Sorting (Ascending) : ";
    print(arr1, size);

    int arr2[] = {5, 4, 3, 2, 1}; // using the same array, but this time sorting in descending order
    // although it is not necessary to make another array with the same values because array will still be sorted but i have shown it twice to make things clear
    size = sizeof(arr2) / sizeof(arr2[0]);
    radixSort(arr2, size, 1);
    cout << "After Sorting (Descending): ";
    print(arr2, size);

    cout << "\n----------------------------------\n\n";

    // array 2
    int arr3[] = {999, 612, 589, 856, 56, 945, 243};
    cout << "Before Sorting: ";
    size = sizeof(arr3) / sizeof(arr3[0]);
    print(arr3, size);
    radixSort(arr3, size, 0);
    cout << "After Sorting (Ascending) : ";
    print(arr3, size);

    int arr4[] = {999, 612, 589, 856, 56, 945, 243};
    size = sizeof(arr4) / sizeof(arr4[0]);
    radixSort(arr4, size, 1);
    cout << "After Sorting (Descending): ";
    print(arr4, size);

    return 0;
}

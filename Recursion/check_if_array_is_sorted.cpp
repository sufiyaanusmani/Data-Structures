// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if (size == 0)
    {
        return true;
    }
    if (arr[size] < arr[size - 1])
    {
        return false;
    }
    isSorted(arr, size - 1);
}

int main()
{
    int size;
    int arr1[] = {1, 2, 3, 4, 5, 60};
    size = sizeof(arr1) / sizeof(arr1[0]);
    cout << isSorted(arr1, size - 1) << endl;

    int arr2[] = {1, 277, 33, 4, 5, 60};
    size = sizeof(arr2) / sizeof(arr2[0]);
    cout << isSorted(arr2, size - 1) << endl;

    return 0;
}
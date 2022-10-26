// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0)
    {
        return true;
    }
    if (arr[size - 1] < arr[size - 2])
    {
        return false;
    }
    return isSorted(arr, size - 1);
}

int main()
{
    int arr[] = {1, 3, 5, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted(arr, size) << endl;
    return 0;
}
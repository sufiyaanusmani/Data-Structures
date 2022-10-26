// Sufiyaan Usmani
// Check if array is sorted

#include <iostream>
using namespace std;

bool sorted(int arr[], int size)
{
    // base case
    if (size == 0)
    {
        return true;
    }
    if (arr[size - 1] < arr[size - 2])
    {
        return false;
    }
    sorted(arr, size - 1);
}

int main()
{
    int arr[] = {2, 5, 10, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sorted(arr, size);
    return 0;
}
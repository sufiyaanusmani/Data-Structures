// Sufiyaan Usmani
// Sum of array

#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return arr[0] + sum(arr + 1, size - 1);
}

int main()
{
    int arr[] = {3, 2, 5, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sum(arr, size);
    return 0;
}
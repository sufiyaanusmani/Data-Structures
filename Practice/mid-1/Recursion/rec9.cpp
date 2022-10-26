// Sufiyaan Usmani
// largest element of array

#include <iostream>
using namespace std;

int largest(int arr[], int size)
{
    static int max = arr[0];
    if (size == 0)
    {
        return max;
    }
    if (arr[0] > max)
    {
        max = arr[0];
    }
    largest(arr + 1, size - 1);
}

int main()
{
    int arr[] = {4, 5, 7, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << largest(arr, size);
    return 0;
}
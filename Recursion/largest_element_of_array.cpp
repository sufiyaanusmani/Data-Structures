// Sufiyaan Usmani

#include <iostream>
using namespace std;

int largest(int *arr, int size, int i)
{
    static int max = arr[0];

    // base case
    if (i >= size)
    {
        return max;
    }

    if (arr[i] > max)
    {
        max = arr[i];
    }
    largest(arr, size, i + 1);
}

int main()
{
    int arr[] = {4, 3, 23, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << largest(arr, size, 0);
    return 0;
}
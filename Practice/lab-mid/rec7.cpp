// Sufiyaan Usmani

#include <iostream>
using namespace std;

int getMax(int arr[], int size)
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
    return getMax(arr + 1, size - 1);
}

int main()
{
    int arr[] = {4, 22, 6, 7, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << getMax(arr, size);
    return 0;
}
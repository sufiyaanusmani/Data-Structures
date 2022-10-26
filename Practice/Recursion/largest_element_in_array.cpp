// Sufiyaan Usmani

#include <iostream>
using namespace std;

int largest(int arr[], int l, int h)
{
    if (l == h)
    {
        return arr[l];
    }
    else
    {
        int max = largest(arr, l + 1, h);
        if (arr[l] > max)
        {
            return arr[l];
        }
        else
        {
            return max;
        }
    }
}

int main()
{
    int arr[] = {5, 2, 55, 22, 80, 34, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << largest(arr, 0, size - 1);
    return 0;
}
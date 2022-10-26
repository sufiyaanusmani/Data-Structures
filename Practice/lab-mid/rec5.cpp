// Sufiyaan Usmani

#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
    if (size < 0)
    {
        return 0;
    }
    return arr[size - 1] + sum(arr, size - 1);
}

int main()
{
    int arr[] = {2, 3, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sum(arr, size) << endl;
    return 0;
}
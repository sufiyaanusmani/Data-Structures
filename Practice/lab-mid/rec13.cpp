// Sufiyaan Usmani

#include <iostream>
using namespace std;

void outer(int[], int, int);
void inner(int arr[], int i, int j, int size)
{
    if (j >= size - 1 - i)
    {
        outer(arr, i + 1, size);
    }
    else
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
        inner(arr, i, j + 1, size);
    }
}

void outer(int arr[], int i, int size)
{
    if (i >= size - 1)
    {
        return;
    }
    inner(arr, i, 0, size);
}

int main()
{
    int arr[] = {2, 7, 3, 9, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    outer(arr, 0, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}
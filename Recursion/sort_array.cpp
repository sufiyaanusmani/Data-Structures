// Sufiyaan Usmani

#include <iostream>
using namespace std;

void loopJ(int *, int, int, int);
void sort(int *arr, int size, int i)
{
    if (i >= size)
    {
        return;
    }
    loopJ(arr, size, i, 0);
}

void loopJ(int *arr, int size, int i, int j)
{
    if (j >= size - 1 - i)
    {
        sort(arr, size, i + 1);
    }
    else
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
        loopJ(arr, size, i, j + 1);
    }
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 2, 0, 22, 3, 4, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    print(arr, size);
    sort(arr, size, 0);
    cout << "After sorting : ";
    print(arr, size);
    return 0;
}
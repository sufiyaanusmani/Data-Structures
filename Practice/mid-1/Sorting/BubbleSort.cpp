// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 5, 6, 32, 12, 2, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    sort(arr, size);
    print(arr, size);
    return 0;
}
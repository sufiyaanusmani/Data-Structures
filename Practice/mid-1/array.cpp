// Sufiyaan Usmani

#include <iostream>
using namespace std;

void remove(int arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                for (int k = j; k < size; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
            }
        }
    }
}

void rightShift(int arr[], int size, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = arr[size - 1];
        for (int j = size - 1; j >= 1; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

void leftShift(int arr[], int size, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

int main()
{
    int arr[] = {4, 2, 5, 3, 2, 4, 5, 7, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // remove(arr, size);
    // rightShift(arr, size, 3);
    leftShift(arr, size, 2);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}
// Sufiyaan Usmani

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int i = 0; i < size - 1 - pass; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
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
    int arr[] = {5, 3, 2, 6, 4, 2, 49, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    print(arr, size);
    return 0;
}
// Sufiyaan Usmani

#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j > -1 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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
    insertionSort(arr, size);
    print(arr, size);
    return 0;
}
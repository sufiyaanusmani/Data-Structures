// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
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
    int arr[] = {3, 5, 6, 32, 12, 2, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    sort(arr, size);
    print(arr, size);
    return 0;
}
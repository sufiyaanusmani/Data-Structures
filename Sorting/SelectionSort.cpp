// Sufiyaan Usmani

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size)
{
    int i, j, k;
    for (i = 0; i < size; i++)
    {
        k = i;
        for (j = i; j < size; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
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
    int arr[] = {4, 3, 6, 7, 8, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, size);
    print(arr, size);
    return 0;
}
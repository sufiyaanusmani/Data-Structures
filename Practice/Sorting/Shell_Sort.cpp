#include <iostream>
using namespace std;

void shellSort(int arr[], int size)
{
    int gap, i, j, temp;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = arr[i];
            for (j = i;)
        }
    }
}

void printArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, size);
    printArr(arr, size);
    return 0;
}
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    int round, j;
    for (round = 1; round < size; round++)
    {
        for (j = 0; j <= size - 1 - round; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "  " << arr[i];
    }
    cout << endl;
}

int main()
{
    int arr[] = {8, 1, 2, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}
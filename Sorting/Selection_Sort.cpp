#include <iostream>
using namespace std;

// 1. Select the smallest value in the list
// 2. Swap smallest value with the first value of the list
// 3. Again select the smallest value in the list (exclude the first value)
// 4. Swap this value with the second element of the list
// 5. Keep doing n-1 times to place all n values in the sorted order

void selectionSort(int arr[], int size)
{
    int i, j, k;

    for (i = 0; i < size - 1; i++)
    {
        k = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        if(i != k){
            swap(arr[i], arr[k]);
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
    int arr[] = {8, 6, 3, 10, 9, 4, 12, 5, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}
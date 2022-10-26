#include <iostream>
using namespace std;

void countSort(int *arr, int size)
{
    // 1. Find maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // 2. Make count array and set all its elements to 0
    int *count = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // 3. Count occurences of elements in arr
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    //
    int k = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            arr[k] = i;
            count[i]--;
            k++;
        }
    }

    delete[] count;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 5, 2, 6, 2, 9, 2, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    countSort(arr, size);
    print(arr, size);
    return 0;
}
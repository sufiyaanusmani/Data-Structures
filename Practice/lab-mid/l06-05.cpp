// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int temp, j;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 2, 1, 7, 1, 8, 10, 2, 66, 3, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    print(arr, size);
    sort(arr, size);
    cout << "After sorting : ";
    print(arr, size);
    return 0;
}
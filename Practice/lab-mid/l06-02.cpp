// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[minIndex], arr[i]);
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
    int arr[] = {2020, 2021, 2020, 2019, 2022, 2023, 2050, 2040};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    print(arr, size);
    return 0;
}
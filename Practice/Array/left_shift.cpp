// Sufiyaan Usmani

#include <iostream>
using namespace std;

void leftRotate(int *arr, int n, int k)
{
    int temp;
    for (int i = 0; i < k; i++)
    {
        temp = arr[0];
        for (int j = 0; j < n; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    leftRotate(arr, n, 3);
    print(arr, n);
    return 0;
}
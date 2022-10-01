// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int **arr, int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[row][j] > arr[row][j + 1])
                {
                    swap(arr[row][j], arr[row][j + 1]);
                }
            }
        }
    }
}

void print(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int **arr;
    int n;
    cin >> n;

    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    print(arr, n);
    sort(arr, n);
    print(arr, n);

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

// 3 5 6 2 3
// 56 43 23 1 2
// 5 33 2 1 3
// 3 4 5 6 7
// 8 66 4 3 0
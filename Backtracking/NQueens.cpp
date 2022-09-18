// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    // checking column
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    // checking diagnols
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int n, int row)
{
    if (row >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, row, col, n))
        {
            arr[row][col] = 1;

            if (nQueen(arr, n, row + 1))
            {
                return true;
            }
        }
        arr[row][col] = 0;
    }
    return false;
}

void print(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, n, 0))
    {
        print(arr, n);
    }
    else
    {
        cout << "Can not solve" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
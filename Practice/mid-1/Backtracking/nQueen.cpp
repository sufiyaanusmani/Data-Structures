// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
        {
            return false;
        }
    }

    int x = row;
    int y = col;

    while (x >= 0 && y >= 0)
    {
        if (arr[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    while (x >= 0 && y < n)
    {
        if (arr[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
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
        if (isSafe(arr, n, row, col))
        {
            arr[row][col] = 1;
            if (nQueen(arr, n, row + 1))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }

    return false;
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
}

int main()
{
    int n;
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

    return 0;
}
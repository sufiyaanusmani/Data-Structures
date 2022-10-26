// Sufiyaan Usmani

#include <iostream>
using namespace std;

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

bool isSafe(int **grid, int n, int row, int col)
{
    // col
    for (int i = 0; i < row; i++)
    {
        if (grid[i][col] == 1)
        {
            return false;
        }
    }

    int x = row;
    int y = col;
    while (x >= 0 && y >= 0)
    {
        if (grid[x][y] == 1)
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
        if (grid[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }

    return true;
}

void nQueen(int **grid, int n, int row)
{
    if (row >= n)
    {
        print(grid, n);
    }

    for (int col = 0; col < n; col++)
    {
        grid[row][col] = 1;
        if (isSafe(grid, n, row, col))
        {
            if (row + 1 < n)
            {
                nQueen(grid, n, row + 1);
            }
        }
        grid[row][col] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    int **grid = new int *[n];
    for (int i = 0; i < n; i++)
    {
        grid[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }

    nQueen(grid, n, 0);
    return 0;
}
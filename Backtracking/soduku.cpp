// Sufiyaan Usmani

#include <iostream>
#define N 9
using namespace std;

void print(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int grid[N][N], int x, int y, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[x][col] == num)
        {
            return false;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if (grid[row][y] == num)
        {
            return false;
        }
    }

    int startRow = x - x % 3,
        startCol = y - y % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                                   startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N], int x, int y)
{
    if (x == N - 1 && y == N)
    {
        return true;
    }

    if (y == N)
    {
        x++;
        y = 0;
    }

    if (grid[x][y] > 0)
        return solveSudoku(grid, x, y + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, x, y, num))
        {
            grid[x][y] = num;
            if (solveSudoku(grid, x, y + 1))
            {
                return true;
            }
            grid[x][y] = 0;
        }
    }
    return false;
}

int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;

    return 0;
}
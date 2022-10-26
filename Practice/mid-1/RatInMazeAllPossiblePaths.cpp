// Sufiyaan Usmani

#include <iostream>
using namespace std;

void print(int maze[5][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
}

bool isSafe(int maze[5][5], int n, int row, int col)
{
    if (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int maze[5][5], int n, int row, int col, int solArr[5][5])
{
    if (row == n - 1 && col == n - 1)
    {
        solArr[row][col] = 1;
        print(solArr, 5);
    }

    solArr[row][col] = 1;
    if (isSafe(maze, n, row, col))
    {
        if (row + 1 < n && solArr[row + 1][col] == 0)
        {
            solve(maze, n, row + 1, col, solArr);
        }
        if (col - 1 < n && solArr[row][col - 1] == 0)
        {
            solve(maze, n, row, col - 1, solArr);
        }
        if (col + 1 < n && solArr[row][col + 1] == 0)
        {
            solve(maze, n, row, col + 1, solArr);
        }
        if (row - 1 < n && solArr[row - 1][col] == 0)
        {
            solve(maze, n, row - 1, col, solArr);
        }
    }
    solArr[row][col] = 0;
}

int main()
{
    int n;
    int maze[5][5] = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 1, 1}};

    int solArr[5][5] = {0};

    solve(maze, 5, 0, 0, solArr);
    return 0;
}
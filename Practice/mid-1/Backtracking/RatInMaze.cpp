// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isSafe(int arr[5][5], int n, int row, int col, int solArr[5][5])
{
    if (row >= 0 && col >= 0 && row < n && col < n && arr[row][col] == 1 && solArr[row][col] == 0)
    {
        return true;
    }
    return false;
}

bool RatInMaze(int arr[5][5], int n, int row, int col, int solArr[5][5])
{
    if (row == n - 1 && col == n - 1)
    {
        solArr[row][col] = 1;
        return true;
    }

    if (isSafe(arr, n, row, col, solArr))
    {
        solArr[row][col] = 1;

        if (RatInMaze(arr, n, row + 1, col, solArr))
        {
            return true;
        }
        if (RatInMaze(arr, n, row, col - 1, solArr))
        {
            return true;
        }
        if (RatInMaze(arr, n, row, col + 1, solArr))
        {
            return true;
        }
        if (RatInMaze(arr, n, row - 1, col, solArr))
        {
            return true;
        }
        solArr[row][col] = 0;
        return false;
    }
    return false;
}

void print(int arr[5][5], int n)
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
    int arr[5][5] = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1}};

    int solArr[5][5] = {0};
    if (RatInMaze(arr, 5, 0, 0, solArr))
    {
        print(solArr, 5);
    }
    return 0;
}
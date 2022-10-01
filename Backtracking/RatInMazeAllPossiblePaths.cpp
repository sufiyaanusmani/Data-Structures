// Sufiyaan Usmani

#include <iostream>
using namespace std;

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
    cout << endl;
}

bool isSafe(int arr[5][5], int n, int row, int col)
{
    if (row >= 0 && col >= 0 && row < n && col < n && arr[row][col] == 1)
    {
        return true;
    }
    return false;
}

void RatInMaze(int arr[5][5], int n, int row, int col, int solArr[5][5], int &count)
{
    if (row == n - 1 && col == n - 1)
    {
        solArr[row][col] = 1;
        count++;
        print(solArr, 5);
    }

    solArr[row][col] = 1;
    if (isSafe(arr, n, row, col))
    {
        if (row + 1 < n && solArr[row + 1][col] == 0)
        {
            RatInMaze(arr, n, row + 1, col, solArr, count);
        }
        if (col - 1 >= 0 && solArr[row][col - 1] == 0)
        {
            RatInMaze(arr, n, row, col - 1, solArr, count);
        }
        if (col + 1 < n && solArr[row][col + 1] == 0)
        {
            RatInMaze(arr, n, row, col + 1, solArr, count);
        }
        if (row >= 0 && solArr[row - 1][col] == 0)
        {
            RatInMaze(arr, n, row - 1, col, solArr, count);
        }
    }
    solArr[row][col] = 0;
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
    int count = 0;
    RatInMaze(arr, 5, 0, 0, solArr, count);
    cout << count;

    return 0;
}
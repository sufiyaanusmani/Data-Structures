// Sufiyaan Usmani

#include <iostream>
#define n 5
using namespace std;

bool isSafe(int arr[n][n], int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

void ratInMaze(int arr[n][n], int x, int y, int solArr[n][n], int &count)
{
    if (x == n - 1 && y == n - 1 && arr[x][y] == 1)
    {
        solArr[x][y] = 1;
        count++;
        print(solArr);
    }

    solArr[x][y] = 1;
    if (isSafe(arr, x, y))
    {
        if (x + 1 < n && solArr[x + 1][y] == 0)
        {
            ratInMaze(arr, x + 1, y, solArr, count);
        }
        if (y - 1 < n && solArr[x][y - 1] == 0)
        {
            ratInMaze(arr, x, y - 1, solArr, count);
        }
        if (y + 1 < n && solArr[x][y + 1] == 0)
        {
            ratInMaze(arr, x, y + 1, solArr, count);
        }
        if (x - 1 < n && solArr[x - 1][y] == 0)
        {
            ratInMaze(arr, x - 1, y, solArr, count);
        }
    }
    solArr[x][y] = 0;
}

int solveAll(int arr[n][n], int N, int x, int y, int solArr[n][n])
{
    int count = 0;
    ratInMaze(arr, x, y, solArr, count);
    return count;
}

void print(int arr[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int arr[n][n] = {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1}};

    int solArr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    cout << "Count: " << solveAll(arr, n, 0, 0, solArr) << endl;
    return 0;
}
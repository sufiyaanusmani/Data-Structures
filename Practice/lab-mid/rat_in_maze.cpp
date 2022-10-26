// Sufiyaan Usmani

#include <iostream>
#define n 5
using namespace std;

bool isSafe(int arr[n][n], int N, int x, int y, int solArr[n][n])
{
    if ((x >= 0 && y >= 0) && (x < N && y < N) && arr[x][y] == 1 && solArr[x][y] == 0)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int arr[n][n], int N, int x, int y, int solArr[n][n])
{
    if (x == N - 1 && y == N - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, N, x, y, solArr))
    {
        solArr[x][y] = 1;
        if (ratInMaze(arr, N, x + 1, y, solArr))
        {
            return true;
        }
        if (ratInMaze(arr, N, x, y - 1, solArr))
        {
            return true;
        }
        if (ratInMaze(arr, N, x, y + 1, solArr))
        {
            return true;
        }
        if (ratInMaze(arr, N, x - 1, y, solArr))
        {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
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

    if (ratInMaze(arr, n, 0, 0, solArr))
    {
        print(solArr);
    }
    else
    {
        cout << "Can not solve" << endl;
    }
    return 0;
}
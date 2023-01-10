// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 5(a)

#include <iostream>
#define N 4
using namespace std;

bool isSafe(int arr[N][N], int x, int y, int n)
{
    if ((x < n) && (y < n) && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ratInMaze(int arr[N][N], int x, int y, int n, bool solutionArray[N][N], int &count)
{
    if (x == n - 1 && y == n - 1)
    {
        count++;
        return;
    }

    solutionArray[x][y] = 1;

    if (isSafe(arr, x, y, n))
    {
        if (x + 1 < n && solutionArray[x + 1][y] == 0)
        {
            ratInMaze(arr, x + 1, y, n, solutionArray, count);
        }

        if (y + 1 < n && solutionArray[x][y + 1] == 0)
        {
            ratInMaze(arr, x, y + 1, n, solutionArray, count);
        }
    }

    solutionArray[x][y] = 0;
}

int count(int arr[4][4], int n)
{

    // base case
    if (n == 0 || arr[0][0] == 0 ||
        arr[n - 1][n - 1] == 0)
    {
        return 0;
    }

    int count = 0;

    bool solutionArray[4][4];

    ratInMaze(arr, 0, 0, n, solutionArray, count);

    return count;
}

int main()
{
    int arr[N][N] =
        {
            {1, 1, 1, 1},
            {1, 0, 1, 1},
            {0, 1, 1, 1},
            {1, 1, 1, 1}};

    cout << "The total number of possible paths are " << count(arr, N);

    return 0;
}
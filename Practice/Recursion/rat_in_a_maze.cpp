// Sufiyaan Usmani

#include <iostream>
#define N 4
using namespace std;

bool isSafe(int newX, int newY, int arr[N][N], int n, bool visited[N][N])
{
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (arr[newX][newY] == 1) && (visited[newX][newY] != 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, int arr[N][N], int n, string &ans, bool visited[N][N], string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans = path;
        return;
    }

    // Down
    if (isSafe(x + 1, y, arr, n, visited))
    {
        visited[x][y] = true;
        solve(x + 1, y, arr, n, ans, visited, path + "D");
        visited[x][y] = false;
    }

    // Left
    if (isSafe(x, y - 1, arr, n, visited))
    {
        visited[x][y] = true;
        solve(x, y - 1, arr, n, ans, visited, path + "L");
        visited[x][y] = false;
    }

    // Right
    if (isSafe(x, y + 1, arr, n, visited))
    {
        visited[x][y] = true;
        solve(x, y + 1, arr, n, ans, visited, path + "R");
        visited[x][y] = false;
    }

    // Down
    if (isSafe(x - 1, y, arr, n, visited))
    {
        visited[x][y] = true;
        solve(x - 1, y, arr, n, ans, visited, path + "U");
        visited[x][y] = false;
    }
}

void searchMaze(int arr[N][N], int n)
{
    string ans;
    bool visited[N][N] = {false};
    string path = "";

    solve(0, 0, arr, n, ans, visited, path);
    cout << ans;
}

int main()
{
    int arr[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    searchMaze(arr, N);
    return 0;
}
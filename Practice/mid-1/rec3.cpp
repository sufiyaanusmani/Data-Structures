// Sufiyaan Usmani

#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

bool isSafe(int *arr, int n, int x)
{
    if (x >= 0 && x < n)
    {
        return true;
    }
    return false;
}

void solve(int *arr, int n, int x, int &count)
{
    // base case
    if (x == n - 1)
    {
        arr[x] = 1;
        count++;
        print(arr, n);
    }

    arr[x] = 1;
    if (isSafe(arr, n, x))
    {
        if (x + 1 < n && arr[x + 1] == 0)
        {
            solve(arr, n, x + 1, count);
        }
        if (x + 2 < n && arr[x + 2] == 0)
        {
            solve(arr, n, x + 2, count);
        }
        if (x + 4 < n && arr[x + 4] == 0)
        {
            solve(arr, n, x + 4, count);
        }
    }
    arr[x] = 0;
}

int main()
{
    int n;
    n = 10;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    int count = 0;
    solve(arr, n, 0, count);
    cout << "Number of possible paths: " << count << endl;
    return 0;
}
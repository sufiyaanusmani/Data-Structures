// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isSafe(char arr[5][5], int i, int j, int n)
{
    if (i >= 0 && j >= 0 && i < n && j < n && arr[i][j] == 'T')
    {
        return true;
    }
    return false;
}

void countTrees(char arr[5][5], int i, int j, int n, int &count)
{
    if (isSafe(arr, i, j, n))
    {
        count++;
        arr[i][j] = '*';
        countTrees(arr, i + 1, j, n, count);
        countTrees(arr, i - 1, j, n, count);
        countTrees(arr, i, j + 1, n, count);
        countTrees(arr, i, j - 1, n, count);
    }
}

int main()
{
    char arr[5][5] = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'T'}};

    int count = 0;
    int max = -1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 'T')
            {
                count = 0;
                countTrees(arr, i, j, 5, count);
                if (count > max)
                {
                    max = count;
                }
            }
        }
    }
    cout << max;
    return 0;
}
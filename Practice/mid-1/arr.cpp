// Sufiyaan Usmani

#include <iostream>
using namespace std;

int find(int arr[], int n)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && arr[i] < arr[i + 1])
        {
            index = i;
        }
        else if (i == n - 1 && arr[i] < arr[i - 1])
        {
            index = i;
        }
        else
        {
            if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1])
            {
                index = i;
            }
        }
    }
    return index;
}

int main()
{
    int arr[] = {23, 8, 15, 2, 3};
    cout << find(arr, 3);
    return 0;
}
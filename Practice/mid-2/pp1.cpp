// Sufiyaan Usmani

#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return ((n % 10) + sumOfDigits(n / 10));
}

void sort(int arr[], int n)
{
    int i, j, k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (sumOfDigits(arr[j]) < sumOfDigits(arr[k]))
            {
                k = j;
            }
        }
        if (i != k)
        {
            swap(arr[i], arr[k]);
        }
    }
}

int main()
{
    int arr[] = {291, 124, 39, 231, 473, 601, 101};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}
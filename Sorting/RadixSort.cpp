// Sufiyaan Usmani

#include <iostream>
using namespace std;

int getMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    delete[] output;
}

void radixSort(int *arr, int n)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value at index " << i << ": ";
        cin >> arr[i];
    }

    radixSort(arr, n);

    print(arr, n);

    delete[] arr;
    return 0;
}
// Sufiyaan Usmani

#include <iostream>
using namespace std;

void ShellSort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            int j;
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int *arr1 = new int[n];

    cout << "Enter " << n << " integers in any order" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << endl
         << "Before Sorting: " << endl;
    print(arr1, n);

    cout << endl
         << endl
         << "SHELL SORT " << endl;

    ShellSort(arr1, n); // SHELL SORT CALLED HERE

    cout << endl
         << "After Sorting: " << endl;
    print(arr1, n);

    return 0;
}

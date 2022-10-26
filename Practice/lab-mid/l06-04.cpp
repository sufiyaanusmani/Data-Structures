// Sufiyaan Usmani

#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j > -1 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int calculate(int arr[], int size, int amount)
{
    int total = 0, count = 0;
    for (int i = 0; i < size; i++)
    {
        if (total > amount)
        {
            break;
        }
        if (total + arr[i] <= amount)
        {
            total += arr[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {20, 30, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    print(arr, size);
    cout << "Toys: " << calculate(arr, size, 100) << endl;
    return 0;
}
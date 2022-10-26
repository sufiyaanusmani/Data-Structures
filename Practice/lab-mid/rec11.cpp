// Sufiyaan Usmani

#include <iostream>
using namespace std;

int search(int arr[], int size, int data)
{
    static int i = 0;
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == data)
    {
        return i;
    }
    i++;
    search(arr + 1, size - 1, data);
}

int main()
{
    int arr[] = {1, 4, 6, 78, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << search(arr, size, 78) << endl;
    return 0;
}
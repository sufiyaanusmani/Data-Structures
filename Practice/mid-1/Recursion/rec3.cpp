// Sufiyaan Usmani
// Linear Search

#include <iostream>
using namespace std;

bool search(int arr[], int size, int data)
{
    // base case
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == data)
    {
        return true;
    }
    search(arr + 1, size - 1, data);
}

int main()
{
    int arr[] = {4, 5, 32, 5, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << search(arr, size, 9) << endl;
    cout << search(arr, size, 7) << endl;
    return 0;
}
// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool search(int arr[], int size, int data)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == data)
    {
        return true;
    }
    return search(arr + 1, size - 1, data);
}

int main()
{
    int arr[] = {4, 3, 2, 5, 33, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int data;
    cout << "Enter data to search: ";
    cin >> data;
    if (search(arr, size, data))
    {
        cout << "Data found" << endl;
    }
    else
    {
        cout << "Data not found" << endl;
    }
    return 0;
}
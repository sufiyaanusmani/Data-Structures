// Sufiyaan Usmani

#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int data)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            found = true;
            cout << "Data found at index " << i << endl;
            break;
        }
    }
    if (found == false)
    {
        cout << "Data not found" << endl;
    }
}

int main()
{
    int arr[] = {4, 2, 7, 9, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int data;
    cout << "Enter data to search: ";
    cin >> data;
    linearSearch(arr, size, data);
    return 0;
}
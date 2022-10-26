// Sufiyaan Usmani

#include <iostream>
#include <string>
using namespace std;

void sort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    string name[] = {"sufiyaan", "ahsan", "qasim", "yousuf", "shahmir"};
    int size = sizeof(name) / sizeof(name[0]);
    sort(name, size);
    print(name, size);
    return 0;
}
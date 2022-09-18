// Sufiyaan Usmani

#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter number of rows: ";
    cin >> row;
    int **arr, *num;
    num = new int[row];
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        cout << "Enter number of columns in row " << i << ": ";
        cin >> num[i];
        arr[i] = new int[num[i]];
    }

    // inputting values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            cout << "Enter value at [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] num;
    return 0;
}
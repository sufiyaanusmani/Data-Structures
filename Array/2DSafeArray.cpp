// Sufiyaan Usmani

#include <iostream>
using namespace std;

class SafeArray
{
private:
    int row;
    int col;
    int **arr;

public:
    // Default Constructor
    SafeArray()
    {
        row = 0;
        col = 0;
        arr = NULL;
    }

    // Parameterized Constructor
    SafeArray(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
    }

    // Copy Constructor
    SafeArray(const SafeArray &obj)
    {
        this->row = obj.row;
        this->col = obj.col;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
    }

    // Copy Assignment Operator
    SafeArray &operator=(const SafeArray &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        arr = NULL;
        this->row = row;
        this->col = col;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[row];
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = obj.arr[i][j];
            }
        }
        return *this;
    }

    bool isSafe(int i, int j)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
        {
            cout << "Index out of range" << endl;
            return false;
        }
        return true;
    }

    void fillArray()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter value at [" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }

    void print()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int operator()(int i, int j)
    {
        if (isSafe(i, j))
        {
            return arr[i][j];
        }
        return -1;
    }

    // Destructor
    ~SafeArray()
    {
        if (arr != NULL)
        {
            for (int i = 0; i < row; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        arr = NULL;
    }
};

int main()
{
    SafeArray arr1(2, 3);
    arr1.fillArray();
    arr1.print();
    cout << arr1(1, 2);
    return 0;
}
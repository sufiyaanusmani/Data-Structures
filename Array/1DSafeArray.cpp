// Sufiyaan Usmani

#include <iostream>
using namespace std;

class SafeArray
{
private:
    int size;
    int *arr;

public:
    // Default Constructor
    SafeArray()
    {
        size = 0;
        arr = NULL;
    }

    // Parameterized Constructor
    SafeArray(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    // Copy Constructor
    SafeArray(const SafeArray &obj)
    {
        this->size = obj.size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    // Copy Assignment Operator
    SafeArray &operator=(const SafeArray &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        delete[] arr;
        arr = NULL;
        this->size = obj.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
        return *this;
    }

    // most important function that implements safe array
    bool isSafe(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range" << endl;
            return false;
        }
        return true;
    }

    // Access operator
    int operator[](int index)
    {
        if (isSafe(index))
        {
            return arr[index];
        }
        return -1;
    }

    void fillArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter value at index " << i << ": ";
            cin >> arr[i];
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "   ";
        }
        cout << endl;
    }

    // Destructor
    ~SafeArray()
    {
        delete[] arr;
        arr = NULL;
    }
};

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    SafeArray arr1(size);
    arr1.fillArray();
    arr1.print();
    cout << arr1[9];
    return 0;
}